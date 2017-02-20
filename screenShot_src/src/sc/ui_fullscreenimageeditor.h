/********************************************************************************
** Form generated from reading UI file 'fullscreenimageeditor.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FULLSCREENIMAGEEDITOR_H
#define UI_FULLSCREENIMAGEEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FullScreenImageEditor
{
public:
    QWidget *centerWidget;
    QWidget *cmdPanel;
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *mosaicButton;
    QPushButton *rectButton;
    QPushButton *ovalButton;
    QPushButton *arrowButton;
    QPushButton *penButton;
    QPushButton *undoButton;
    QPushButton *sizeButtonSmall;
    QPushButton *sizeButtonNormal;
    QPushButton *sizeButtonLarge;
    QPushButton *colorButton;
    QPushButton *saveButton;
    QPushButton *okButton;
    QWidget *colorPanel;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *colorButton1;
    QPushButton *colorButton2;
    QPushButton *colorButton3;
    QPushButton *colorButton4;
    QPushButton *colorButton5;
    QPushButton *saveButton_4;
    QPushButton *saveButton_3;
    QPushButton *saveButton_5;
    QPushButton *saveButton_7;
    QPushButton *saveButton_6;
    QPushButton *saveButton_8;
    QPushButton *saveButton_2;

    void setupUi(QMainWindow *FullScreenImageEditor)
    {
        if (FullScreenImageEditor->objectName().isEmpty())
            FullScreenImageEditor->setObjectName(QStringLiteral("FullScreenImageEditor"));
        FullScreenImageEditor->resize(800, 600);
        FullScreenImageEditor->setMouseTracking(true);
        FullScreenImageEditor->setAutoFillBackground(false);
        centerWidget = new QWidget(FullScreenImageEditor);
        centerWidget->setObjectName(QStringLiteral("centerWidget"));
        centerWidget->setMouseTracking(true);
        cmdPanel = new QWidget(centerWidget);
        cmdPanel->setObjectName(QStringLiteral("cmdPanel"));
        cmdPanel->setGeometry(QRect(150, 120, 402, 101));
        verticalLayout = new QVBoxLayout(cmdPanel);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(cmdPanel);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        widget_2->setPalette(palette);
        widget_2->setAutoFillBackground(false);
        widget_2->setStyleSheet(QLatin1String("border:1px groove gray;\n"
"border-radius:3px;\n"
"padding:2px 4px;\n"
"background:#000000"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        mosaicButton = new QPushButton(widget_2);
        mosaicButton->setObjectName(QStringLiteral("mosaicButton"));
        mosaicButton->setMinimumSize(QSize(30, 30));
        mosaicButton->setMaximumSize(QSize(30, 30));
		mosaicButton->setToolTip(QStringLiteral("mosaic"));
		mosaicButton->setStyleSheet("QPushButton{border-image: url(./res/btn_mosaic.png);}");
        horizontalLayout->addWidget(mosaicButton);


        rectButton = new QPushButton(widget_2);
        rectButton->setObjectName(QStringLiteral("rectButton"));
        rectButton->setMinimumSize(QSize(30, 30));
        rectButton->setMaximumSize(QSize(30, 30));
		rectButton->setToolTip(QStringLiteral("rect"));
		rectButton->setStyleSheet("QPushButton{border-image: url(./res/btn_rect.png);}");

        horizontalLayout->addWidget(rectButton);

        ovalButton = new QPushButton(widget_2);
        ovalButton->setObjectName(QStringLiteral("ovalButton"));
        ovalButton->setMinimumSize(QSize(30, 30));
        ovalButton->setMaximumSize(QSize(30, 30));
		ovalButton->setToolTip(QStringLiteral("oval"));
        ovalButton->setStyleSheet("QPushButton{border-image: url(./res/btn_oval.png);}");

        horizontalLayout->addWidget(ovalButton);

        arrowButton = new QPushButton(widget_2);
        arrowButton->setObjectName(QStringLiteral("arrowButton"));
        arrowButton->setMinimumSize(QSize(30, 30));
        arrowButton->setMaximumSize(QSize(30, 30));
		arrowButton->setToolTip(QStringLiteral("arrow"));
        arrowButton->setStyleSheet("QPushButton{border-image: url(./res/btn_arrow.png);}");

        horizontalLayout->addWidget(arrowButton);

        penButton = new QPushButton(widget_2);
        penButton->setObjectName(QStringLiteral("penButton"));
        penButton->setMinimumSize(QSize(30, 30));
        penButton->setMaximumSize(QSize(30, 30));
		penButton->setToolTip(QStringLiteral("brush"));
        penButton->setStyleSheet("QPushButton{border-image: url(./res/btn_brush.png);}");

        horizontalLayout->addWidget(penButton);

        undoButton = new QPushButton(widget_2);
        undoButton->setObjectName(QStringLiteral("undoButton"));
        undoButton->setMinimumSize(QSize(30, 30));
        undoButton->setMaximumSize(QSize(30, 30));
		undoButton->setToolTip(QStringLiteral("undo"));
        undoButton->setStyleSheet("QPushButton{border-image: url(./res/btn_undo.png);}");

        horizontalLayout->addWidget(undoButton);

        sizeButtonSmall = new QPushButton(widget_2);
        sizeButtonSmall->setObjectName(QStringLiteral("sizeButtonSmall"));
        sizeButtonSmall->setMinimumSize(QSize(20, 20));
        sizeButtonSmall->setMaximumSize(QSize(20, 20));
        sizeButtonSmall->setAutoFillBackground(false);
		sizeButtonSmall->setToolTip(QStringLiteral("small"));
        sizeButtonSmall->setStyleSheet("QPushButton{border-image: url(./res/btn_small.png);}");

        horizontalLayout->addWidget(sizeButtonSmall);

        sizeButtonNormal = new QPushButton(widget_2);
        sizeButtonNormal->setObjectName(QStringLiteral("sizeButtonNormal"));
        sizeButtonNormal->setMinimumSize(QSize(20, 20));
        sizeButtonNormal->setMaximumSize(QSize(20, 20));
        sizeButtonNormal->setAutoFillBackground(false);
		sizeButtonNormal->setToolTip(QStringLiteral("normal"));
        sizeButtonNormal->setStyleSheet("QPushButton{border-image: url(./res/btn_normal.png);}");

        horizontalLayout->addWidget(sizeButtonNormal);

        sizeButtonLarge = new QPushButton(widget_2);
        sizeButtonLarge->setObjectName(QStringLiteral("sizeButtonLarge"));
        sizeButtonLarge->setMinimumSize(QSize(20, 20));
        sizeButtonLarge->setMaximumSize(QSize(20, 20));
        sizeButtonLarge->setAutoFillBackground(false);
		sizeButtonLarge->setToolTip(QStringLiteral("large"));
        sizeButtonLarge->setStyleSheet("QPushButton{border-image: url(./res/btn_big.png);}");

        horizontalLayout->addWidget(sizeButtonLarge);

        colorButton = new QPushButton(widget_2);
        colorButton->setObjectName(QStringLiteral("colorButton"));
        colorButton->setMinimumSize(QSize(30, 30));
        colorButton->setMaximumSize(QSize(30, 30));
		colorButton->setToolTip(QStringLiteral("color"));
        colorButton->setStyleSheet(QLatin1String("QPushButton {\n"
"border:2px groove gray;\n"
"border-radius:2px;\n"
"padding:2px 4px;\n"
"background:rgb(255, 0, 0)\n"
"}\n"
"QPushButton:hover{\n"
"border:2px groove white;\n"
"border-radius:2px;\n"
"padding:2px 4px;\n"
"background:rgb(255, 0, 0)\n"
"}\n"
"\n"
""));

        horizontalLayout->addWidget(colorButton);

        saveButton = new QPushButton(widget_2);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setMinimumSize(QSize(30, 30));
        saveButton->setMaximumSize(QSize(30, 30));
		saveButton->setToolTip(QStringLiteral("save"));
        saveButton->setStyleSheet("QPushButton{border-image: url(./res/btn_save.png);}");

        horizontalLayout->addWidget(saveButton);

        okButton = new QPushButton(widget_2);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setMinimumSize(QSize(30, 30));
        okButton->setMaximumSize(QSize(30, 30));
		okButton->setToolTip(QStringLiteral("ok"));
        okButton->setStyleSheet("QPushButton{border-image: url(./res/btn_ok.png);}");
        okButton->setIconSize(QSize(42, 42));

        horizontalLayout->addWidget(okButton);

        ovalButton->raise();
        penButton->raise();
        okButton->raise();
        rectButton->raise();
        undoButton->raise();
        saveButton->raise();
        arrowButton->raise();
        colorButton->raise();
        mosaicButton->raise();
        sizeButtonLarge->raise();
        sizeButtonNormal->raise();
        sizeButtonSmall->raise();

        verticalLayout->addWidget(widget_2);

        colorPanel = new QWidget(cmdPanel);
        colorPanel->setObjectName(QStringLiteral("colorPanel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(colorPanel->sizePolicy().hasHeightForWidth());
        colorPanel->setSizePolicy(sizePolicy);
        colorPanel->setMaximumSize(QSize(65535, 65535));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Button, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush);
        colorPanel->setPalette(palette1);
        colorPanel->setAutoFillBackground(false);
        colorPanel->setStyleSheet(QLatin1String("border:1px groove gray;\n"
"border-radius:3px;\n"
"padding:2px 4px;\n"
"background:#000000"));
        horizontalLayout_2 = new QHBoxLayout(colorPanel);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        colorButton1 = new QPushButton(colorPanel);
        colorButton1->setObjectName(QStringLiteral("colorButton1"));
        colorButton1->setMinimumSize(QSize(20, 20));
        colorButton1->setMaximumSize(QSize(20, 20));
        colorButton1->setAutoFillBackground(false);
        colorButton1->setStyleSheet(QLatin1String("QPushButton {\n"
"border:2px groove gray;\n"
"border-radius:2px;\n"
"padding:2px 4px;\n"
"background:rgb(255, 0, 0)\n"
"}\n"
"QPushButton:hover{\n"
"border:2px groove white;\n"
"border-radius:2px;\n"
"padding:2px 4px;\n"
"background:rgb(255, 0, 0)\n"
"}\n"
"\n"
""));

        horizontalLayout_2->addWidget(colorButton1);

        colorButton2 = new QPushButton(colorPanel);
        colorButton2->setObjectName(QStringLiteral("colorButton2"));
        colorButton2->setMinimumSize(QSize(20, 20));
        colorButton2->setMaximumSize(QSize(20, 20));
        colorButton2->setAutoFillBackground(false);
        colorButton2->setStyleSheet(QLatin1String("QPushButton {\n"
"border:2px groove gray;\n"
"border-radius:2px;\n"
"padding:2px 4px;\n"
"background:rgb(255, 8, 243)\n"
"}\n"
"QPushButton:hover{\n"
"border:2px groove white;\n"
"border-radius:2px;\n"
"padding:2px 4px;\n"
"background:rgb(255, 8, 243)\n"
"}\n"
"\n"
""));

        horizontalLayout_2->addWidget(colorButton2);

        colorButton3 = new QPushButton(colorPanel);
        colorButton3->setObjectName(QStringLiteral("colorButton3"));
        colorButton3->setMinimumSize(QSize(20, 20));
        colorButton3->setMaximumSize(QSize(20, 20));
        colorButton3->setAutoFillBackground(false);
        colorButton3->setStyleSheet(QLatin1String("QPushButton {\n"
"border:2px groove gray;\n"
"border-radius:2px;\n"
"padding:2px 4px;\n"
"background:rgb(127, 35, 255)\n"
"}\n"
"QPushButton:hover{\n"
"border:2px groove white;\n"
"border-radius:2px;\n"
"padding:2px 4px;\n"
"background:rgb(127, 35, 255)\n"
"}\n"
"\n"
""));

        horizontalLayout_2->addWidget(colorButton3);

        colorButton4 = new QPushButton(colorPanel);
        colorButton4->setObjectName(QStringLiteral("colorButton4"));
        colorButton4->setMinimumSize(QSize(20, 20));
        colorButton4->setMaximumSize(QSize(20, 20));
        colorButton4->setAutoFillBackground(false);
        colorButton4->setStyleSheet(QLatin1String("QPushButton {\n"
"border:2px groove gray;\n"
"border-radius:2px;\n"
"padding:2px 4px;\n"
"background:rgb(0, 0, 255)\n"
"}\n"
"QPushButton:hover{\n"
"border:2px groove white;\n"
"border-radius:2px;\n"
"padding:2px 4px;\n"
"background:rgb(0, 0, 255)\n"
"}\n"
"\n"
""));

        horizontalLayout_2->addWidget(colorButton4);

        colorButton5 = new QPushButton(colorPanel);
        colorButton5->setObjectName(QStringLiteral("colorButton5"));
        colorButton5->setMinimumSize(QSize(20, 20));
        colorButton5->setMaximumSize(QSize(20, 20));
        colorButton5->setAutoFillBackground(false);
        colorButton5->setStyleSheet(QLatin1String("QPushButton {\n"
"border:2px groove gray;\n"
"border-radius:2px;\n"
"padding:2px 4px;\n"
"background:rgb(53, 255, 255)\n"
"}\n"
"QPushButton:hover{\n"
"border:2px groove white;\n"
"border-radius:2px;\n"
"padding:2px 4px;\n"
"background:rgb(53, 255, 255)\n"
"}\n"
"\n"
""));
        colorButton5->setIconSize(QSize(42, 42));

        horizontalLayout_2->addWidget(colorButton5);

        saveButton_4 = new QPushButton(colorPanel);
        saveButton_4->setObjectName(QStringLiteral("saveButton_4"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(saveButton_4->sizePolicy().hasHeightForWidth());
        saveButton_4->setSizePolicy(sizePolicy1);
        saveButton_4->setMinimumSize(QSize(20, 20));
        saveButton_4->setMaximumSize(QSize(20, 20));
        saveButton_4->setAutoFillBackground(false);
        saveButton_4->setStyleSheet(QLatin1String("QPushButton {\n"
"border:2px groove gray;\n"
"border-radius:2px;\n"
"padding:2px 4px;\n"
"background:rgb(175, 255, 194)\n"
"}\n"
"QPushButton:hover{\n"
"border:2px groove white;\n"
"border-radius:2px;\n"
"padding:2px 4px;\n"
"background:rgb(175, 255, 194)\n"
"}\n"
"\n"
""));

        horizontalLayout_2->addWidget(saveButton_4);

        saveButton_3 = new QPushButton(colorPanel);
        saveButton_3->setObjectName(QStringLiteral("saveButton_3"));
        saveButton_3->setMinimumSize(QSize(20, 20));
        saveButton_3->setMaximumSize(QSize(20, 20));
        saveButton_3->setAutoFillBackground(false);
        saveButton_3->setStyleSheet(QLatin1String("QPushButton {\n"
"border:2px groove gray;\n"
"border-radius:2px;\n"
"padding:2px 4px;\n"
"background:rgb(0, 255, 0)\n"
"}\n"
"QPushButton:hover{\n"
"border:2px groove white;\n"
"border-radius:2px;\n"
"padding:2px 4px;\n"
"background:rgb(0, 255, 0)\n"
"}\n"
"\n"
""));

        horizontalLayout_2->addWidget(saveButton_3);

        saveButton_5 = new QPushButton(colorPanel);
        saveButton_5->setObjectName(QStringLiteral("saveButton_5"));
        saveButton_5->setMinimumSize(QSize(20, 20));
        saveButton_5->setMaximumSize(QSize(20, 20));
        saveButton_5->setAutoFillBackground(false);
        saveButton_5->setStyleSheet(QLatin1String("QPushButton {\n"
"border:2px groove gray;\n"
"border-radius:2px;\n"
"padding:2px 4px;\n"
"background:rgb(192, 255, 90)\n"
"}\n"
"QPushButton:hover{\n"
"border:2px groove white;\n"
"border-radius:2px;\n"
"padding:2px 4px;\n"
"background:rgb(192, 255, 90)\n"
"}\n"
"\n"
""));

        horizontalLayout_2->addWidget(saveButton_5);

        saveButton_7 = new QPushButton(colorPanel);
        saveButton_7->setObjectName(QStringLiteral("saveButton_7"));
        saveButton_7->setMinimumSize(QSize(20, 20));
        saveButton_7->setMaximumSize(QSize(20, 20));
        saveButton_7->setAutoFillBackground(false);
        saveButton_7->setStyleSheet(QLatin1String("QPushButton {\n"
"border:2px groove gray;\n"
"border-radius:2px;\n"
"padding:2px 4px;\n"
"background:rgb(255, 255, 76)\n"
"}\n"
"QPushButton:hover{\n"
"border:2px groove white;\n"
"border-radius:2px;\n"
"padding:2px 4px;\n"
"background:rgb(255, 255, 76)\n"
"}\n"
"\n"
""));

        horizontalLayout_2->addWidget(saveButton_7);

        saveButton_6 = new QPushButton(colorPanel);
        saveButton_6->setObjectName(QStringLiteral("saveButton_6"));
        saveButton_6->setMinimumSize(QSize(20, 20));
        saveButton_6->setMaximumSize(QSize(20, 20));
        saveButton_6->setAutoFillBackground(false);
        saveButton_6->setStyleSheet(QLatin1String("QPushButton {\n"
"border:2px groove gray;\n"
"border-radius:2px;\n"
"padding:2px 4px;\n"
"background:rgb(255, 144, 33)\n"
"}\n"
"QPushButton:hover{\n"
"border:2px groove white;\n"
"border-radius:2px;\n"
"padding:2px 4px;\n"
"background:rgb(255, 144, 33)\n"
"}\n"
"\n"
""));

        horizontalLayout_2->addWidget(saveButton_6);

        saveButton_8 = new QPushButton(colorPanel);
        saveButton_8->setObjectName(QStringLiteral("saveButton_8"));
        saveButton_8->setMinimumSize(QSize(20, 20));
        saveButton_8->setMaximumSize(QSize(20, 20));
        saveButton_8->setAutoFillBackground(false);
        saveButton_8->setStyleSheet(QLatin1String("QPushButton {\n"
"border:2px groove gray;\n"
"border-radius:2px;\n"
"padding:2px 4px;\n"
"background:#000000\n"
"}\n"
"QPushButton:hover{\n"
"border:2px groove white;\n"
"border-radius:2px;\n"
"padding:2px 4px;\n"
"background:#000000\n"
"}\n"
"\n"
""));

        horizontalLayout_2->addWidget(saveButton_8);

        saveButton_2 = new QPushButton(colorPanel);
        saveButton_2->setObjectName(QStringLiteral("saveButton_2"));
        saveButton_2->setMinimumSize(QSize(20, 20));
        saveButton_2->setMaximumSize(QSize(20, 20));
        saveButton_2->setAutoFillBackground(false);
        saveButton_2->setStyleSheet(QLatin1String("QPushButton {\n"
"border:2px groove gray;\n"
"border-radius:2px;\n"
"padding:2px 4px;\n"
"background:#ffffff\n"
"}\n"
"QPushButton:hover{\n"
"border:2px groove white;\n"
"border-radius:2px;\n"
"padding:2px 4px;\n"
"background:#ffffff\n"
"}\n"
"\n"
""));

        horizontalLayout_2->addWidget(saveButton_2);


        verticalLayout->addWidget(colorPanel);

        FullScreenImageEditor->setCentralWidget(centerWidget);
        cmdPanel->raise();
        saveButton_7->raise();
        colorButton5->raise();
        saveButton_5->raise();
        saveButton_8->raise();
        colorButton3->raise();
        colorButton2->raise();
        colorButton4->raise();
        saveButton_4->raise();
        colorButton1->raise();
        saveButton_6->raise();
        saveButton_3->raise();
        saveButton_2->raise();
        saveButton_8->raise();
        colorButton5->raise();
        saveButton_5->raise();
        saveButton_7->raise();
        colorButton3->raise();
        colorButton2->raise();
        colorButton4->raise();
        saveButton_4->raise();
        colorButton1->raise();
        saveButton_6->raise();
        saveButton_3->raise();
        saveButton_2->raise();

        retranslateUi(FullScreenImageEditor);

        QMetaObject::connectSlotsByName(FullScreenImageEditor);
    } // setupUi

    void retranslateUi(QMainWindow *FullScreenImageEditor)
    {
        FullScreenImageEditor->setWindowTitle(QApplication::translate("FullScreenImageEditor", "MainWindow", 0));
        mosaicButton->setText(QString());
        rectButton->setText(QString());
        ovalButton->setText(QString());
        arrowButton->setText(QString());
        penButton->setText(QString());
        undoButton->setText(QString());
        sizeButtonSmall->setText(QString());
        sizeButtonNormal->setText(QString());
        sizeButtonLarge->setText(QString());
        colorButton->setText(QString());
        saveButton->setText(QString());
        okButton->setText(QString());
        colorButton1->setText(QString());
        colorButton2->setText(QString());
        colorButton3->setText(QString());
        colorButton4->setText(QString());
        colorButton5->setText(QString());
        saveButton_4->setText(QString());
        saveButton_3->setText(QString());
        saveButton_5->setText(QString());
        saveButton_7->setText(QString());
        saveButton_6->setText(QString());
        saveButton_8->setText(QString());
        saveButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FullScreenImageEditor: public Ui_FullScreenImageEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FULLSCREENIMAGEEDITOR_H
