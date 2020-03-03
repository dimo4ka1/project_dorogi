#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_circle_clicked()
{
    this->ui->graphic->setBackgroundColor(Qt::white);
    this->ui->graphic->setFunction(Graphic::circle);
    this->ui->graphic->repaint();
}

void MainWindow::on_clover_clicked()
{
    this->ui->graphic->setBackgroundColor(Qt::white);
    this->ui->graphic->setFunction(Graphic::clover);
    this->ui->graphic->repaint();
}

void MainWindow::on_Archimedes_clicked()
{
    this->ui->graphic->setBackgroundColor(Qt::white);
    this->ui->graphic->setFunction(Graphic::Archimedes);
    this->ui->graphic->repaint();
}


void MainWindow::on_snail_clicked()
{
    this->ui->graphic->setBackgroundColor(Qt::white);
    this->ui->graphic->setFunction(Graphic::snail);
    this->ui->graphic->repaint();
}

void MainWindow::on_scale_valueChanged(double scale)
{
    this->ui->graphic->setScale(scale);
}

void MainWindow::on_intervallength_valueChanged(double intervalLength)
{
    this->ui->graphic->setIntervalLength(intervalLength);
}

