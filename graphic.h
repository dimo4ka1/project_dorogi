#pragma once

#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <QWidget>
#include <QColor>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

#include <QGraphicsItem>
#include <QPainter>
#include <QPolygon>
#include <QTimer>

class Graphic : public QWidget // Я так назвал виджет, обычно это не на что не влияет
{
    Q_OBJECT
public:
    explicit Graphic(QWidget *parent = 0);

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

    enum Functions{circle, clover,Archimedes,snail, hyperbolicSpiral, Bernulli,calculate,Astroid };

    void setBackgroundColor(QColor color){ mBackgroundColor = color; } //Функция, которая объявляет цвет
    QColor BackgroundColor() const { return mBackgroundColor; }

    void setFunction(Functions function) { mFunction= function; on_function_change(); } // Обьявляю функцию, которая присваетвает переменнной mFunction значение из списка.
    Functions function () const { return mFunction; }                             //Потом это понадобиться

    void Line(bool line) { mLine= line; }
    bool Line() const { return mLine; }

    void setScale(float scale) { mScale= scale; repaint(); } //Функция, которая присваевает размер введенный в окошке
    float scale  () const { return mScale; }

    void setIntervalLength(float intervalLength) { mIntervalLength= intervalLength; repaint(); } //Функция, которая присваевает интервал углу из окна
    float intervalLength () const {  return mIntervalLength; }

    void setAValue(float aValue) { mAValue = aValue; repaint(); } //Функция, которая присваевает интервал углу из окна
    float aValue () const { return mAValue; }

    void setStepCount (int count) { mStepCount = count; repaint(); }
    int stepCount () const { return mStepCount; }

    void setmBvalue(float Bvalue){mBvalue = Bvalue; }
    int Bvalue () const{ return mBvalue;}

    void setmKvalue(float Kvalue){mKvalue = Kvalue; }
    int Kvalue () const{ return mKvalue;}

protected:
        void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

signals:
      void signalTargetCoordinate(QPointF mousepoint);


public slots:

private slots:
    //  void slotTimer();

private:
      // void mouseMoveEvent(QGraphicsSceneMouseEvent *event,QPointF target);
       QPointF compute_function(float t);                  // Объявляю главную функцию
       QPointF compute_circle(float t);                    // Круг
       QPointF compute_clover(float t, float a);           // Полярная роза
       QPointF compute_Archimedes(float t, float a);       // Спираль Архимеда
       QPointF compute_snail(float t, float a);            // Кардиоида
       QPointF compute_hyperbolicSpiral(float t, float a); // Гиперболическая спираль
       QPointF compute_Bernulli(float t, float a);         // Лемниската Бернулли
       QPointF compute_FEdit(float t, float a);            // Введенная функция
       QPointF compute_calculate(float t);                 // Функция из канкулятора
       QPointF compute_Astroid(float t, float a);
       void compute_Line(float k,float b);

       void on_function_change(); // Объявляю функцию, отвечающую за размер, угол, кол-во точек на графике
       QColor mBackgroundColor; // Цвет
       QColor mShapeColor;
       Functions mFunction; // Переменная, отвечающая за тип графика, ключевая часть програмы
       QTimer *Timer;      // Игровой таймер
       QPointF target;         // Положение курсора

       bool mLine;
       float mBvalue;
       float mKvalue;
       float mScale;  // Размер
       float mIntervalLength; // Интервал угла
       int mStepCount; // Количество точек на графике
       float mAValue; // Коэффициент a
};

#endif // GRAPHIC_H
