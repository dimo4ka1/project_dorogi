#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    update_ui();
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
    this->ui->graphic->setBackgroundColor(Qt::white);//белый фон
    this->ui->graphic->setFunction(Graphic::circle);//присваевает mFunction значение круг
    this->ui->graphic->repaint();//перерисовывает рисунок
    update_ui ();
}

void MainWindow::on_clover_clicked()// Кнопка, для рисования клевера
{
    this->ui->graphic->setBackgroundColor(Qt::white);//белый фон
    this->ui->graphic->setFunction(Graphic::clover);//присваевает mFunction значение клевер
    this->ui->graphic->repaint();//перерисовывает рисунок
    update_ui ();
}

void MainWindow::on_Archimedes_clicked()// Кнопка, для рисования  фигуры
{
    this->ui->graphic->setBackgroundColor(Qt::white);//белый фон
    this->ui->graphic->setFunction(Graphic::Archimedes);//присваевает mFunction значение архимед
    this->ui->graphic->repaint();//перерисовывает рисунок
    update_ui ();
}


void MainWindow::on_snail_clicked()// Кнопка, для рисования фигуры
{
    this->ui->graphic->setBackgroundColor(Qt::white);//белый фон
    this->ui->graphic->setFunction(Graphic::snail);//присваевает mFunction значение улитка
    this->ui->graphic->repaint();//перерисовывает рисунок
    update_ui ();
}

void MainWindow::on_hyperbolicSpiral_clicked()
{
    this->ui->graphic->setBackgroundColor(Qt::white);//белый фон
    this->ui->graphic->setFunction(Graphic::hyperbolicSpiral);
    this->ui->graphic->repaint();//перерисовывает рисунок
    update_ui ();
}

void MainWindow::on_Bernulli_clicked()
{
    this->ui->graphic->setBackgroundColor(Qt::white);//белый фон
    this->ui->graphic->setFunction(Graphic::Bernulli);
    this->ui->graphic->repaint();//перерисовывает рисунок
    update_ui ();
}

void MainWindow::on_scale_valueChanged(double scale)//изменяет размер
{
    this->ui->graphic->setScale(scale);
}

void MainWindow::on_intervallength_valueChanged(double intervalLength)// изменяет интервал
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
