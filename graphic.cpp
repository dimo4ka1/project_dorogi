#include "graphic.h"
#include<QPainter>
#include<QPaintEvent>
#include"math.h"
#include <QPixmap>
#include <QPen>
#include <sstream>
#include <QtScript/QScriptEngine>
#include <QtScript/QscriptValue>
#include <QtScript/QScriptValueList>
#include <QString>


#include <iostream>
#include <fstream>
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

QPointF Graphic::compute_calculate(double t, QString CodeFunction) // Функция из калькулятора
{
    QScriptEngine engine;
    QScriptValue scriptFun;

    // Текст в формулу
    engine.evaluate("function fun(t)\n {\n var r=0;\n r="+CodeFunction+"\n return r;\n}\n");
    scriptFun = engine.globalObject().property("fun");
    // r - длина радиус-вектора при угле t
    double r = scriptFun.call(QScriptValue(), QScriptValueList() << t).toNumber();
    // Переводим r в параметрический вид x(t), y(t)
    float x = r * cos(t);
    float y = r * sin(t);
    return QPointF(x,y);
}
QPointF Graphic::compute_circle(double t) // Окружность
{
    float cos_t = cos(t);
    float sin_t = sin(t);
    float x=cos_t;
    float y = sin_t;
    return QPointF(x,y);
}

QPointF Graphic::compute_clover(double t, double a) // Полярная роза
{
    float cos_t = cos(t);
    float sin_t = sin(t);
    float x=cos(a*t)*cos_t;
    float y = cos(a*t)*sin_t;
    return QPointF(x,y);
}
QPointF Graphic::compute_Archimedes(double t, double a) // Спираль Архемеда
{
    float cos_t = cos(t);
    float sin_t = sin(t);
    float x=(t+a)*cos_t;
    float y =(t+a)*sin_t;
    return QPointF(x,y);
}
QPointF Graphic::compute_snail(double t,double a) // Кардиоида
{
    float cos_t = cos(t);
    float sin_t = sin(t);
    float x=(1+a*cos_t)*cos_t;
    float y =(1+a*cos_t)*sin_t;
    return QPointF(x,y);
}

QPointF Graphic::compute_hyperbolicSpiral(double t, double a) // Гиперболическая спираль
{

    float cos_t = cos(t);
    float sin_t = sin(t);
    float x=(a/t)*cos_t;
    float y =(a/t)*sin_t;
    return QPointF(x,y);
}

QPointF Graphic::compute_Bernulli(double t,double a) // Лемниската Бернулли
{
    float x = (cos(2*t + a*M_PI_2) >= 0) ? sqrt((cos(2*t + a*M_PI_2)))*cos(t) : 0;
    float y = (cos(2*t + a*M_PI_2) >= 0) ? sqrt((cos(2*t + a*M_PI_2)))*sin(t) : 0;
    return QPointF(x,y);
}
QPointF Graphic::compute_Astroid(double t, double a) // Астроида
{
    float cos_t = cos(t);
    float sin_t = sin(t);
    float x = a * cos_t * cos_t * cos_t;
    float y = a * sin_t * sin_t * sin_t;
    return QPointF (x, y);
}
QPointF Graphic::compute_LogSpiral(double t, double a) // Логарифмическая спираль
{
    float cos_t = cos(t);
    float sin_t = sin(t);
    float x = exp(a*t) * cos_t;
    float y = exp(a*t) * sin_t;
    return QPointF (x, y);
}


double Graphic::rho(double t) { // Длина радиус-вектора функции
    if (cos(t)) return compute_function(t).x()/cos(t);
    return  compute_function(t).y()/sin(t);
}

QString Graphic::string(int a){
    QString b;
    if(a<0) {b += "-"; a *=-1;}
    if(a>=10){ int c= a/10; b+= c +(int)'0';}
    a=a%10;
    b+=a +(int)'0';

    return b;
}

