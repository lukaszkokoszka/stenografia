#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QBitArray>
#include <QByteArray>
#include <QMessageBox>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QPainter>

#include <cctype>
#include <fstream>
#include <vector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->hide();

    QtCharts::QPieSeries *series = new QtCharts::QPieSeries();
    series->append("Free", 0);
    series->append("Used", 1);

    slice1 = series->slices().at(0);
    slice1->setBrush(Qt::green);

    slice2 = series->slices().at(1);
    slice2->setBrush(Qt::red);

    series->setPieEndAngle(360);

    QtCharts::QChart *chart = new QtCharts::QChart();
    chart->setMargins(QMargins(0, 0, 0, 0));
    chart->addSeries(series);
    chart->setTitle("Used space");
    chart->legend()->show();

    ui->chartview->setChart(chart);
    ui->chartview->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

QBitArray MainWindow::QStringToBitArray(QString &string)
{
    QBitArray array(string.length()*8);
    QByteArray bytes(string.toLocal8Bit());
    for(int i=0; i<bytes.count(); ++i) {
        for(int b=0; b<8;b++) {
            array.setBit( i*8+b, bytes.at(i)&(1<<(7-b)) );
        }
    }
    return array;
}

void MainWindow::loadImage(QLabel *label,QString fileName)
{
    QPixmap img(fileName);
    int w = ui->lImageOutput->width();
    int h = ui->lImageOutput->height();
    label->setPixmap(img.scaled(w, h, Qt::KeepAspectRatio));
}

void MainWindow::loadImage(QLabel *label, std::vector<uint8_t> &bytes)
{
    QPixmap img;
    img.loadFromData(bytes.data(), bytes.size()*8);
    int w = ui->lImageOutput->width();
    int h = ui->lImageOutput->height();
    label->setPixmap(img.scaled(w, h, Qt::KeepAspectRatio));
}

std::vector<uint8_t> MainWindow::MessageToVectorOfEightBits(QString &message, int r, int g, int b)
{
    QBitArray bits = QStringToBitArray(message);
    std::vector<uint8_t> vec;
    uint8_t num;
    int n = 0, i = 0;
    int a[3] = {r,g,b};

    while (n < bits.count()) {
        num = 0;
        int size = a[i++%3];
        if (size > (bits.count() - n)) {
            size = bits.count() - n;
        }
        for (int j = 0; j < size; ++j) {
            num <<= 1;
            num |= bits.at(n+j);

        }
        n += size;
        vec.push_back(num);
    }

    return vec;
}

void MainWindow::on_bLoadFileEncode_clicked()
{
    inputFileName = QFileDialog::getOpenFileName(this, "Load Image", NULL, "*.bmp");
    if (inputFileName.isEmpty()) {
        return;
    }
    std::ifstream input(inputFileName.toStdString(), std::ios::binary);
    if (input) {
        bytes = std::vector<uint8_t>(std::istreambuf_iterator<char>(input), {});
    }
    input.close();

    pixelArrayOffset = 0;
    imageSize = 0;
    for (int i = 0; i < 4; ++i) {
        pixelArrayOffset += (bytes[10+i] << (i*8));
        imageSize += (bytes[2+i] << (i*8));
    }
    imageSize -= pixelArrayOffset;

    loadImage(ui->lImageSource, inputFileName);
    calculateFreeSize();
    ui->label->show();
}

bool MainWindow::encodeMessage(QString &message, uint32_t startPos, std::vector<uint8_t> &bytes, int r, int g, int b)
{
    std::vector<uint8_t> a(MessageToVectorOfEightBits(message, r, g, b));
    unsigned long size = a.size();
    if ((avalibleSpace*8) < size) {
        QMessageBox msgBox;
        msgBox.setText("Out of space to encode message.");
        msgBox.exec();
        return false;
    }

    for (unsigned long i = 0; i < size; i+=3) {
        bytes[startPos+i+2] &= ((0xff) << b);
        bytes[startPos+i+1] &= ((0xff) << g);
        bytes[startPos+i+0] &= ((0xff) << r);

        if ((i+2) < size) bytes[startPos+i+2] |= a[i+2];
        if ((i+1) < size) bytes[startPos+i+1] |= a[i+1];
        if ((i+0) < size) bytes[startPos+i+0] |= a[i+0];
    }
    return true;
}

