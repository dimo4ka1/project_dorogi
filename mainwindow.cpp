#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calculator.h"
#include <QPixmap>
#include <QPainter>
#include <QGraphicsItem>
#include <QtDebug>
#include <QString>
#include <QMouseEvent>

//#include <QtScript/QScriptEngine>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    update_ui();
    ui->graphic->setMouseTracking(true);
   // connect(ui->scroll, SIGNAL(valueChanged(int)), ui->menugr, SLOT(setNum(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_ui ()
{
    this->ui->scale->setValue(this->ui->graphic->scale());
    this->ui->intervallength->setValue(this->ui->graphic->intervalLength ());
    this->ui->aValue->setValue(this->ui->graphic->aValue());
    this->ui->stepCount->setValue(this->ui->graphic->stepCount ());
}

void MainWindow::on_circle_clicked() // Кнопка, для рисования круга
{
    this->ui->graphic->setBackgroundColor(Qt::white);// белый фон
    this->ui->graphic->setFunction(Graphic::circle);// присваевает mFunction значение круга
    this->ui->formula->setText("\u03C1");
    this->ui->formula->setText((this->ui->formula->text())+"=a");
    this->ui->graphic->repaint();// перерисовывает рисунок
    update_ui ();

}

void MainWindow::on_clover_clicked() // Кнопка, для рисования клевера
{

    this->ui->graphic->setBackgroundColor(Qt::white); // белый фон
    this->ui->graphic->setFunction(Graphic::clover); // присваевает mFunction значение клевер
    this->ui->formula->setText("\u03C1");
    this->ui->formula->setText((this->ui->formula->text())+"=cos(a*"+"\u03B8"+")");
    this->ui->graphic->repaint(); // перерисовывает рисунок
    update_ui ();
}

void MainWindow::on_Archimedes_clicked() // Кнопка, для рисования  фигуры
{
    this->ui->graphic->setBackgroundColor(Qt::white); // белый фон
    this->ui->graphic->setFunction(Graphic::Archimedes); // присваевает mFunction значение архимед
    this->ui->formula->setText("\u03C1");
    this->ui->formula->setText((this->ui->formula->text())+"=("+"\u03B8"+"+a)");
    this->ui->graphic->repaint(); // перерисовывает рисунок
    update_ui ();
}


void MainWindow::on_snail_clicked() // Кнопка, для рисования фигуры
{
    this->ui->graphic->setBackgroundColor(Qt::white); // белый фон
    this->ui->graphic->setFunction(Graphic::snail); // присваевает mFunction значение улитка
    this->ui->formula->setText("\u03C1");
    this->ui->formula->setText((this->ui->formula->text())+"=(1+a*cos"+ "\u03B8"+")");
    this->ui->graphic->repaint(); // перерисовывает рисунок
    update_ui ();
}

void MainWindow::on_hyperbolicSpiral_clicked()
{
    this->ui->graphic->setBackgroundColor(Qt::white); // белый фон
    this->ui->graphic->setFunction(Graphic::hyperbolicSpiral);
    this->ui->formula->setText("\u03C1");
    this->ui->formula->setText((this->ui->formula->text())+"=(a/"+ "\u03B8"+")");
    this->ui->graphic->repaint(); // перерисовывает рисунок
    update_ui ();
}

void MainWindow::on_Bernulli_clicked()
{
    this->ui->graphic->setBackgroundColor(Qt::white); // белый фон
    this->ui->graphic->setFunction(Graphic::Bernulli);
    this->ui->formula->setText("\u03C1");
    this->ui->formula->setText((this->ui->formula->text())+"^2=a^2"+ "cos2"+"\u03B8");
    this->ui->graphic->repaint(); // перерисовывает рисунок
    update_ui ();
}
void MainWindow::on_Astroid_clicked()
{
    this->ui->graphic->setBackgroundColor(Qt::white); // белый фон
    this->ui->graphic->setFunction(Graphic::Astroid);
    this->ui->formula->setText("x^(2/3) + y^(2/3) = R^(2/3) ");
    this->ui->graphic->repaint(); // перерисовывает рисунок
    update_ui ();
}
void MainWindow::on_LogSpiral_clicked()
{
    this->ui->graphic->setBackgroundColor(Qt::white); // белый фон
    this->ui->graphic->setFunction(Graphic::LogSpiral);
    this->ui->formula->setText("\u03C1");
    this->ui->formula->setText((this->ui->formula->text())+"= exp(a*"+"\u03B8"+")");
    this->ui->graphic->repaint(); // перерисовывает рисунок
    update_ui ();
}

void MainWindow::on_Line_clicked()
{
    this->ui->graphic->Line(true);
    this->ui->graphic->repaint();
}
void MainWindow::on_K_value_valueChanged(double arg1)
{
    this->ui->graphic->setmKvalue(arg1);
}

void MainWindow::on_B_value_valueChanged(double arg1)
{
    this->ui->graphic->setmBvalue(arg1);
}


void MainWindow::on_scale_valueChanged(double scale) // изменяет размер
{
    this->ui->graphic->setScale(scale);
}

void MainWindow::on_intervallength_valueChanged(double intervalLength) // изменяет интервал
{
    this->ui->graphic->setIntervalLength(intervalLength);
}

void MainWindow::on_aValue_valueChanged(double aValue)
{
    this->ui->graphic->setAValue(aValue);
}

void MainWindow::on_stepCount_valueChanged(int count)
{
    this->ui->graphic->setStepCount (count);
}

// Функция, которая считывает координаты мышки
void MainWindow::mousePressEvent(QMouseEvent * event ){
    emit signalTargetCoordinate(event->pos());
          if(event->buttons() & Qt::RightButton and 2*this->ui->graphic->rect().center().x() > event->pos().x() and 2*this->ui->graphic->rect().center().y() > event->pos().y()){

   this->ui->X_coordinate->setText("X:" );
   this->ui->X_coordinate->setText("X: " + QString::number((-this->ui->graphic->rect().center().x() + event->pos().x())/20));
   this->ui->Y_coordinate->setText("Y:");
    this->ui->Y_coordinate->setText("Y: " + QString::number((this->ui->graphic->rect().center().y() - event->pos().y())/20));

}}
//Кнопка, которая очищает холст
void MainWindow::on_clear_clicked()
{
    this->ui->graphic->setBackgroundColor(Qt::white); // белый фон
    this->ui->graphic->setmKvalue(0);
    this->ui->graphic->setmBvalue(0);
    this->ui->graphic->setFunction(Graphic::clear);
    this->ui->formula->setText(" ");
    this->ui->graphic->repaint(); // перерисовывает рисунок
    update_ui ();
}

void MainWindow::on_call_calculator_clicked()
{
    this->ui->graphic->setBackgroundColor(Qt::white); // белый фон
    this->ui->graphic->setmKvalue(0);
    this->ui->graphic->setmBvalue(0);
    this->ui->graphic->setFunction(Graphic::clear);
    this->ui->graphic->repaint(); // перерисовывает рисунок
    this->ui->formula->setText(" ");
    calculator s;
    s.setModal(true);
    s.exec();
    if(s.mready == true) {
    }
    this->ui->graphic->setCodeFunction(s.CodeFun());
    this->ui->formula->setText(s.Formula());
    this->ui->graphic->setFunction(Graphic::calculate);
}



