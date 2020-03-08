#include "graphic.h"
#include<QPainter>
#include<QPaintEvent>
#include"math.h"
#include "helper.cpp"

Graphic::Graphic(QWidget *parent) : QWidget(parent),
  mBackgroundColor(255,255,255)

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
QPointF Graphic::compute_Bernuli(float t, float a) // Лемниската Бернулли
{
    float cos_t = cos(t);
    float sin_t = sin(t);
    float x = sqrt(2*sin(2*t+a*M_PI_2) * cos_t*cos_t);
    float y = sqrt(2*sin(2*t+a*M_PI_2) * sin_t*sin_t);
    /*float x = sqrt(2)*(p + p*p*p)/(1 + p*p*p*p);
    float y = sqrt(2)*(p - p*p*p)/(1 + p*p*p*p); //гду р = tan(M_PI_4 - t)*/
    return QPointF(x,y);
}

void Graphic::on_function_change() // Присваивание к mFunction выбранного графика
{
    switch(mFunction) {
    case circle:
        mScale= 40;
        mStepCount =1024;
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
    case Bernuli:
        mScale= 40;
        mStepCount = 2*1024;
        mIntervalLength=M_PI_2*2*50;
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
    case Bernuli:
        return  compute_Bernuli(t, mAValue);
        break;
    default:
        break;
}
return QPointF(0,0);

}
 void Graphic::paintEvent(QPaintEvent *event) // Рисуем график
 {
     QPainter painter(this);

     painter.setBrush(mBackgroundColor); //цвет
     painter.setRenderHint(QPainter::Antialiasing, true);
     painter.drawRect(this->rect());
     QPoint center = this->rect().center(); //центр холста

     QPointF prevPoint = compute_function (0); //задаем начальную точку
     QPoint prevPixel;
     prevPixel.setX(prevPoint.x()*2*mScale + center.x());
     prevPixel.setY(prevPoint.y()*2*mScale + center.y());

     float step = mIntervalLength/50 / mStepCount;
     for(float i=0; i<= mIntervalLength/50; i+=step ) {
         QPointF point = compute_function(i);

         QPoint pixel; // Объявляем точку и задаем ее координаты
         pixel.setX(point.x()*2*mScale + center.x());
         pixel.setY(point.y()*2*mScale + center.y());
//         painter.drawPoint(pixel);// Рисуем точку
         painter.drawLine(pixel, prevPixel); // Соединяем точки
         prevPixel = pixel; //задаем предыдущую точку
     }

     //Отдельные циклы для Бернулли
     if (mFunction == Bernuli) {

            if( int(floor( mAValue)) %2) {
                for(float i=0; i<= mIntervalLength/50; i+=step ) {
                    QPointF point = compute_function(i);// тут мы вызываем функцию, для нахождения точки, много раз
                    QPoint pixel;// Объявляем точку
                    //II четверть
                    pixel.setX(-point.x()*2*mScale +center.x()); //Задаем координаты точки
                    pixel.setY(point.y()*2*mScale + center.y());//Задаем координаты точк
                    painter.drawLine(pixel, prevPixel); //Соединяем точки
                    prevPixel = pixel;
                }
            }
            for(float i=0; i<= mIntervalLength/50; i+=step ) {
                QPointF point = compute_function(i);// тут мы вызываем функцию, для нахождения точки, много раз
                QPoint pixel;// Объявляем точку
                //III четверть
                pixel.setX(-point.x()*2*mScale + center.x()); //Задаем координаты точки
                pixel.setY(-point.y()*2*mScale + center.y());//Задаем координаты точк
                painter.drawLine(pixel, prevPixel); //Соединяем точки
                prevPixel = pixel;
            }

            if( int(floor( mAValue)) %2) {
                for(float i=0; i<= mIntervalLength/50; i+=step ) {
                    QPointF point = compute_function(i);// тут мы вызываем функцию, для нахождения точки, много раз
                    QPoint pixel;// Объявляем точку
                    //IV четверть
                    pixel.setX(point.x()*2*mScale +center.x()); //Задаем координаты точки
                    pixel.setY(-point.y()*2*mScale + center.y());//Задаем координаты точк
                    painter.drawLine(pixel, prevPixel); //Соединяем точки
                    prevPixel = pixel;
                }
            }
    }
 }

