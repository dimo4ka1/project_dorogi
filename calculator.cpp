#include "calculator.h"
#include "ui_calculator.h"
#include "graphic.h"


calculator::calculator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::calculator)
{
    ui->setupUi(this);
    ui->output_icon->setText((ui->output_icon->text())+"\u03C1"+"=");

}

calculator::~calculator()
{
    delete ui;
}

void calculator::on_Pi_clicked()
{
  ui->output_icon->setText((ui->output_icon->text())+"Pi");
}

void calculator::on_number_1_clicked()
{
    ui->output_icon->setText((ui->output_icon->text())+"1");
}

void calculator::on_number_2_clicked()
{
  ui->output_icon->setText((ui->output_icon->text())+"2");
}

void calculator::on_number_3_clicked()
{
  ui->output_icon->setText((ui->output_icon->text())+"3");
}

void calculator::on_exp_clicked()
{
  ui->output_icon->setText((ui->output_icon->text())+"e");
}

void calculator::on_number_4_clicked()
{
  ui->output_icon->setText((ui->output_icon->text())+"4");
}

void calculator::on_number_5_clicked()
{
  ui->output_icon->setText((ui->output_icon->text())+"5");
}

void calculator::on_number_6_clicked()
{
  ui->output_icon->setText((ui->output_icon->text())+"6");
}



void calculator::on_sin_clicked()
{
  ui->output_icon->setText((ui->output_icon->text())+"sin");
}

void calculator::on_number_7_clicked()
{
  ui->output_icon->setText((ui->output_icon->text())+"7");
}

void calculator::on_number_8_clicked()
{
  ui->output_icon->setText((ui->output_icon->text())+"8");
}

void calculator::on_number_9_clicked()
{
  ui->output_icon->setText((ui->output_icon->text())+"9");
}
void calculator::on_number_0_clicked()
{
    ui->output_icon->setText((ui->output_icon->text())+"0");
}

void calculator::on_dot_clicked()
{
    if(!(ui->output_icon->text().contains('.')))
        ui->output_icon->setText((ui->output_icon->text())+".");
}

void calculator::on_cos_clicked()
{
  ui->output_icon->setText((ui->output_icon->text())+"cos");
}

void calculator::on_tg_clicked()
{
  ui->output_icon->setText((ui->output_icon->text())+"tg");
}

void calculator::on_ctg_clicked()
{
  ui->output_icon->setText((ui->output_icon->text())+"ctg");
}

void calculator::on_plus_clicked()
{
   ui->output_icon->setText((ui->output_icon->text())+"+");
}

void calculator::on_minus_clicked()
{
   ui->output_icon->setText((ui->output_icon->text())+"-");
}

void calculator::on_multiply_clicked()
{
   ui->output_icon->setText((ui->output_icon->text())+"*");
}

void calculator::on_divide_clicked()
{
   ui->output_icon->setText((ui->output_icon->text())+"/");
}

void calculator::on_angle_clicked()
{
   ui->output_icon->setText((ui->output_icon->text())+"\u03B8");
}
void calculator::on_hook_open_clicked()
{
    ui->output_icon->setText((ui->output_icon->text())+"(");
}

void calculator::on_hook_close_clicked()
{
    ui->output_icon->setText((ui->output_icon->text())+")");
}
QString calculator::value(){
    return ui->output_icon->text();

}

void calculator::on_start_clicked()
{
    mready == true;

    close();
    //QMetaObject::invokeMethod(this,"close",Qt::QueuedConnection);

}