void MainWindow::on_bEncode_clicked()
{
    if (bytes.empty()) {
        QMessageBox msgBox;
        msgBox.setText("No image to encode.");
        msgBox.exec();
        return;
    }

    std::vector<uint8_t> tmp(bytes);
    QString text = ui->textEdit->toPlainText();

    uint8_t r = (uint8_t)ui->sRed->value();
    uint8_t g = (uint8_t)ui->sGreen->value();
    uint8_t b = (uint8_t)ui->sBlue->value();

    uint32_t size = text.size();

    tmp.at(pixelArrayOffset+0) = 13;
    tmp.at(pixelArrayOffset+1) = 13;
    tmp.at(pixelArrayOffset+2) = 13;
    tmp.at(pixelArrayOffset+3) = r;
    tmp.at(pixelArrayOffset+4) = g;
    tmp.at(pixelArrayOffset+5) = b;
    tmp.at(pixelArrayOffset+6) = (size & 0xff000000) >> 24;
    tmp.at(pixelArrayOffset+7) = (size & 0x00ff0000) >> 16;
    tmp.at(pixelArrayOffset+8) = (size & 0x0000ff00) >> 8;
    tmp.at(pixelArrayOffset+9) = (size & 0x000000ff);


    if (!encodeMessage(text, pixelArrayOffset+CHECKSUM_SIZE+1, tmp, r, g, b)) {
        return;
    }

    outputbytes = std::vector<uint8_t>(tmp);
    loadImage(ui->lImageOutput, outputbytes);
}

void MainWindow::saveImage(QString fileName, std::vector<uint8_t> &bytes)
{
    std::ofstream output(fileName.toStdString(), std::ios::binary);
    std::ostream_iterator<uint8_t> output_iterator(output);
    std::copy(bytes.begin(), bytes.end(), output_iterator);
    output.close();
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    if (!bytes.empty()) loadImage(ui->lImageSource, bytes);
    if (!outputbytes.empty()) loadImage(ui->lImageOutput, outputbytes);
}

void MainWindow::calculateFreeSize()
{
    if (imageSize > 0) {
        avalibleSpace =  imageSize / 24 * (ui->sRed->value() + ui->sGreen->value() + ui->sBlue->value());
        long long space = (((long long)avalibleSpace - ui->textEdit->toPlainText().length()));
        if (space > 0) ui->label->setText(QString("Avalible space: %1KiB").arg(space / 1024.0));
        else ui->label->setText(QString("Out of space!"));
    }
}

void MainWindow::on_sRed_valueChanged(int value)
{
    ui->lValueRed->setNum(value);
    calculateFreeSize();
}

void MainWindow::on_sGreen_valueChanged(int value)
{
    ui->lValueGreen->setNum(value);
    calculateFreeSize();
}

void MainWindow::on_sBlue_valueChanged(int value)
{
    ui->lValueBlue->setNum(value);
    calculateFreeSize();
}

uint8_t MainWindow::getBits(uint8_t byte, uint8_t numberOfBits, uint8_t positionFromRight)
{
    return (byte >> positionFromRight) & (0xff >> (8-numberOfBits));
}

QBitArray MainWindow::VectorToBitArray(std::vector<uint8_t> &vec, uint32_t length)
{
    QBitArray array(8*vec.size());
    for(unsigned long i=0; i < vec.size(); ++i) {
        for(int b=0; b<8;b++) {
            array.setBit( i*8+b, vec.at(i)&(1<<(7-b)) );
        }
    }
    return array;
}

QByteArray bitsToBytes(std::vector<bool> bits) {
    QByteArray bytes;
    uint8_t c = 0;
    for (unsigned long j = 0; j < (bits.size()/8); ++j) {
        c = 0;
        for (int i = 0; i < 8; ++i) {
            c <<= 1;
            c |= bits.at(j*8+i);
        }
        bytes.push_back(c);
    }

    return bytes;
}


