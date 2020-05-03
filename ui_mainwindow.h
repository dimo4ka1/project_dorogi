/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "graphic.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    Graphic *graphic;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *call_calculator;
    QScrollArea *menugr;
    QWidget *scrollAreaWidgetContents;
    QPushButton *circle;
    QPushButton *clover;
    QPushButton *Archimedes;
    QPushButton *snail;
    QPushButton *hyperbolicSpiral;
    QPushButton *Bernulli;
    QPushButton *Astroid;
    QPushButton *Line;
    QPushButton *LogSpiral;
    QScrollBar *scroll;
    QScrollArea *parametr;
    QWidget *scrollAreaWidgetContents_2;
    QFormLayout *formLayout;
    QDoubleSpinBox *scale;
    QLabel *textScale;
    QDoubleSpinBox *intervallength;
    QLabel *label;
    QDoubleSpinBox *aValue;
    QLabel *label_2;
    QSpinBox *stepCount;
    QLabel *label_3;
    QDoubleSpinBox *K_value;
    QDoubleSpinBox *B_value;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *X_coordinate;
    QLabel *Y_coordinate;
    QPushButton *clear;
    QLabel *formula;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1235, 700);
        MainWindow->setMinimumSize(QSize(1235, 700));
        MainWindow->setMaximumSize(QSize(1235, 700));
        MainWindow->setContextMenuPolicy(Qt::DefaultContextMenu);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/picture/logo.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setIconSize(QSize(700, 700));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphic = new Graphic(centralwidget);
        graphic->setObjectName(QString::fromUtf8("graphic"));
        graphic->setGeometry(QRect(0, 0, 961, 561));
        graphic->setMinimumSize(QSize(950, 400));
        QFont font;
        font.setFamily(QString::fromUtf8("MV Boli"));
        font.setPointSize(11);
        graphic->setFont(font);
        graphic->setMouseTracking(true);
        graphic->setTabletTracking(true);
        graphic->setAutoFillBackground(true);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(970, 19, 252, 570));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        call_calculator = new QPushButton(layoutWidget);
        call_calculator->setObjectName(QString::fromUtf8("call_calculator"));

        verticalLayout->addWidget(call_calculator);

        menugr = new QScrollArea(layoutWidget);
        menugr->setObjectName(QString::fromUtf8("menugr"));
        menugr->setMinimumSize(QSize(250, 400));
        menugr->setMaximumSize(QSize(700, 88800));
        menugr->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 248, 398));
        circle = new QPushButton(scrollAreaWidgetContents);
        circle->setObjectName(QString::fromUtf8("circle"));
        circle->setGeometry(QRect(10, 13, 91, 52));
        circle->setMinimumSize(QSize(55, 52));
        circle->setFocusPolicy(Qt::WheelFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/picture/photo_2020-04-16_19-24-27.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        circle->setIcon(icon1);
        circle->setIconSize(QSize(90, 100));
        clover = new QPushButton(scrollAreaWidgetContents);
        clover->setObjectName(QString::fromUtf8("clover"));
        clover->setGeometry(QRect(130, 13, 91, 52));
        clover->setMinimumSize(QSize(90, 52));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/picture/photo_2020-04-19_01-02-17.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        clover->setIcon(icon2);
        clover->setIconSize(QSize(90, 100));
        Archimedes = new QPushButton(scrollAreaWidgetContents);
        Archimedes->setObjectName(QString::fromUtf8("Archimedes"));
        Archimedes->setGeometry(QRect(10, 80, 93, 52));
        Archimedes->setMinimumSize(QSize(52, 52));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/picture/photo_2020-04-16_19-24-57.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Archimedes->setIcon(icon3);
        Archimedes->setIconSize(QSize(90, 100));
        snail = new QPushButton(scrollAreaWidgetContents);
        snail->setObjectName(QString::fromUtf8("snail"));
        snail->setGeometry(QRect(10, 140, 101, 111));
        snail->setMinimumSize(QSize(90, 101));
        snail->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/picture/\320\243\320\273\320\270\321\202\320\272\320\260.png"), QSize(), QIcon::Normal, QIcon::Off);
        snail->setIcon(icon4);
        snail->setIconSize(QSize(300, 100));
        hyperbolicSpiral = new QPushButton(scrollAreaWidgetContents);
        hyperbolicSpiral->setObjectName(QString::fromUtf8("hyperbolicSpiral"));
        hyperbolicSpiral->setGeometry(QRect(20, 260, 71, 41));
        hyperbolicSpiral->setIcon(icon3);
        hyperbolicSpiral->setIconSize(QSize(90, 100));
        Bernulli = new QPushButton(scrollAreaWidgetContents);
        Bernulli->setObjectName(QString::fromUtf8("Bernulli"));
        Bernulli->setGeometry(QRect(120, 80, 101, 51));
        Bernulli->setMinimumSize(QSize(0, 0));
        Bernulli->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/for_calculator/picture/\320\233\320\265\320\274\320\275\320\270\321\201\320\272\320\260\321\202\320\260.png"), QSize(), QIcon::Normal, QIcon::Off);
        Bernulli->setIcon(icon5);
        Bernulli->setIconSize(QSize(90, 120));
        Astroid = new QPushButton(scrollAreaWidgetContents);
        Astroid->setObjectName(QString::fromUtf8("Astroid"));
        Astroid->setGeometry(QRect(120, 140, 101, 111));
        Astroid->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/for_calculator/picture/Astroid.png"), QSize(), QIcon::Normal, QIcon::Off);
        Astroid->setIcon(icon6);
        Astroid->setIconSize(QSize(75, 75));
        Line = new QPushButton(scrollAreaWidgetContents);
        Line->setObjectName(QString::fromUtf8("Line"));
        Line->setGeometry(QRect(130, 260, 70, 41));
        Line->setMaximumSize(QSize(70, 50));
        Line->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/img/picture/\320\237\321\200\321\217\320\274\320\260\321\217.png"), QSize(), QIcon::Normal, QIcon::Off);
        Line->setIcon(icon7);
        Line->setIconSize(QSize(60, 40));
        LogSpiral = new QPushButton(scrollAreaWidgetContents);
        LogSpiral->setObjectName(QString::fromUtf8("LogSpiral"));
        LogSpiral->setGeometry(QRect(130, 311, 80, 45));
        LogSpiral->setMinimumSize(QSize(80, 45));
        LogSpiral->setIcon(icon3);
        LogSpiral->setIconSize(QSize(80, 80));
        scroll = new QScrollBar(scrollAreaWidgetContents);
        scroll->setObjectName(QString::fromUtf8("scroll"));
        scroll->setGeometry(QRect(230, 0, 20, 401));
        scroll->setOrientation(Qt::Vertical);
        menugr->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(menugr);

        parametr = new QScrollArea(layoutWidget);
        parametr->setObjectName(QString::fromUtf8("parametr"));
        parametr->setMinimumSize(QSize(250, 100));
        parametr->setMaximumSize(QSize(700, 400));
        parametr->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 227, 208));
        formLayout = new QFormLayout(scrollAreaWidgetContents_2);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        scale = new QDoubleSpinBox(scrollAreaWidgetContents_2);
        scale->setObjectName(QString::fromUtf8("scale"));
        scale->setMinimumSize(QSize(58, 21));
        scale->setMaximumSize(QSize(58, 21));
        scale->setDecimals(1);
        scale->setSingleStep(0.300000000000000);

        formLayout->setWidget(3, QFormLayout::LabelRole, scale);

        textScale = new QLabel(scrollAreaWidgetContents_2);
        textScale->setObjectName(QString::fromUtf8("textScale"));
        textScale->setMinimumSize(QSize(10, 10));
        textScale->setMouseTracking(false);
        textScale->setTabletTracking(false);

        formLayout->setWidget(3, QFormLayout::FieldRole, textScale);

        intervallength = new QDoubleSpinBox(scrollAreaWidgetContents_2);
        intervallength->setObjectName(QString::fromUtf8("intervallength"));
        intervallength->setMinimumSize(QSize(58, 21));
        intervallength->setMaximumSize(QSize(58, 21));
        intervallength->setDecimals(1);
        intervallength->setMaximum(630.000000000000000);
        intervallength->setSingleStep(10.000000000000000);

        formLayout->setWidget(4, QFormLayout::LabelRole, intervallength);

        label = new QLabel(scrollAreaWidgetContents_2);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(4, QFormLayout::FieldRole, label);

        aValue = new QDoubleSpinBox(scrollAreaWidgetContents_2);
        aValue->setObjectName(QString::fromUtf8("aValue"));
        aValue->setEnabled(true);
        aValue->setMinimumSize(QSize(58, 21));
        aValue->setMaximumSize(QSize(58, 21));
        aValue->setDecimals(1);
        aValue->setMinimum(-100.000000000000000);
        aValue->setSingleStep(1.000000000000000);

        formLayout->setWidget(5, QFormLayout::LabelRole, aValue);

        label_2 = new QLabel(scrollAreaWidgetContents_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(5, QFormLayout::FieldRole, label_2);

        stepCount = new QSpinBox(scrollAreaWidgetContents_2);
        stepCount->setObjectName(QString::fromUtf8("stepCount"));
        stepCount->setMinimumSize(QSize(58, 21));
        stepCount->setMaximumSize(QSize(58, 21));
        stepCount->setMaximum(512);
        stepCount->setSingleStep(8);

        formLayout->setWidget(6, QFormLayout::LabelRole, stepCount);

        label_3 = new QLabel(scrollAreaWidgetContents_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(6, QFormLayout::FieldRole, label_3);

        K_value = new QDoubleSpinBox(scrollAreaWidgetContents_2);
        K_value->setObjectName(QString::fromUtf8("K_value"));
        K_value->setEnabled(true);
        K_value->setMinimumSize(QSize(30, 35));
        QFont font1;
        font1.setPointSize(12);
        K_value->setFont(font1);
        K_value->setLayoutDirection(Qt::LeftToRight);
        K_value->setAutoFillBackground(false);
        K_value->setInputMethodHints(Qt::ImhFormattedNumbersOnly);
        K_value->setButtonSymbols(QAbstractSpinBox::NoButtons);
        K_value->setKeyboardTracking(true);
        K_value->setProperty("showGroupSeparator", QVariant(false));
        K_value->setDecimals(2);
        K_value->setMinimum(-50.000000000000000);
        K_value->setMaximum(50.000000000000000);
        K_value->setValue(0.000000000000000);

        formLayout->setWidget(0, QFormLayout::LabelRole, K_value);

        B_value = new QDoubleSpinBox(scrollAreaWidgetContents_2);
        B_value->setObjectName(QString::fromUtf8("B_value"));
        B_value->setMinimumSize(QSize(30, 35));
        B_value->setFont(font1);
        B_value->setButtonSymbols(QAbstractSpinBox::NoButtons);
        B_value->setDecimals(1);
        B_value->setMinimum(-25.000000000000000);
        B_value->setMaximum(25.000000000000000);

        formLayout->setWidget(2, QFormLayout::LabelRole, B_value);

        label_4 = new QLabel(scrollAreaWidgetContents_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(0, QFormLayout::FieldRole, label_4);

        label_5 = new QLabel(scrollAreaWidgetContents_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(2, QFormLayout::FieldRole, label_5);

        parametr->setWidget(scrollAreaWidgetContents_2);

        verticalLayout->addWidget(parametr);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 570, 101, 61));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        X_coordinate = new QLabel(layoutWidget1);
        X_coordinate->setObjectName(QString::fromUtf8("X_coordinate"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        X_coordinate->setFont(font2);
        X_coordinate->setContextMenuPolicy(Qt::PreventContextMenu);
        X_coordinate->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 10pt \"MS Shell Dlg 2\";\n"
"  qproperty-alignment: 'AlignVCenter | AlignLeft';\n"
"  border: 1px solid gray;\n"
"background-color : white;\n"
"}\n"
"\n"
""));

        verticalLayout_2->addWidget(X_coordinate);

        Y_coordinate = new QLabel(layoutWidget1);
        Y_coordinate->setObjectName(QString::fromUtf8("Y_coordinate"));
        Y_coordinate->setFont(font2);
        Y_coordinate->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 10pt \"MS Shell Dlg 2\";\n"
"    qproperty-alignment: 'AlignVCenter | AlignLeft';\n"
"  border: 1px solid gray;\n"
"background-color : white;\n"
"}\n"
"\n"
""));

        verticalLayout_2->addWidget(Y_coordinate);

        clear = new QPushButton(centralwidget);
        clear->setObjectName(QString::fromUtf8("clear"));
        clear->setGeometry(QRect(890, 570, 71, 61));
        formula = new QLabel(centralwidget);
        formula->setObjectName(QString::fromUtf8("formula"));
        formula->setGeometry(QRect(340, 590, 381, 41));
        formula->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 16pt \"MS Shell Dlg 2\";\n"
" qproperty-alignment: 'AlignVCenter | AlignVCenter';"));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Road", nullptr));
        call_calculator->setText(QCoreApplication::translate("MainWindow", "Touch me", nullptr));
        circle->setText(QString());
        clover->setText(QString());
        Archimedes->setText(QString());
        snail->setText(QString());
        hyperbolicSpiral->setText(QString());
        Bernulli->setText(QString());
        Astroid->setText(QString());
        Line->setText(QString());
        LogSpiral->setText(QString());
        textScale->setText(QCoreApplication::translate("MainWindow", "Scale", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Interval Length", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Parameter A", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Step Count", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "k", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "b", nullptr));
        X_coordinate->setText(QCoreApplication::translate("MainWindow", "X:", nullptr));
        Y_coordinate->setText(QCoreApplication::translate("MainWindow", "Y:", nullptr));
        clear->setText(QString());
        formula->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
