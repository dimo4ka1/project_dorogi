#include "graphic.h"
#include<QPainter>
#include<QPaintEvent>
#include"math.h"
#include "helper.cpp"

//Для проверки экстремумов
#include <iostream>
using namespace std;

Graphic::Graphic(QWidget *parent) :
    QWidget(parent),
    mBackgroundColor(255,255,255),
    mShapeColor(QColor (0, 0, 0))

{
    on_function_change();
}

QSize Graphic::minimumSizeHint() const
{
    return QSize(500,500);
}

QSize Graphic::sizeHint() const
{
    return QSize(800, 500);
}

QPointF Graphic::compute_circle(float t) //Круг
{
    float cos_t = cos(t);
    float sin_t = sin(t);
    float x=cos_t;
    float y = sin_t;
    return QPointF(x,y);
}

QPointF Graphic::compute_clover(float t, float a) // Полярная роза
{
    float cos_t = cos(t);
    float sin_t = sin(t);
    float x=cos(a*t)*cos_t;
    float y = cos(a*t)*sin_t;
    return QPointF(x,y);
}
QPointF Graphic::compute_Archimedes(float t, float a) // Спираль Архемеда
{
    float cos_t = cos(t);
    float sin_t = sin(t);
    float x=(t+a)*cos_t;
    float y =(t+a)*sin_t;
    return QPointF(x,y);
}
QPointF Graphic::compute_snail(float t,float a) // Кардиоида
{
    float cos_t = cos(t);
    float sin_t = sin(t);
    float x=(1+a*cos_t)*cos_t;
    float y =(1+a*cos_t)*sin_t;
    return QPointF(x,y);
}

QPointF Graphic::compute_hyperbolicSpiral(float t, float a) // Гиперболической спираль
{
    float cos_t = cos(t);
    float sin_t = sin(t);
    float x=(a/t)*cos_t;
    float y =(a/t)*sin_t;
    return QPointF(x,y);
}
QPointF Graphic::compute_Bernulli(float t, float a) // Лемниската Бернулли
{
    float x = (cos(2*t + a*M_PI_2) >= 0) ? sqrt((cos(2*t + a*M_PI_2)))*cos(t) : 0;
    float y = (cos(2*t + a*M_PI_2) >= 0) ? sqrt((cos(2*t + a*M_PI_2)))*sin(t) : 0;
    return QPointF(x,y);
}

void Graphic::on_function_change() // Присваивание к mFunction выбранного графика
{
    switch(mFunction) {
    case circle:
        mScale= 40;
        mStepCount =M_PI;
        mIntervalLength=M_PI*2*50;
        break;
    case clover:
        mScale = 40;
        mStepCount =1024*32;
        mAValue = 2;
        mIntervalLength=M_PI*2*50;
        break;
    case Archimedes:
        mScale = 40;
        mStepCount = 2048;
        mAValue =1;
        mIntervalLength=M_PI*2*50;
        break;
    case snail:
        mScale = 40;
        mStepCount =1024;
        mAValue = 2;
        mIntervalLength=M_PI*2*50;
        break;
    case hyperbolicSpiral:
        mScale= 40;
        mStepCount = 2*1024;
        mIntervalLength=M_PI*2*50;
        mAValue = 1;
        break;
    case Bernulli:
        mScale= 40;
        mStepCount = 2*1024;
        mIntervalLength=M_PI*2*50;
        mAValue = 0;
        break;
    default:
        break;
    }

}
QPointF Graphic::compute_function(float t) // Вызов выбранной функции
{
    switch(mFunction) {
    case circle:
        return compute_circle(t);
        break;
    case clover:
        return compute_clover(t,mAValue);
        break;
    case Archimedes:
        return compute_Archimedes(t, mAValue);
        break;
    case snail:
        return compute_snail(t, mAValue);
        break;
    case hyperbolicSpiral:
        return compute_hyperbolicSpiral(t, mAValue);
        break;
    case Bernulli:
        return  compute_Bernulli(t, mAValue);
        break;
    default:
        break;
}
return QPointF(0,0);

}
 void Graphic::paintEvent(QPaintEvent *event) // Рисуем график
 {
     QPainter painter(this);

     painter.setBrush(mBackgroundColor); //цвет фона
     painter.setPen(mShapeColor); //цвет рисунка

     painter.setRenderHint(QPainter::Antialiasing, true);
     painter.drawRect(this->rect());
     QPoint center = this->rect().center(); //центр холста

     QPointF prevPoint = compute_function (0); //задаем начальную точку
     QPoint prevPixel;
     prevPixel.setX(prevPoint.x()*2*mScale + center.x());
     prevPixel.setY(prevPoint.y()*2*mScale + center.y());

     float step = mIntervalLength/50 / mStepCount;
     for(float i=0; i<= mIntervalLength/50; i+=step ) {
         painter.setPen(Qt::black);

         // Объявляем точку и задаем ее координаты
         QPointF point = compute_function(i);
         QPoint pixel;
         pixel.setX(point.x()*2*mScale + center.x());
         pixel.setY(point.y()*2*mScale + center.y());

         // Нахождение экстремумов (неудачная попытка сравнения соседних точек, пока неизвестно, почему)
         float x0 = point.x();
         float y0 = point.x();
         QPointF point1 = compute_function(i+step);
         float x1 = point1.x();
         float y1 = point1.y();
         QPointF point2 = compute_function(i-step);
         float x2 = point2.x();
         float y2 = point2.y();
         if ((x0 > x1 && x0 > x2) || (x0 < x1 && x0 < x2) || (y0 > y1 && y0 > y2) || (y0 < y1 && y0 < y2)) {
             cout << "i = " << i << endl; //вывод для проверки
             /*cout << "x0 = " << x0 << endl << "y0 = " << y0 << endl;
             cout << "x1 = " << x1 << endl << "y1 = " << y1 << endl;
             cout << "x2 = " << x2 << endl << "y2 = " << y2 << endl;*/
             painter.setPen(Qt::red);
             painter.drawPoint(pixel);
         } else {
             painter.drawLine(pixel, prevPixel); // Соединяем точки
         }
         prevPixel = pixel; //задаем предыдущую точку
     }
 }

