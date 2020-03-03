#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix1(":/sketch/img/circle.tiff");
    QPixmap pix2(":/sketch/img/sinRose.tiff");

    int w1 = 250;
    int h1 = 150;

    int w2 = 250;
    int h2 = 150;

    //ui->sketchCircle->setPixmap(pix1.scaled(w1, h1, Qt::KeepAspectRatio));
    //ui->sketchSinRose->setPixmap(pix2.scaled(w2, h2, Qt::KeepAspectRatio));


    this->ui->spinScale->setValue(this->ui->renderArea->scale());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnAstroid_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Astroid);
    this->ui->renderArea->repaint();

    this->ui->spinScale->setValue(this->ui->renderArea->scale());
}

void MainWindow::on_btnCycloid_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Cycloid);
    this->ui->renderArea->repaint();

    this->ui->spinScale->setValue(this->ui->renderArea->scale());
}

void MainWindow::on_btnHuygensCycloid_clicked()
{
    this->ui->renderArea->setShape(RenderArea::HuygensCycloid);
    this->ui->renderArea->repaint();

    this->ui->spinScale->setValue(this->ui->renderArea->scale());
}

void MainWindow::on_btnHypo_clicked()
{
    this->ui->renderArea->setShape(RenderArea::HypoCycloid );
    this->ui->renderArea->repaint();

    this->ui->spinScale->setValue(this->ui->renderArea->scale());
}

void MainWindow::on_btnLine_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Line );
    this->ui->renderArea->repaint();

    this->ui->spinScale->setValue(this->ui->renderArea->scale());
}

void MainWindow::on_spinScale_valueChanged(double scale)
{
    this->ui->renderArea->setScale (scale);
}
