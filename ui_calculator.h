/********************************************************************************
** Form generated from reading UI file 'calculator.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATOR_H
#define UI_CALCULATOR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_calculator
{
public:
    QLabel *output_icon;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *ctg;
    QPushButton *minus;
    QPushButton *Pi;
    QPushButton *hook_open;
    QPushButton *divide;
    QPushButton *plus;
    QPushButton *number_7;
    QPushButton *angle;
    QPushButton *number_0;
    QPushButton *tg;
    QPushButton *number_8;
    QPushButton *sin;
    QPushButton *number_6;
    QPushButton *dot;
    QPushButton *number_3;
    QPushButton *number_9;
    QPushButton *number_4;
    QPushButton *multiply;
    QPushButton *number_5;
    QPushButton *start;
    QPushButton *number_2;
    QPushButton *exp;
    QPushButton *number_1;
    QPushButton *hook_close;
    QPushButton *cos;

    void setupUi(QDialog *calculator)
    {
        if (calculator->objectName().isEmpty())
            calculator->setObjectName(QString::fromUtf8("calculator"));
        calculator->resize(500, 660);
        calculator->setMinimumSize(QSize(500, 660));
        calculator->setMaximumSize(QSize(500, 660));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/picture/logo.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        calculator->setWindowIcon(icon);
        output_icon = new QLabel(calculator);
        output_icon->setObjectName(QString::fromUtf8("output_icon"));
        output_icon->setGeometry(QRect(0, 0, 500, 171));
        output_icon->setMinimumSize(QSize(500, 150));
        output_icon->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 28pt \"MS Shell Dlg 2\";\n"
"  qproperty-alignment: 'AlignVCenter | AlignRight';\n"
"  border: 1px solid gray;\n"
"background-color : white;\n"
"}\n"
"\n"
""));
        layoutWidget = new QWidget(calculator);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 165, 502, 502));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        ctg = new QPushButton(layoutWidget);
        ctg->setObjectName(QString::fromUtf8("ctg"));
        ctg->setMinimumSize(QSize(100, 100));
        ctg->setMaximumSize(QSize(100, 100));
        ctg->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"	font: 30pt \"MS Shell Dlg 2\";\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        ctg->setIconSize(QSize(100, 100));

        gridLayout->addWidget(ctg, 3, 0, 1, 1);

        minus = new QPushButton(layoutWidget);
        minus->setObjectName(QString::fromUtf8("minus"));
        minus->setMinimumSize(QSize(100, 100));
        minus->setMaximumSize(QSize(100, 100));
        minus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 151, 57);\n"
"  color: white; \n"
"font: 35pt \"MS Shell Dlg 2\";\n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}\n"
""));
        minus->setIconSize(QSize(100, 100));

        gridLayout->addWidget(minus, 1, 7, 1, 1);

        Pi = new QPushButton(layoutWidget);
        Pi->setObjectName(QString::fromUtf8("Pi"));
        Pi->setMinimumSize(QSize(100, 100));
        Pi->setMaximumSize(QSize(100, 100));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/for_calculator/picture2/pi_button.png"), QSize(), QIcon::Normal, QIcon::Off);
        Pi->setIcon(icon1);
        Pi->setIconSize(QSize(90, 100));

        gridLayout->addWidget(Pi, 4, 0, 1, 1);

        hook_open = new QPushButton(layoutWidget);
        hook_open->setObjectName(QString::fromUtf8("hook_open"));
        hook_open->setMinimumSize(QSize(100, 100));
        hook_open->setMaximumSize(QSize(100, 100));
        hook_open->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"	font: 30pt \"MS Shell Dlg 2\";\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        hook_open->setIconSize(QSize(100, 100));

        gridLayout->addWidget(hook_open, 4, 5, 1, 1);

        divide = new QPushButton(layoutWidget);
        divide->setObjectName(QString::fromUtf8("divide"));
        divide->setMinimumSize(QSize(100, 100));
        divide->setMaximumSize(QSize(100, 100));
        divide->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 151, 57);\n"
"  color: white; \n"
"font: 35pt \"MS Shell Dlg 2\";\n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}\n"
""));
        divide->setIconSize(QSize(100, 100));

        gridLayout->addWidget(divide, 3, 7, 1, 1);

        plus = new QPushButton(layoutWidget);
        plus->setObjectName(QString::fromUtf8("plus"));
        plus->setMinimumSize(QSize(100, 100));
        plus->setMaximumSize(QSize(100, 100));
        plus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 151, 57);\n"
"  color: white; \n"
"font: 35pt \"MS Shell Dlg 2\";\n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}\n"
""));
        plus->setIconSize(QSize(100, 100));

        gridLayout->addWidget(plus, 0, 7, 1, 1);

        number_7 = new QPushButton(layoutWidget);
        number_7->setObjectName(QString::fromUtf8("number_7"));
        number_7->setMinimumSize(QSize(100, 100));
        number_7->setMaximumSize(QSize(100, 100));
        number_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 35pt \"MS Shell Dlg 2\";\n"
"   border: 1px solid gray;\n"
"\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        number_7->setIconSize(QSize(100, 100));

        gridLayout->addWidget(number_7, 2, 3, 1, 1);

        angle = new QPushButton(layoutWidget);
        angle->setObjectName(QString::fromUtf8("angle"));
        angle->setMinimumSize(QSize(100, 100));
        angle->setMaximumSize(QSize(100, 100));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/for_calculator/picture2/alpha_button.png"), QSize(), QIcon::Normal, QIcon::Off);
        angle->setIcon(icon2);
        angle->setIconSize(QSize(90, 90));

        gridLayout->addWidget(angle, 3, 3, 1, 1);

        number_0 = new QPushButton(layoutWidget);
        number_0->setObjectName(QString::fromUtf8("number_0"));
        number_0->setMinimumSize(QSize(100, 100));
        number_0->setMaximumSize(QSize(100, 100));
        number_0->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 35pt \"MS Shell Dlg 2\";\n"
"   border: 1px solid gray;\n"
"\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        number_0->setIconSize(QSize(100, 100));

        gridLayout->addWidget(number_0, 3, 5, 1, 1);

        tg = new QPushButton(layoutWidget);
        tg->setObjectName(QString::fromUtf8("tg"));
        tg->setMinimumSize(QSize(100, 100));
        tg->setMaximumSize(QSize(100, 100));
        tg->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"	font: 30pt \"MS Shell Dlg 2\";\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        tg->setIconSize(QSize(100, 100));

        gridLayout->addWidget(tg, 2, 0, 1, 1);

        number_8 = new QPushButton(layoutWidget);
        number_8->setObjectName(QString::fromUtf8("number_8"));
        number_8->setMinimumSize(QSize(100, 100));
        number_8->setMaximumSize(QSize(100, 100));
        number_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 35pt \"MS Shell Dlg 2\";\n"
"   border: 1px solid gray;\n"
"\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        number_8->setIconSize(QSize(100, 100));

        gridLayout->addWidget(number_8, 2, 5, 1, 1);

        sin = new QPushButton(layoutWidget);
        sin->setObjectName(QString::fromUtf8("sin"));
        sin->setMinimumSize(QSize(100, 100));
        sin->setMaximumSize(QSize(100, 100));
        sin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"	font: 30pt \"MS Shell Dlg 2\";\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        sin->setIconSize(QSize(100, 100));

        gridLayout->addWidget(sin, 0, 0, 1, 1);

        number_6 = new QPushButton(layoutWidget);
        number_6->setObjectName(QString::fromUtf8("number_6"));
        number_6->setMinimumSize(QSize(100, 100));
        number_6->setMaximumSize(QSize(100, 100));
        number_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 35pt \"MS Shell Dlg 2\";\n"
"   border: 1px solid gray;\n"
"\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        number_6->setIconSize(QSize(100, 100));

        gridLayout->addWidget(number_6, 1, 6, 1, 1);

        dot = new QPushButton(layoutWidget);
        dot->setObjectName(QString::fromUtf8("dot"));
        dot->setMinimumSize(QSize(100, 100));
        dot->setMaximumSize(QSize(100, 100));
        dot->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"	font: 30pt \"MS Shell Dlg 2\";\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        dot->setIconSize(QSize(100, 100));

        gridLayout->addWidget(dot, 3, 6, 1, 1);

        number_3 = new QPushButton(layoutWidget);
        number_3->setObjectName(QString::fromUtf8("number_3"));
        number_3->setMinimumSize(QSize(100, 100));
        number_3->setMaximumSize(QSize(100, 100));
        number_3->setSizeIncrement(QSize(100, 100));
        number_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 35pt \"MS Shell Dlg 2\";\n"
"   border: 1px solid gray;\n"
"\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        number_3->setIconSize(QSize(100, 100));

        gridLayout->addWidget(number_3, 0, 6, 1, 1);

        number_9 = new QPushButton(layoutWidget);
        number_9->setObjectName(QString::fromUtf8("number_9"));
        number_9->setMinimumSize(QSize(100, 100));
        number_9->setMaximumSize(QSize(100, 100));
        number_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 35pt \"MS Shell Dlg 2\";\n"
"   border: 1px solid gray;\n"
"\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        number_9->setIconSize(QSize(100, 100));

        gridLayout->addWidget(number_9, 2, 6, 1, 1);

        number_4 = new QPushButton(layoutWidget);
        number_4->setObjectName(QString::fromUtf8("number_4"));
        number_4->setMinimumSize(QSize(100, 100));
        number_4->setMaximumSize(QSize(100, 100));
        number_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 35pt \"MS Shell Dlg 2\";\n"
"   border: 1px solid gray;\n"
"\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        number_4->setIconSize(QSize(100, 100));

        gridLayout->addWidget(number_4, 1, 3, 1, 1);

        multiply = new QPushButton(layoutWidget);
        multiply->setObjectName(QString::fromUtf8("multiply"));
        multiply->setMinimumSize(QSize(100, 100));
        multiply->setMaximumSize(QSize(100, 100));
        multiply->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 151, 57);\n"
"  color: white; \n"
"font: 35pt \"MS Shell Dlg 2\";\n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}\n"
""));
        multiply->setIconSize(QSize(100, 100));

        gridLayout->addWidget(multiply, 2, 7, 1, 1);

        number_5 = new QPushButton(layoutWidget);
        number_5->setObjectName(QString::fromUtf8("number_5"));
        number_5->setMinimumSize(QSize(100, 100));
        number_5->setMaximumSize(QSize(100, 100));
        number_5->setSizeIncrement(QSize(100, 100));
        number_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 35pt \"MS Shell Dlg 2\";\n"
"   border: 1px solid gray;\n"
"\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        number_5->setIconSize(QSize(100, 100));

        gridLayout->addWidget(number_5, 1, 5, 1, 1);

        start = new QPushButton(layoutWidget);
        start->setObjectName(QString::fromUtf8("start"));
        start->setMinimumSize(QSize(100, 100));
        start->setMaximumSize(QSize(100, 100));
        start->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 24pt \"MS Shell Dlg 2\";\n"
"  background-color: rgb(255, 151, 57);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        start->setIconSize(QSize(100, 100));

        gridLayout->addWidget(start, 4, 7, 1, 1);

        number_2 = new QPushButton(layoutWidget);
        number_2->setObjectName(QString::fromUtf8("number_2"));
        number_2->setMinimumSize(QSize(100, 100));
        number_2->setSizeIncrement(QSize(100, 100));
        number_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 35pt \"MS Shell Dlg 2\";\n"
"   border: 1px solid gray;\n"
"\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        number_2->setIconSize(QSize(100, 100));

        gridLayout->addWidget(number_2, 0, 5, 1, 1);

        exp = new QPushButton(layoutWidget);
        exp->setObjectName(QString::fromUtf8("exp"));
        exp->setMinimumSize(QSize(100, 100));
        exp->setMaximumSize(QSize(100, 100));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/for_calculator/picture2/e.png"), QSize(), QIcon::Normal, QIcon::Off);
        exp->setIcon(icon3);
        exp->setIconSize(QSize(90, 90));

        gridLayout->addWidget(exp, 4, 3, 1, 1);

        number_1 = new QPushButton(layoutWidget);
        number_1->setObjectName(QString::fromUtf8("number_1"));
        number_1->setMinimumSize(QSize(100, 100));
        number_1->setMaximumSize(QSize(100, 100));
        number_1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 35pt \"MS Shell Dlg 2\";\n"
"   border: 1px solid gray;\n"
"\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        number_1->setIconSize(QSize(100, 100));

        gridLayout->addWidget(number_1, 0, 3, 1, 1);

        hook_close = new QPushButton(layoutWidget);
        hook_close->setObjectName(QString::fromUtf8("hook_close"));
        hook_close->setMinimumSize(QSize(100, 100));
        hook_close->setMaximumSize(QSize(100, 100));
        hook_close->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"	font: 30pt \"MS Shell Dlg 2\";\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        hook_close->setIconSize(QSize(100, 100));

        gridLayout->addWidget(hook_close, 4, 6, 1, 1);

        cos = new QPushButton(layoutWidget);
        cos->setObjectName(QString::fromUtf8("cos"));
        cos->setMinimumSize(QSize(100, 100));
        cos->setMaximumSize(QSize(100, 100));
        cos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"	font: 30pt \"MS Shell Dlg 2\";\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        cos->setIconSize(QSize(100, 100));

        gridLayout->addWidget(cos, 1, 0, 1, 1);


        retranslateUi(calculator);

        QMetaObject::connectSlotsByName(calculator);
    } // setupUi

    void retranslateUi(QDialog *calculator)
    {
        calculator->setWindowTitle(QCoreApplication::translate("calculator", "Function input window", nullptr));
        output_icon->setText(QString());
        ctg->setText(QCoreApplication::translate("calculator", "ctg", nullptr));
        minus->setText(QCoreApplication::translate("calculator", "-", nullptr));
        Pi->setStyleSheet(QCoreApplication::translate("calculator", "QPushButton {\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"	font: 30pt \"MS Shell Dlg 2\";\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}", nullptr));
        Pi->setText(QString());
        hook_open->setText(QCoreApplication::translate("calculator", "(", nullptr));
        divide->setText(QCoreApplication::translate("calculator", "/", nullptr));
        plus->setText(QCoreApplication::translate("calculator", "+", nullptr));
        number_7->setText(QCoreApplication::translate("calculator", "7", nullptr));
        angle->setStyleSheet(QCoreApplication::translate("calculator", "QPushButton {\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"	font: 30pt \"MS Shell Dlg 2\";\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}", nullptr));
        angle->setText(QString());
        number_0->setText(QCoreApplication::translate("calculator", "0", nullptr));
        tg->setText(QCoreApplication::translate("calculator", "tg", nullptr));
        number_8->setText(QCoreApplication::translate("calculator", "8", nullptr));
        sin->setText(QCoreApplication::translate("calculator", "sin", nullptr));
        number_6->setText(QCoreApplication::translate("calculator", "6", nullptr));
        dot->setText(QCoreApplication::translate("calculator", ".", nullptr));
        number_3->setText(QCoreApplication::translate("calculator", "3", nullptr));
        number_9->setText(QCoreApplication::translate("calculator", "9", nullptr));
        number_4->setText(QCoreApplication::translate("calculator", "4", nullptr));
        multiply->setText(QCoreApplication::translate("calculator", "*", nullptr));
        number_5->setText(QCoreApplication::translate("calculator", "5", nullptr));
        start->setText(QCoreApplication::translate("calculator", "start", nullptr));
        number_2->setText(QCoreApplication::translate("calculator", "2", nullptr));
        exp->setStyleSheet(QCoreApplication::translate("calculator", "QPushButton {\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"	font: 30pt \"MS Shell Dlg 2\";\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}", nullptr));
        exp->setText(QString());
        number_1->setText(QCoreApplication::translate("calculator", "1", nullptr));
        hook_close->setText(QCoreApplication::translate("calculator", ")", nullptr));
        cos->setText(QCoreApplication::translate("calculator", "cos", nullptr));
    } // retranslateUi

};

namespace Ui {
    class calculator: public Ui_calculator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATOR_H
