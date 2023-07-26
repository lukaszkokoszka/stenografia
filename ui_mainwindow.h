/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCharts/QChartView>
#include <QtCharts/chartsnamespace.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lImageSource;
    QVBoxLayout *verticalLayout_2;
    QPushButton *bEncode;
    QPushButton *bDecode;
    QLabel *lImageOutput;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout_3;
    QPushButton *bSaveFileDecoded;
    QPushButton *bSaveMessageDecoded;
    QPushButton *bLoadMessageEncode;
    QPushButton *bLoadFileDecode;
    QPushButton *bLoadFileEncode;
    QTextEdit *textEdit;
    QtCharts::QChartView *chartview;
    QLabel *label;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QSlider *sRed;
    QLabel *lValueRed;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QSlider *sGreen;
    QLabel *lValueGreen;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QSlider *sBlue;
    QLabel *lValueBlue;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setMinimumSize(QSize(800, 558));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        lImageSource = new QLabel(centralwidget);
        lImageSource->setObjectName(QString::fromUtf8("lImageSource"));
        lImageSource->setFrameShape(QFrame::Box);
        lImageSource->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lImageSource);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetNoConstraint);
        bEncode = new QPushButton(centralwidget);
        bEncode->setObjectName(QString::fromUtf8("bEncode"));

        verticalLayout_2->addWidget(bEncode);

        bDecode = new QPushButton(centralwidget);
        bDecode->setObjectName(QString::fromUtf8("bDecode"));

        verticalLayout_2->addWidget(bDecode);


        horizontalLayout->addLayout(verticalLayout_2);

        lImageOutput = new QLabel(centralwidget);
        lImageOutput->setObjectName(QString::fromUtf8("lImageOutput"));
        lImageOutput->setFrameShape(QFrame::Box);
        lImageOutput->setFrameShadow(QFrame::Plain);
        lImageOutput->setLineWidth(1);
        lImageOutput->setMidLineWidth(0);
        lImageOutput->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lImageOutput);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetMaximumSize);
        gridLayout_3->setContentsMargins(-1, -1, 0, -1);
        bSaveFileDecoded = new QPushButton(centralwidget);
        bSaveFileDecoded->setObjectName(QString::fromUtf8("bSaveFileDecoded"));

        gridLayout_3->addWidget(bSaveFileDecoded, 4, 0, 1, 1);

        bSaveMessageDecoded = new QPushButton(centralwidget);
        bSaveMessageDecoded->setObjectName(QString::fromUtf8("bSaveMessageDecoded"));

        gridLayout_3->addWidget(bSaveMessageDecoded, 6, 0, 1, 1);

        bLoadMessageEncode = new QPushButton(centralwidget);
        bLoadMessageEncode->setObjectName(QString::fromUtf8("bLoadMessageEncode"));

        gridLayout_3->addWidget(bLoadMessageEncode, 5, 0, 1, 1);

        bLoadFileDecode = new QPushButton(centralwidget);
        bLoadFileDecode->setObjectName(QString::fromUtf8("bLoadFileDecode"));

        gridLayout_3->addWidget(bLoadFileDecode, 1, 0, 1, 1);

        bLoadFileEncode = new QPushButton(centralwidget);
        bLoadFileEncode->setObjectName(QString::fromUtf8("bLoadFileEncode"));
        bLoadFileEncode->setMinimumSize(QSize(143, 23));

        gridLayout_3->addWidget(bLoadFileEncode, 0, 0, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_3);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        horizontalLayout_2->addWidget(textEdit);

        chartview = new QtCharts::QChartView(centralwidget);
        chartview->setObjectName(QString::fromUtf8("chartview"));

        horizontalLayout_2->addWidget(chartview);

        horizontalLayout_2->setStretch(1, 4);
        horizontalLayout_2->setStretch(2, 2);

        verticalLayout->addLayout(horizontalLayout_2);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, -1, 0, -1);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setMinimumSize(QSize(37, 0));

        horizontalLayout_4->addWidget(label_3);

        sRed = new QSlider(centralwidget);
        sRed->setObjectName(QString::fromUtf8("sRed"));
        sRed->setMinimum(1);
        sRed->setMaximum(8);
        sRed->setPageStep(8);
        sRed->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(sRed);

        lValueRed = new QLabel(centralwidget);
        lValueRed->setObjectName(QString::fromUtf8("lValueRed"));

        horizontalLayout_4->addWidget(lValueRed);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(37, 0));

        horizontalLayout_5->addWidget(label_4);

        sGreen = new QSlider(centralwidget);
        sGreen->setObjectName(QString::fromUtf8("sGreen"));
        sGreen->setMinimum(1);
        sGreen->setMaximum(8);
        sGreen->setPageStep(8);
        sGreen->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(sGreen);

        lValueGreen = new QLabel(centralwidget);
        lValueGreen->setObjectName(QString::fromUtf8("lValueGreen"));

        horizontalLayout_5->addWidget(lValueGreen);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setEnabled(true);
        label_5->setMinimumSize(QSize(37, 0));

        horizontalLayout_6->addWidget(label_5);

        sBlue = new QSlider(centralwidget);
        sBlue->setObjectName(QString::fromUtf8("sBlue"));
        sBlue->setMinimum(1);
        sBlue->setMaximum(8);
        sBlue->setPageStep(8);
        sBlue->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(sBlue);

        lValueBlue = new QLabel(centralwidget);
        lValueBlue->setObjectName(QString::fromUtf8("lValueBlue"));

        horizontalLayout_6->addWidget(lValueBlue);


        verticalLayout->addLayout(horizontalLayout_6);

        verticalLayout->setStretch(0, 1);

        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Steganografia", nullptr));
        lImageSource->setText(QString());
        bEncode->setText(QCoreApplication::translate("MainWindow", "Encode ->", nullptr));
        bDecode->setText(QCoreApplication::translate("MainWindow", "<- Decode", nullptr));
        lImageOutput->setText(QString());
        bSaveFileDecoded->setText(QCoreApplication::translate("MainWindow", "Save Decoded Image", nullptr));
        bSaveMessageDecoded->setText(QCoreApplication::translate("MainWindow", "Save Decoded Message", nullptr));
        bLoadMessageEncode->setText(QCoreApplication::translate("MainWindow", "Load Message to Encode", nullptr));
        bLoadFileDecode->setText(QCoreApplication::translate("MainWindow", "Load Image to Decode", nullptr));
        bLoadFileEncode->setText(QCoreApplication::translate("MainWindow", "Load Image to Encode", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Avalible space: 0KiB", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Red", nullptr));
        lValueRed->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Green", nullptr));
        lValueGreen->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Blue", nullptr));
        lValueBlue->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
