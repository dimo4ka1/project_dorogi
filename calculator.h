#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QDialog>
#include <QString>

namespace Ui {
class calculator;
}

class calculator : public QDialog
{
    Q_OBJECT

public:
    explicit calculator(QWidget *parent = nullptr);
    ~calculator();

    QString value();



    void setCodeFun(QString CodeFun){ mCodeFun = CodeFun; }
    QString CodeFun () const { return mCodeFun; }

    void setFormula(QString Formula) { mFormula = Formula; }
    QString Formula() const { return mFormula; }

private slots:

    void on_Pi_clicked();

    void on_number_1_clicked();

    void on_number_2_clicked();

    void on_number_3_clicked();

    void on_exp_clicked();

    void on_number_4_clicked();

    void on_number_5_clicked();

    void on_number_6_clicked();

    void on_sin_clicked();

    void on_number_7_clicked();

    void on_number_8_clicked();

    void on_number_9_clicked();

    void on_dot_clicked();

    void on_cos_clicked();

    void on_tg_clicked();

    void on_ctg_clicked();

    void on_plus_clicked();

    void on_minus_clicked();

    void on_multiply_clicked();

    void on_divide_clicked();

    void on_angle_clicked();

    void on_number_0_clicked();

    void on_hook_open_clicked();

    void on_hook_close_clicked();

    void on_start_clicked();



    void on_lg_clicked();

    void on_ln_clicked();

    void on_delete_2_clicked();

    void on_cancel_clicked();

    void on_degree_clicked();

    void on_exp_2_clicked();

    void on_radical_clicked();

    void on_arcsin_clicked();

    void on_arccos_clicked();

    void on_arctg_clicked();

    void on_arcctg_clicked();

private:



    QString mCodeFun;
    QString mFormula;

private:
    Ui::calculator *ui;
};

#endif // CALCULATOR_H