void Graphic::on_function_change() // Выбор графика
{
    switch(mFunction) {
    case circle:
        mScale= 80;
         mAValue = 1;
        mStepCount = 1024;
        mIntervalLength=M_PI*2*50;
        break;
    case clover:
        mScale = 40;
        mStepCount = 32 * 1024;
        mAValue = 2;
        mIntervalLength = 2 * M_PI * 50;
        break;
    case Archimedes:
        mScale = 40;
        mStepCount = 2 * 1024;
        mAValue = 1;
        mIntervalLength = 2 * M_PI * 50;
        break;
    case snail:
        mScale = 40;
        mStepCount = 1024;
        mAValue = 2;
        mIntervalLength = 2 * M_PI * 50;
        break;
    case hyperbolicSpiral:
        mScale = 40;
        mStepCount = 2 * 1024;
        mIntervalLength = 2 * M_PI * 50;
        mAValue = 1;
        break;
    case Bernulli:
        mScale = 40;
        mStepCount = 2 * 1024;
        mIntervalLength = 2 * M_PI * 50;
        mAValue = 0;
        break;
    case calculate:
        mScale = 40;
        mStepCount = 2 * 1024;
        mIntervalLength = 2 * M_PI * 50;
        mAValue = 1;
        break;
    case Astroid:
        mScale = 40;
        mStepCount = 2 * 1024;
        mIntervalLength = 2 * M_PI * 50;
        mAValue = 1;
        break;
    case LogSpiral:
        mScale = 180;
        mStepCount = 2 * 1024;
        mIntervalLength = 2 * M_PI * 50;
        mAValue = -1;
        break;
    default:
        break;
    }

}
QPointF Graphic::compute_function(double t) // Вызов выбранной функции
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
    case calculate:
        return  compute_calculate(t, mCodeFunction);
        break;
    case Astroid:
        return  compute_Astroid(t,mAValue);
        break;
    case LogSpiral:
        return compute_LogSpiral(t, mAValue);
    default:
        break;
}
return QPointF(0,0);

}


