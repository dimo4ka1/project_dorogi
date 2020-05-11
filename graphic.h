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

    Functions tfunction;//переменная созданная для сохранения
    QString tcodefuction;//переменная созданная для сохранения
    double tscale;//переменная созданная для сохранения
    double tAValue;//переменная созданная для сохранения


    int NumberOfLine=0;//количество прямых
    QPointF tmassPos[100][2];//массив точек, через которые рисуют прямые


    void setBackgroundColor(QColor color){ mBackgroundColor = color; } //Функция, которая объявляет цвет
    QColor BackgroundColor() const { return mBackgroundColor; }

    void setFunction(Functions function) { mFunction= function; tfunction=function; on_function_change(); } // Обьявляю функцию, которая присваетвает переменнной mFunction значение из списка.
    Functions function () const { return mFunction; }                             //Потом это понадобиться


    void Line(bool line) { mLine= line; }//Функция, которая меняет параметр mLine
    bool Line() const { return mLine; }


    void setAsymptote(bool asymptote) { mAsymptote= asymptote; }//Функция, которая меняет
    bool Asymptote() const { return mAsymptote; }

    void setScale(double scale) { mScale= scale;  repaint(); } //Функция, которая присваевает размер введенный в окошке
   double scale  () const { return mScale; }

    void setIntervalLength(double intervalLength) { mIntervalLength= intervalLength; repaint(); } //Функция, которая присваевает интервал углу из окна
   double intervalLength () const {  return mIntervalLength; }

    void setAValue(double aValue) { mAValue = aValue; repaint(); } //Функция, которая присваевает параметр а
   double aValue () const { return mAValue; }

    void setStepCount (int count) { mStepCount = count; repaint(); }//Функция, которая присваевает четкость прорисовки
    int stepCount () const { return mStepCount; }

    void setNumberOfLine (int numberOfLine) { NumberOfLine = numberOfLine; repaint(); }//Функция, которая отвечает за количество линий
    int numberOfLine() const { return NumberOfLine; }

    void setPos1(QPointF pos1){ mPos1 = pos1; } // 1 точка прямой
    QPointF pos1 () const{ return mPos1; }

    void setPos2(QPointF pos2){ mPos2 = pos2; }// 2 точка прямой
    QPointF pos2 () const{ return mPos2; }

    void setmassPos(double x0, double y0,double x1,double y1, int i){

        massPos[i][0]=QPoint(x0,y0);

        massPos[i][1]=QPoint(x1,y1);

                                               }
   // QPointF pos () const{ return massPos[1][1]; }

    void setCodeFunction(QString CodeFunction){ mCodeFunction = CodeFunction; tcodefuction= CodeFunction;}//Функция, которая присваевает уравнение введенное в калькуляторе калькулятора
    QString CodeFunction () const { return mCodeFunction; }



protected:
        void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

signals:
      void signalTargetCoordinate(QPointF mousepoint);


public slots:

private slots:
    //  void slotTimer();

private:

       QPointF compute_function(double t);                  // Объявляю главную функцию
       QPointF compute_circle(double t);                    // Круг
       QPointF compute_clover(double t, double a);           // Полярная роза
       QPointF compute_Archimedes(double t, double a);       // Спираль Архимеда
       QPointF compute_snail(double t, double a);            // Кардиоида
       QPointF compute_hyperbolicSpiral(double t, double a); // Гиперболическая спираль
       QPointF compute_Bernulli(double t, double a);         // Лемниската Бернулли
       QPointF compute_FEdit(double t, double a);            // Введенная функция
       QPointF compute_calculate(double t,QString CodeFunction);                 // Функция из канкулятора
       QPointF compute_Astroid(double t, double a);          // Астроида
       QPointF compute_LogSpiral(double t, double a);        // Логарифмическая спираль

       QString string(int a); //функция перевода из int в string
       double rho(double t);


       void on_function_change(); // Объявляю функцию, отвечающую за размер, угол, кол-во точек на графике
       QColor mBackgroundColor; // Цвет
       QColor mShapeColor;
       Functions mFunction = Graphic::clear; // Переменная, отвечающая за тип графика, ключевая часть програмы
       QTimer *Timer;      // Игровой таймер
       QPointF target;         // Положение курсора

       QPointF mPos1;
       QPointF mPos2;

        bool mAsymptote;
    QPointF massPos[100][2];
       QString mCodeFunction;//формула из калькулятора
       const double h=1e-10;//шаг, для нахождения лимитов
       bool mLine;//Переменная отвечающая рисуем линию, или нет
       double mScale;  // Размер
       double mIntervalLength; // Интервал угла
       int mStepCount; // Количество точек на графике
       double mAValue; // Коэффициент a
};

#endif // GRAPHIC_H
