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
    check= false;
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
    this->ui->X_parametr->setText("x=a*cos(t)");
    this->ui->Y_parametr->setText("y=a*sin(t)");
    update_ui ();

}

void MainWindow::on_clover_clicked() // Кнопка, для рисования клевера
{

    this->ui->graphic->setBackgroundColor(Qt::white); // белый фон
    this->ui->graphic->setFunction(Graphic::clover); // присваевает mFunction значение клевер
    this->ui->formula->setText("\u03C1");
    this->ui->formula->setText((this->ui->formula->text())+"=cos(a*"+"\u03B8"+")");
    this->ui->graphic->repaint(); // перерисовывает рисунок
    this->ui->X_parametr->setText("x=cos(a*t)*cos(t)");
    this->ui->Y_parametr->setText("y=cos(a*t)*sin(t)");
    update_ui ();
}

void MainWindow::on_Archimedes_clicked() // Кнопка, для рисования  фигуры
{
    this->ui->graphic->setBackgroundColor(Qt::white); // белый фон
    this->ui->graphic->setFunction(Graphic::Archimedes); // присваевает mFunction значение архимед
    this->ui->formula->setText("\u03C1");
    this->ui->formula->setText((this->ui->formula->text())+"=("+"\u03B8"+"+a)");
    this->ui->graphic->repaint(); // перерисовывает рисунок
    this->ui->X_parametr->setText("x=(t+a)*cos(t)");
    this->ui->Y_parametr->setText("y=(t+a)*sin(t)");
    update_ui ();
}


void MainWindow::on_snail_clicked() // Кнопка, для рисования фигуры
{
    this->ui->graphic->setBackgroundColor(Qt::white); // белый фон
    this->ui->graphic->setFunction(Graphic::snail); // присваевает mFunction значение улитка
    this->ui->formula->setText("\u03C1");
    this->ui->formula->setText((this->ui->formula->text())+"=(1+a*cos"+ "\u03B8"+")");
    this->ui->graphic->repaint(); // перерисовывает рисунок
    this->ui->X_parametr->setText("x=(1+a*cos(t))*cos(t)");
    this->ui->Y_parametr->setText("y=(1+a*cos(t))*sin(t)");
    update_ui ();
}

void MainWindow::on_hyperbolicSpiral_clicked()
{
    this->ui->graphic->setBackgroundColor(Qt::white); // белый фон
    this->ui->graphic->setFunction(Graphic::hyperbolicSpiral);
    this->ui->formula->setText("\u03C1");
    this->ui->formula->setText((this->ui->formula->text())+"=(a/"+ "\u03B8"+")");
    this->ui->graphic->repaint(); // перерисовывает рисунок
    this->ui->X_parametr->setText("x=(a/t)*cos(t)");
    this->ui->Y_parametr->setText("y=(a/t)*sin(t)");
    update_ui ();
}

void MainWindow::on_Bernulli_clicked()
{
    this->ui->graphic->setBackgroundColor(Qt::white); // белый фон
    this->ui->graphic->setFunction(Graphic::Bernulli);
    this->ui->formula->setText("\u03C1");
    this->ui->formula->setText((this->ui->formula->text())+"^2=a^2"+ "cos2"+"\u03B8");
    this->ui->graphic->repaint(); // перерисовывает рисунок
    this->ui->X_parametr->setText("x= ");
    this->ui->Y_parametr->setText("y= ");
    update_ui ();
}

void MainWindow::on_Astroid_clicked()
{
    this->ui->graphic->setBackgroundColor(Qt::white); // белый фон
    this->ui->graphic->setFunction(Graphic::Astroid);
    this->ui->formula->setText("x^(2/3) + y^(2/3) = R^(2/3) ");
    this->ui->graphic->repaint(); // перерисовывает рисунок
    this->ui->X_parametr->setText("x=a*cos(t)^3");
    this->ui->Y_parametr->setText("y=a*sin(t)^3");
    update_ui ();
}

void MainWindow::on_LogSpiral_clicked()
{
    this->ui->graphic->setBackgroundColor(Qt::white); // белый фон
    this->ui->graphic->setFunction(Graphic::LogSpiral);
    this->ui->formula->setText("\u03C1");
    this->ui->formula->setText((this->ui->formula->text())+"= exp(a*"+"\u03B8"+")");
    this->ui->graphic->repaint(); // перерисовывает рисунок
    this->ui->X_parametr->setText("x=exp(a*t)*cos(t)");
    this->ui->Y_parametr->setText("y=exp(a*t)*sin(t)");
    update_ui ();
}

void MainWindow::on_Line_clicked()
{
    this->ui->graphic->setPos1(pos1);
    this->ui->graphic->setPos2(pos2);
    if(check ==false){
     this->ui->graphic->setNumberOfLine(this->ui->graphic->NumberOfLine +1);
        check=true;
    }else{
    check=false;

    this->ui->graphic->Line(true);
    this->ui->graphic->repaint();

}
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
}

          if(event->buttons() & Qt::LeftButton and check==true and 2*this->ui->graphic->rect().center().x() > event->pos().x() and 2*this->ui->graphic->rect().center().y() > event->pos().y()){
    pos2=pos1;
    pos1=event->pos();
    this->ui->graphic->setPos1(pos1);
    this->ui->graphic->setPos2(pos2);

     this->ui->graphic->repaint();
}
}

//Кнопка, которая очищает холст
void MainWindow::on_clear_clicked()
{
    this->ui->graphic->setBackgroundColor(Qt::white); // белый фон
    this->ui->graphic->setFunction(Graphic::clear);
    this->ui->formula->setText(" ");
    this->ui->X_parametr->setText(" ");
    this->ui->Y_parametr->setText(" ");
    this->ui->graphic->setNumberOfLine(0);
    this->ui->graphic->repaint(); // перерисовывает рисунок
    update_ui ();
}

void MainWindow::on_call_calculator_clicked()
{
    this->ui->graphic->setBackgroundColor(Qt::white); // белый фон
    this->ui->graphic->setNumberOfLine(0);
    this->ui->graphic->setFunction(Graphic::clear);
    this->ui->graphic->repaint(); // перерисовывает рисунок
    this->ui->formula->setText(" ");
    this->ui->X_parametr->setText(" ");
    this->ui->Y_parametr->setText(" ");
    calculator s;
    s.setModal(true);
    s.exec();

    this->ui->graphic->setCodeFunction(s.CodeFun());
    this->ui->formula->setText(s.Formula());
    this->ui->graphic->setFunction(Graphic::calculate);
    QString a= s.Formula();
    this->ui->X_parametr->setText("x="+a.remove(0,2)+"*cos(t)");
    this->ui->Y_parametr->setText("y="+a+"*sin(t)");
}



