#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QtCharts/QPieSlice>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_bLoadFileEncode_clicked();

    void on_bEncode_clicked();

    void on_sRed_valueChanged(int value);

    void on_sGreen_valueChanged(int value);

    void on_sBlue_valueChanged(int value);

    void on_bDecode_clicked();

    void on_bLoadFileDecode_clicked();

    void on_bSaveFileDecoded_clicked();

    void on_bLoadMessageEncode_clicked();

    void on_bSaveMessageDecoded_clicked();

    void on_textEdit_textChanged();

private:
    const int CHECKSUM_SIZE = 10;
    Ui::MainWindow *ui;
    uint32_t imageSize = 0;
    uint32_t pixelArrayOffset = 0;
    uint32_t avalibleSpace;
    std::vector<uint8_t> bytes;
    std::vector<uint8_t> outputbytes;
    QString inputFileName;
    QString outputFileName;
    QtCharts::QPieSlice *slice1;
    QtCharts::QPieSlice *slice2;

    void loadImage(QLabel *label, QString fileName);
    void loadImage(QLabel *label, std::vector<uint8_t> &bytes);
    void saveImage(QString fileName, std::vector<uint8_t> &bytes);
    bool encodeMessage(QString &message, uint32_t startPos, std::vector<uint8_t> &bytes, int r, int g, int b);
    void calculateFreeSize();
    uint8_t getBits(uint8_t byte, uint8_t numberOfBits, uint8_t position);
    QBitArray QStringToBitArray(QString &string);
    QBitArray VectorToBitArray(std::vector<uint8_t> &vec, uint32_t length);
    std::vector<uint8_t> MessageToVectorOfEightBits(QString &message, int r, int g, int b);
    QString decodeMessage(std::vector<uint8_t> &vec, uint32_t length, uint8_t r, uint8_t g, uint8_t b);


protected:
    void resizeEvent(QResizeEvent *event) override;
};
#endif // MAINWINDOW_H