QString MainWindow::decodeMessage(std::vector<uint8_t> &vec, uint32_t length, uint8_t r, uint8_t g, uint8_t b)
{
    QByteArray _byteArray;
    uint32_t offset = pixelArrayOffset+CHECKSUM_SIZE+1;
    uint8_t a[3] = {r,g,b};
    unsigned long i = 0;

    unsigned long size = 0;
    long long n = length*8;
    while (n > 0) {
        n -= a[size++%3];
    }

    for (unsigned long byte = 0; byte < size; ++byte) {
        uint8_t c = 0;
        c = getBits(vec.at(offset+byte), a[i++%3], 0);
        _byteArray.push_back(c);
    }

    std::vector<bool> _bitArray;
    i = 0;
    unsigned long k = 1;

    foreach (uint8_t byte, _byteArray) {
        size = a[i++%3] - 1;
        QBitArray bits(8, false);
        for(int b = 0; b < 8; b++) {
            bits.setBit( b, byte & (1 << (7 - b)) );
        }

        if (k == (unsigned long)_byteArray.size()) {
        if (((_bitArray.size() % 7)) < size) {
            size = size - ((_bitArray.size() % 8));
        }
        }

        for (int j = size; j >= 0; j--) {
            _bitArray.push_back(bits.at(7-j));
        }
        k++;
    }



    QString decodedMessage(bitsToBytes(_bitArray));

    return decodedMessage;
}

void MainWindow::on_bDecode_clicked()
{
    if (outputbytes.empty()) return;
    std::vector<uint8_t> tmp(outputbytes);
    QString decodedString;
    uint32_t length = 0;



    if ((tmp.at(pixelArrayOffset+0) & tmp.at(pixelArrayOffset+1) & tmp.at(pixelArrayOffset+2)) == 13) {
        uint8_t r = tmp.at(pixelArrayOffset+3);
        uint8_t g = tmp.at(pixelArrayOffset+4);
        uint8_t b = tmp.at(pixelArrayOffset+5);
        length |= (tmp.at(pixelArrayOffset+6)) << 24;
        length |= (tmp.at(pixelArrayOffset+7)) << 16;
        length |= (tmp.at(pixelArrayOffset+8)) << 8;
        length |= (tmp.at(pixelArrayOffset+9));

        slice1->setValue(imageSize);
        slice2->setValue(length);
        ui->chartview->show();
        decodedString = decodeMessage(tmp, length, r, g, b);
        ui->textEdit->setText(decodedString);
    } else {
        QMessageBox msgBox;
        msgBox.setText("Image don't have encoded message.");
        msgBox.exec();
    }

}

void MainWindow::on_bLoadFileDecode_clicked()
{
    outputFileName = QFileDialog::getOpenFileName(this, "Load Image", NULL, "*.bmp");
    if (outputFileName.isEmpty()) return;
    std::ifstream fin(outputFileName.toStdString(), std::ios::binary);
    if (fin) {
        outputbytes = std::vector<uint8_t>(std::istreambuf_iterator<char>(fin), {});
    }
    fin.close();
    loadImage(ui->lImageOutput, outputbytes);

    pixelArrayOffset = 0;
    imageSize = 0;
    for (int i = 0; i < 4; ++i) {
        pixelArrayOffset += (outputbytes[10+i] << (i*8));
        imageSize += (outputbytes[2+i] << (i*8));
    }
    imageSize -= pixelArrayOffset;

    ui->chartview->show();
    slice1->setValue(imageSize);
}

void MainWindow::on_bSaveFileDecoded_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save Image", NULL, "*.bmp");
    if (filename.isEmpty()) return;
    std::fstream fout(filename.toStdString(), std::ios::out | std::ios::binary);
    fout.write((char*)&outputbytes[0], outputbytes.size() * sizeof(uint8_t));
    fout.close();
}

void MainWindow::on_bLoadMessageEncode_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Load File", NULL, "*.txt");
    if (filename.isEmpty()) return;
    std::fstream fin(filename.toStdString(), std::ios::in);
    std::string str((std::istreambuf_iterator<char>(fin)),
                     std::istreambuf_iterator<char>());
    fin.close();
    ui->textEdit->setText(QString::fromStdString(str));
}

void MainWindow::on_bSaveMessageDecoded_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save Image", NULL, "*.txt");
    if (filename.isEmpty()) return;
    std::fstream fout(filename.toStdString(), std::ios::out | std::ios::binary);
    fout << ui->textEdit->toPlainText().toStdString();
    fout.close();
}

void MainWindow::on_textEdit_textChanged()
{
    calculateFreeSize();
}
