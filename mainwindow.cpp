#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calculator.h"
#include <QPixmap>
#include <QPainter>
#include <QGraphicsItem>
#include <QtDebug>
#include <string>
#include <QMouseEvent>
//#include <QtScript/QScriptEngine>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    update_ui();
    ui->graphic->setMouseTracking(true);
    //connect(, &Graphic::signalTargetCoordinate, &Graphic::slotTarget);

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
    this->ui->graphic->repaint();// перерисовывает рисунок
    update_ui ();

}

void MainWindow::on_clover_clicked() // Кнопка, для рисования клевера
{

    this->ui->graphic->setBackgroundColor(Qt::white); // белый фон
    this->ui->graphic->setFunction(Graphic::clover); // присваевает mFunction значение клевер
    this->ui->graphic->repaint(); // перерисовывает рисунок
    update_ui ();
}

void MainWindow::on_Archimedes_clicked() // Кнопка, для рисования  фигуры
{
    this->ui->graphic->setBackgroundColor(Qt::white); // белый фон
    this->ui->graphic->setFunction(Graphic::Archimedes); // присваевает mFunction значение архимед
    this->ui->graphic->repaint(); // перерисовывает рисунок
    update_ui ();
}


void MainWindow::on_snail_clicked() // Кнопка, для рисования фигуры
{
    this->ui->graphic->setBackgroundColor(Qt::white); // белый фон
    this->ui->graphic->setFunction(Graphic::snail); // присваевает mFunction значение улитка
    this->ui->graphic->repaint(); // перерисовывает рисунок
    update_ui ();
}

void MainWindow::on_hyperbolicSpiral_clicked()
{
    this->ui->graphic->setBackgroundColor(Qt::white); // белый фон
    this->ui->graphic->setFunction(Graphic::hyperbolicSpiral);
    this->ui->graphic->repaint(); // перерисовывает рисунок
    update_ui ();
}

void MainWindow::on_Bernulli_clicked()
{
    this->ui->graphic->setBackgroundColor(Qt::white); // белый фон
    this->ui->graphic->setFunction(Graphic::Bernulli);
    this->ui->graphic->repaint(); // перерисовывает рисунок
    update_ui ();
}
void MainWindow::on_Astroid_clicked()
{
    this->ui->graphic->setBackgroundColor(Qt::white); // белый фон
    this->ui->graphic->setFunction(Graphic::Astroid);
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
void MainWindow::mousePressEvent(QGraphicsSceneMouseEvent * event ){

          if(event->buttons() & Qt::RightButton){
   emit signalTargetCoordinate(event->scenePos());
   this->ui->X_coordinate->setText("X:" );
   this->ui->X_coordinate->setText(ui->X_coordinate->text()+(event->scenePos().x()));
   this->ui->Y_coordinate->setText("Y:");
   this->ui->Y_coordinate->setText(ui->Y_coordinate->text()+event->scenePos().y());

}
}


void MainWindow::on_call_calculator_clicked()
{
    calculator s;
    s.setModal(true);
    s.exec();

}


