#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QDialog>

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


    bool mready;

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

private:
    Ui::calculator *ui;
};

#endif // CALCULATOR_H
