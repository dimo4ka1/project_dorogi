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
QPointF Graphic::compute_circle(float t) //Параметрическое уравнение круга
{
    float cos_t = cos(t);
    float sin_t = sin(t);
    float x=cos_t;
    float y = sin_t;
    return QPointF(x,y);// Выводит координаты точки
}
QPointF Graphic::compute_clover(float t, float a) //Параметрическое уравнение клевера
{
    float cos_t = cos(t);
    float sin_t = sin(t);
    float x=cos(a*t)*cos_t;
    float y = cos(a*t)*sin_t;
    return QPointF(x,y);// Выводит координаты точки
}
QPointF Graphic::compute_Archimedes(float t, float a)//Параметрическое уравнение спирали Архемеда
{
    float cos_t = cos(t);
    float sin_t = sin(t);
    float x=(t+a)*cos_t;
    float y =(t+a)*sin_t;
    return QPointF(x,y);// Выводит координаты точки
}
QPointF Graphic::compute_snail(float t,float a)//Параметрическое уравнение улитки Паскаля
{
    float cos_t = cos(t);
    float sin_t = sin(t);
    float x=(1+a*cos_t)*cos_t;
    float y =(1+a*cos_t)*sin_t;
    return QPointF(x,y); // Выводит координаты точки
}

QPointF Graphic::compute_hyperbolicSpiral(float t, float a)//Параметрическое уравнение гиперболической спирали
{
    float cos_t = cos(t);
    float sin_t = sin(t);
    float x=(a/t)*cos_t;
    float y =(a/t)*sin_t;
    return QPointF(x,y); // Выводит координаты точки
}
QPointF Graphic::compute_Bernuli(float t, float a)//Параметрическое уравнение гиперболической спирали
{
    float cos_t = cos(t);
    float sin_t = sin(t);
    float x =sqrt(2*sin(2*t+a*M_PI_2)* cos_t*cos_t);
    float y =sqrt(2*sin(2*t+a*M_PI_2)* sin_t * sin_t);
    return QPointF(x,y); // Выводит координаты точки
}

void Graphic::on_function_change(){   //Мы сравнивем какую фигуру выбрали, присвоили к mFunction график, и задаем размер графику
                                     //Если что, пишите, я объясню
    switch(mFunction){
    case circle:
        mScale= 40;
        mStepCount =1024;
        mIntervalLength=M_PI*2*50;// Мне надо было так сделать, это кастыль для интервала
        break;
    case clover:
        mScale = 40;
        mStepCount =1024*32;
        mAValue = 2;
        mIntervalLength=M_PI*2*50;// Мне надо было так сделать, это кастыль для интервала
        break;
    case Archimedes:
        mScale = 40;
        mStepCount =2048; // Количество точек
        mAValue =1;
        mIntervalLength=M_PI*2*50;// Мне надо было так сделать, это кастыль для интервала
        break;
    case snail:
        mScale = 40;
        mStepCount =1024;
        mAValue = 2;
        mIntervalLength=M_PI*2*50;// Мне надо было так сделать, это кастыль для интервала
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
        mIntervalLength=M_PI*2*50;
        mAValue = 0;
        break;
    }

}
QPointF Graphic::compute_function(float t){ //Мы сравнивем какую фигуру выбрали, присвоили к mFunction график, и вызываем функцию параметрического уравнения
                                           //То есть функция, для определения фигуры, чтобы потом выбрать нужную нам функцию
    switch(mFunction){
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
 void Graphic::paintEvent(QPaintEvent *event) // Тут мы рисуем на холсте
 {
     QPainter painter(this);

     painter.setBrush(mBackgroundColor); //цвет
     painter.setRenderHint(QPainter::Antialiasing, true);
     painter.drawRect(this->rect());
     QPoint center = this->rect().center(); //центр холста


     float step = mIntervalLength/50 / mStepCount;// интервал между точками
     for(float i=0; i<= mIntervalLength/50; i+=step ){
         QPointF point = compute_function(i);// тут мы вызываем функцию, для нахождения точки, много раз

         QPoint pixel;// Объявляем точку
         pixel.setX(point.x()*2*mScale + center.x()); //Задаем координаты точки
         pixel.setY(point.y()*2*mScale + center.y());//Задаем координаты точки
         painter.drawPoint(pixel);// Рисуем точку

        if (mFunction == Bernuli) {
            pixel.setX(-point.x()*2*mScale + center.x()); //Задаем координаты точки
            pixel.setY(-point.y()*2*mScale + center.y());//Задаем координаты точк
            painter.drawPoint(pixel);// Рисуем точку
       /*if( int(floor( mAValue)) %2==0){
            pixel.setX(-point.x()*2*mScale +center.x()); //Задаем координаты точки
            pixel.setY(point.y()*2*mScale + center.y());//Задаем координаты точк
            painter.drawPoint(pixel);// Рисуем точку
            pixel.setX(point.x()*2*mScale +center.x()); //Задаем координаты точки
            pixel.setY(-point.y()*2*mScale + center.y());//Задаем координаты точк
            painter.drawPoint(pixel);// Рисуем точку
        }*/
}

     }
 }

