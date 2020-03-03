#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_circle_clicked();

    void on_clover_clicked();

    void on_Archimedes_clicked();

    void on_snail_clicked();

    void on_scale_valueChanged(double arg1);

    void on_intervallength_valueChanged(double arg1);

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
// Тут я нечего не трогал, оно само
