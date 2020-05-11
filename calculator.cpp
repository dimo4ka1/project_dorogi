#include "calculator.h"
#include "ui_calculator.h"
#include "graphic.h"


calculator::calculator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::calculator)
{
    ui->setupUi(this);
    ui->output_icon->setText((ui->output_icon->text())+"\u03C1"+"=");
    setCodeFun("");
ui->degree->setToolTip("pow(x, y)");
ui->lg->setToolTip("Для log<sub>x</sub>(y) введите lg(x)/lg(y)");
}

calculator::~calculator()
{
    delete ui;
}
//кнопка калькулятора
void calculator::on_Pi_clicked()
{
  ui->output_icon->setText((ui->output_icon->text())+"Pi");
  mCodeFun += "Math.PI";
}
//кнопка калькулятора
void calculator::on_number_1_clicked()
{
    ui->output_icon->setText((ui->output_icon->text())+"1");
    mCodeFun += "1";


}
//кнопка калькулятора
void calculator::on_number_2_clicked()
{
  ui->output_icon->setText((ui->output_icon->text())+"2");
  mCodeFun += "2";
}
//кнопка калькулятора
void calculator::on_number_3_clicked()
{
  ui->output_icon->setText((ui->output_icon->text())+"3");
  mCodeFun += "3";
}
//кнопка калькулятора
void calculator::on_number_4_clicked()
{
  ui->output_icon->setText((ui->output_icon->text())+"4");
  mCodeFun += "4";
}
//кнопка калькулятора
void calculator::on_number_5_clicked()
{
  ui->output_icon->setText((ui->output_icon->text())+"5");
  mCodeFun += "5";
}
//кнопка калькулятора
void calculator::on_number_6_clicked()
{
  ui->output_icon->setText((ui->output_icon->text())+"6");
  mCodeFun += "6";
}
//кнопка калькулятора
void calculator::on_number_7_clicked()
{
  ui->output_icon->setText((ui->output_icon->text())+"7");
  mCodeFun += "7";
}
//кнопка калькулятора
void calculator::on_number_8_clicked()
{
  ui->output_icon->setText((ui->output_icon->text())+"8");
  mCodeFun += "8";
}
//кнопка калькулятора
void calculator::on_number_9_clicked()
{
  ui->output_icon->setText((ui->output_icon->text())+"9");
  mCodeFun += "9";
}
//кнопка калькулятора
void calculator::on_number_0_clicked()
{
    ui->output_icon->setText((ui->output_icon->text())+"0");
    mCodeFun += "0";
}
//кнопка калькулятора
void calculator::on_dot_clicked()
{

    if(mPow==true){mPow=false; mCodeFun += ", "; ui->output_icon->setText((ui->output_icon->text())+", ");}
    else  {mCodeFun += "."; ui->output_icon->setText((ui->output_icon->text())+".");}
}
//кнопка калькулятора
void calculator::on_exp_clicked()
{
  ui->output_icon->setText((ui->output_icon->text())+"e");
  mCodeFun += "Math.E";
}
//кнопка калькулятора
void calculator::on_sin_clicked()
{
  ui->output_icon->setText((ui->output_icon->text())+"sin(");
  mCodeFun += "Math.sin(";
}
//кнопка калькулятора
void calculator::on_cos_clicked()
{
  ui->output_icon->setText((ui->output_icon->text())+"cos(");
  mCodeFun += "Math.cos(";
}
//кнопка калькулятора
void calculator::on_tg_clicked()
{
  ui->output_icon->setText((ui->output_icon->text())+"tg(");
  mCodeFun += "Math.tan(";
}
//кнопка калькулятора
void calculator::on_ctg_clicked()
{
  ui->output_icon->setText((ui->output_icon->text())+"ctg(");
  mCodeFun += "Math.cot(";
}
//кнопка калькулятора
void calculator::on_plus_clicked()
{
   ui->output_icon->setText((ui->output_icon->text())+"+");
   mCodeFun += "+";
}
//кнопка калькулятора
void calculator::on_minus_clicked()
{
   ui->output_icon->setText((ui->output_icon->text())+"-");
   mCodeFun += "-";
}
//кнопка калькулятора
void calculator::on_multiply_clicked()
{
   ui->output_icon->setText((ui->output_icon->text())+"*");
   mCodeFun += "*";
}
//кнопка калькулятора
void calculator::on_divide_clicked()
{
   ui->output_icon->setText((ui->output_icon->text())+"/");
   mCodeFun += "/";
}
//кнопка калькулятора
void calculator::on_angle_clicked()
{
   ui->output_icon->setText((ui->output_icon->text())+"\u03B8");
   mCodeFun += "t";
}
//кнопка калькулятора
void calculator::on_hook_open_clicked()
{
    ui->output_icon->setText((ui->output_icon->text())+"(");
    mCodeFun += "(";
}
//кнопка калькулятора
void calculator::on_hook_close_clicked()
{
    ui->output_icon->setText((ui->output_icon->text())+")");
    mCodeFun += ")";
}

QString calculator::value(){
    return ui->output_icon->text();
}
//кнопка калькулятора заканчивающая программу
void calculator::on_start_clicked()
{
    setFormula(ui->output_icon->text());
    setCodeFun(mCodeFun);

    close();
}
//кнопка калькулятора
void calculator::on_lg_clicked()
{
    ui->output_icon->setText((ui->output_icon->text())+"lg(");
    mCodeFun += "Math.log10(";
}

//кнопка калькулятора
void calculator::on_ln_clicked()
{
    ui->output_icon->setText((ui->output_icon->text())+"ln(");
    mCodeFun += "Math.log(";
}
//кнопка калькулятора
void calculator::on_delete_2_clicked()
{
    ui->output_icon->setText("\u03C1");
    ui->output_icon->setText(ui->output_icon->text()+"=");
    setCodeFun("");
}
//кнопка калькулятора
void calculator::on_cancel_clicked()
{
    QString a=ui->output_icon->text();
    int b=1;
    a.chop(b);
    ui->output_icon->setText(a);
    mCodeFun.chop(1);

}

//кнопка калькулятора
void calculator::on_degree_clicked()
{
    ui->output_icon->setText((ui->output_icon->text())+"pow(");
    mCodeFun += "Math.pow(";
    mPow=true;
}
//кнопка калькулятора
void calculator::on_exp_2_clicked()
{
    ui->output_icon->setText((ui->output_icon->text())+"exp(");
    mCodeFun += "Math.exp(";
}

//кнопка калькулятора
void calculator::on_radical_clicked()
{
    ui->output_icon->setText((ui->output_icon->text())+"\u221A(");
    mCodeFun += "Math.sqrt(";

}
//кнопка калькулятора
void calculator::on_arcsin_clicked()
{
    ui->output_icon->setText((ui->output_icon->text())+"arcsin(");
    mCodeFun += "Math.asin(";
}
//кнопка калькулятора
void calculator::on_arccos_clicked()
{
    ui->output_icon->setText((ui->output_icon->text())+"arccos(");
    mCodeFun += "Math.acos(";
}
//кнопка калькулятора
void calculator::on_arctg_clicked()
{
    ui->output_icon->setText((ui->output_icon->text())+"arctg(");
    mCodeFun += "Math.atan(";
}
//кнопка калькулятора
void calculator::on_arcctg_clicked()
{
    ui->output_icon->setText((ui->output_icon->text())+"arcctg(");
    mCodeFun += "Math.acot(";
}
