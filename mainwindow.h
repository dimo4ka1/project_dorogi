#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPushButton>
#include <QMouseEvent>
#include <QMainWindow>
#include <QGraphicsSceneMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
      void signalTargetCoordinate(QPointF mousepoint);


private slots:


    void on_circle_clicked();

    void on_clover_clicked();

    void on_Archimedes_clicked();

    void on_snail_clicked();

    void on_scale_valueChanged(double arg1);

    void on_intervallength_valueChanged(double arg1);

    void on_hyperbolicSpiral_clicked();

    void on_aValue_valueChanged(double arg1);

    void on_Bernulli_clicked();

    void on_stepCount_valueChanged(int arg1);

    void on_call_calculator_clicked();

    void mousePressEvent(QMouseEvent * event );

    void on_Astroid_clicked();

    void on_Line_clicked();

    void on_clear_clicked();

    void on_LogSpiral_clicked();



private:
    void update_ui(); // Выведение значений параметров у графиков

    QPointF pos1;

    QPointF pos2;

    bool check;
private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
