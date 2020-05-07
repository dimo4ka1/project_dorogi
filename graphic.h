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

/*#include <QScriptEngine>
#include <QtScript/QScriptEngine>
#include <QtScript/QscriptValue>
#include <QtScript/QScriptValueList>
#include <QString>
*/
class Graphic : public QWidget // Я так назвал виджет, обычно это не на что не влияет
{
    Q_OBJECT
public:
    explicit Graphic(QWidget *parent = 0);

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

    enum Functions{circle, clover,Archimedes,snail, hyperbolicSpiral, Bernulli,calculate,Astroid,LogSpiral,clear };

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

    void setNumberOfLine (int numberOfLine) { NumberOfLine = numberOfLine; repaint(); }
    int numberOfLine() const { return NumberOfLine; }

    void setPos1(QPointF pos1){ mPos1 = pos1; }
    QPointF pos1 () const{ return mPos1; }

    void setPos2(QPointF pos2){ mPos2 = pos2; }
    QPointF pos2 () const{ return mPos2; }

    void setCodeFunction(QString CodeFunction){ mCodeFunction = CodeFunction; }
    QString CodeFunction () const { return mCodeFunction; }
    int NumberOfLine=0;
protected:
        void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

signals:
      void signalTargetCoordinate(QPointF mousepoint);


public slots:

private slots:
    //  void slotTimer();

private:

       QPointF compute_function(float t);                  // Объявляю главную функцию
       QPointF compute_circle(float t);                    // Круг
       QPointF compute_clover(float t, float a);           // Полярная роза
       QPointF compute_Archimedes(float t, float a);       // Спираль Архимеда
       QPointF compute_snail(float t, float a);            // Кардиоида
       QPointF compute_hyperbolicSpiral(float t, float a); // Гиперболическая спираль
       QPointF compute_Bernulli(float t, float a);         // Лемниската Бернулли
       QPointF compute_FEdit(float t, float a);            // Введенная функция
       QPointF compute_calculate(float t,QString CodeFunction);                 // Функция из канкулятора
       QPointF compute_Astroid(float t, float a);          // Астроида
       QPointF compute_LogSpiral(float t, float a);        // Логарифмическая спираль

       int asimtote(int argc, const char * argv[]);  // функция рисующая асимптоты
       double rho(double t);
       double rho1(double t);
       double rho2(double t);
       double rho3(double t);

       void on_function_change(); // Объявляю функцию, отвечающую за размер, угол, кол-во точек на графике
       QColor mBackgroundColor; // Цвет
       QColor mShapeColor;
       Functions mFunction; // Переменная, отвечающая за тип графика, ключевая часть програмы
       QTimer *Timer;      // Игровой таймер
       QPointF target;         // Положение курсора

       QPointF mPos1;
       QPointF mPos2;
       QPointF massPos[100][2];


       QString mCodeFunction;
       const double h=1e-10;
       bool mLine;
       float mScale;  // Размер
       float mIntervalLength; // Интервал угла
       int mStepCount; // Количество точек на графике
       float mAValue; // Коэффициент a
};

#endif // GRAPHIC_H