void Graphic::paintEvent(QPaintEvent *event) // Подготовка к построению графика
{
    QPainter painter(this);

    painter.setBrush(mBackgroundColor);
    painter.setPen(mShapeColor);

    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.drawRect(this->rect());
    QPoint center = this->rect().center();

    QPointF prevPoint = compute_function (0);
    QPoint prevPixel;
    prevPixel.setX(prevPoint.x()*2*mScale + center.x());
    prevPixel.setY(prevPoint.y()*2*mScale + center.y());

    QPen pen4;
    pen4.setWidth(3);
    pen4.setColor(Qt::black);
    painter.setPen(pen4);
    painter.drawPoint(mPos1);
    painter.drawPoint(mPos2);
for(int i=1; i<=NumberOfLine; i++ ){
    tmassPos[i][0]=massPos[i][0];
tmassPos[i][1]=massPos[i][1];
}
    tAValue=mAValue;
    tscale=mScale;
//рисуем прямые
    painter.setPen(Qt::black);
    if(mLine==true){
       massPos[NumberOfLine][0] = mPos1;
       massPos[NumberOfLine][1] = mPos2;
       for(int i=1; i<=NumberOfLine; i++ ){

     int a1 = massPos[i][1].x() - massPos[i][0].x();
     int a2 = massPos[i][1].y() - massPos[i][0].y();

     painter.drawLine(QPointF(massPos[i][0].x()+a1*1000,massPos[i][0].y()+a2*1000),massPos[i][1]);
     painter.drawLine(massPos[i][0],massPos[i][1]);
     painter.drawLine(QPointF(massPos[i][0].x()-a1*1000,massPos[i][0].y()-a2*1000),massPos[i][1]);
    }
}
    // Координатные оси
    painter.setPen(Qt::lightGray);
    painter.drawLine(QPoint(center.x(), 0), QPoint(center.x(), 2*center.y())); // Ox
    int o=-24;
    for (double i = 0; i <= 2*center.x(); i+=20) {
        painter.drawLine(QPoint(i, 2+center.y()), QPoint(i, -2+center.y()));
     painter.drawText(QPoint(i+2, -2+center.y()), string(o));
                o++;
    }
    o=14;
    painter.drawLine(QPoint(0, center.y()), QPoint(2*center.x(), center.y())); // Oy
    for (float i = 0; i <= 2*center.x(); i+=20) {
        painter.drawLine(QPoint(2+center.x(), i), QPoint(-2+center.x(), i));
        if(o!=0)painter.drawText(QPoint(2+center.x(), i+2), string(o));
        o--;
    }

    double maxV = 0; // Угол, при котором rho максимальное
    double minV = 0; // Угол, при котором rho минимальное
    int q1=0; // Количество одинаковых максимумов
    int q2=0; // Количество одинаковых минимумов
    vector <double> v; // Список углов, при которых r->inf

    double step = mIntervalLength/100 / mStepCount;
    for(double i=0; i<= mIntervalLength/50; i+=step) { // Построение графика
        painter.setPen(Qt::black);

        // Объявляем точку и задаем ее координаты
        QPointF point = compute_function(i);
        QPoint pixel;
        pixel.setX(point.x()*2*mScale + center.x());
        pixel.setY(-point.y()*2*mScale + center.y());

        if(rho(i)>rho(maxV)){
           maxV=i;
           q1=0;
        }
        if(rho(i)<rho(minV)){  minV=i;q2=0;}
        if(rho(i)==rho(maxV)){q1++;}
        if(rho(i)==rho(minV)){q2++;}

        if (isinf(rho(i))) {
            v.push_back(i);
        }
        // Перебираем точки и проверяем их на экстремум
        double x0 = point.x();
        double y0 = point.y();
        QPointF point1 = compute_function(i+step*10);
        double x1 = point1.x();
        double y1 = point1.y();
        QPointF point2 = compute_function(i-step*10);
        double x2 = point2.x();
        double y2 = point2.y();

        if ((x0 > x1 && x0 > x2) || (x0 < x1 && x0 < x2) || (y0 > y1 && y0 > y2) || (y0 < y1 && y0 < y2)) {
            QPen pen1;
            pen1.setWidth(5);
            pen1.setColor(Qt::red);
            painter.setPen(pen1);
            painter.drawPoint(pixel);
        } else {
            painter.drawLine(pixel, prevPixel);
        }
        prevPixel = pixel;
     }

    if(v.empty() and q1<2 and q2<2){
        v.push_back(minV);
        if(minV!=maxV){v.push_back(maxV);}
    }
    // Поиск асимптот
    if ((mFunction == hyperbolicSpiral || mFunction == calculate) && mAsymptote==true) {

        for (auto c:v) {
                double b= 0;double k=0;double  bv = 0;
                // Вертикальная асимптота
                if (fabs(c - M_PI_2)<h || fabs(c - 3*M_PI_2)<h) {
                    if (!isinf(rho(c)*cos(c))) {
                        bv = rho(c+h)*cos(c+h);
                        painter.setPen(Qt::darkGreen);
                        painter.drawLine(QPoint(bv*2*mScale+ center.x(),0), QPoint(bv*2*mScale+ center.x(), center.y()*2)); // Асимптота x=bv
                    } else if (!isinf(rho(c)*sin(c))) {
                        bv = rho(c+h)*sin(c+h);
                        painter.setPen(Qt::darkGreen);
                        painter.drawLine(QPoint(bv*2*mScale+ center.x(),0), QPoint(bv*2*mScale+ center.x(), center.y()*2)); // Асимптота x=bv
                    }
                }
                // Горизонтальная асимптота
                else if (fabs(tan(c)) < h) {
                    if (!isnan(rho(c)*sin(c))) {
                        if (b) {
                            b = rho(c)*sin(c);
                            painter.setPen(Qt::darkGreen);
                            painter.drawLine(QPoint(0,-b*2*mScale+center.y()), QPoint(center.x()*2, center.y()-b*2*mScale)); // Асимптота y=b
                        }
                    } else if ((rho(c+h)*sin(c+h))-(rho(c-h)*sin(c-h)) < h) {
                        b = rho(c+h)*sin(c+h);
                        if (b)  {
                            painter.setPen(Qt::darkGreen);
                            painter.drawLine(QPoint(0,-b*2*mScale+center.y()), QPoint(center.x()*2, center.y()-b*2*mScale)); // Асимптота y=b
                        }
                    }
                }

                // Наклонная асимптота
                else if (!isnan(tan(c)) && !isinf(tan(c) )) {
                    k=tan(c);
                    if (c==maxV) {b = rho(c+h)*sin(c+h) - k*rho(c+h)*cos(c+h);}
                    else if (c==minV){ b = rho(c)*sin(c) - k*rho(c-h)*cos(c-h);}
                    else {b = rho(c+h)*sin(c+h)-k*rho(c+h)*cos(c+h);}
                    painter.setPen(Qt::darkGreen);
                    painter.drawLine(QPoint(0,-b*2+center.y()), QPoint(center.x()*2, center.y()-(k*center.x()+b*2))); // Асимптота y=kx+b
                    break;
               }
            }
        }
}
