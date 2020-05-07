#include "graphic.h"
#include<QPainter>
#include<QPaintEvent>
#include"math.h"
#include <QPixmap>
#include <QPen>


#include <QtScript/QScriptEngine>
#include <QtScript/QscriptValue>
#include <QtScript/QScriptValueList>
#include <QString>

//Для проверки экстремумов
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

QPointF Graphic::compute_calculate(float t, QString CodeFunction) // Функция из калькулятора
{
    // Необходимые переменные
    double r;
    QScriptEngine engine;
    QScriptValue scriptFun;

    //подготовка движка QtScript
    engine.evaluate("function fun(t)\n {\n var r=0;\n r="+CodeFunction+"\n return r;\n}\n");
    scriptFun = engine.globalObject().property("fun");
    // Вычисление значения r в t
    r = scriptFun.call(QScriptValue(), QScriptValueList() << t).toNumber();
    // Проверка
    cout << r << endl;

    float x = r * cos(t);
    float y = r * sin(t);
    return QPointF(x,y);
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

QPointF Graphic::compute_hyperbolicSpiral(float t, float a) // Гиперболическая спираль
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
QPointF Graphic::compute_Astroid(float t, float a)
{
    float cos_t = cos(t);
    float sin_t = sin(t);
    float x = a * cos_t * cos_t * cos_t;
    float y = a * sin_t * sin_t * sin_t;
    return QPointF (x, y);
}
QPointF Graphic::compute_LogSpiral(float t, float a)
{
    float cos_t = cos(t);
    float sin_t = sin(t);
    float x = exp(a*t) * cos_t;
    float y = exp(a*t) * sin_t;
    return QPointF (x, y);
}


double Graphic::rho1(double t) {
    return 9/(4-5*cos(t));
}

double Graphic::rho2(double t) {
    return (3*sin(t)*cos(t))/(pow(sin(t), 3)+pow(cos(t), 3));
}

double Graphic::rho3(double t) {
    return 1 + 2*cos(t);
}

double Graphic::rho(double t) {
    return 2/t;
}

int Graphic::asimtote(int argc, const char * argv[]) {
    vector <double> v;
    double t;
    double maxV = 0, minV = 0;
    //Создаем список всех углов при которых r->inf
    for (t = 0; t < 2*M_PI; t += 2*M_PI/102400) {
        maxV = (rho(t) > rho(maxV))?t:maxV;
        minV = (rho(t) < rho(minV))?t:minV;
        if (isinf(rho(t))) {
            //cout << t << endl;
            v.push_back(t);
        }
    }
    if (v.empty()) {
        //cout << "MAXV = " << maxV << endl;
        //cout << "MINV = " << minV << endl;
        v.push_back(maxV);
        v.push_back(minV);
    }
    double k;
    double b;
    for (auto c:v) {
        cout << c << endl;
        if (fabs(tan(c)) < h) {
            //cout << tan(c) << endl;
            if (!isnan(rho(c)*sin(c))) {
                b = rho(c)*sin(c);
                if (b)  cout << "y = " << b << endl;
            } else if ((rho(c+h)*sin(c+h))-(rho(c-h)*sin(c-h)) < h) {
                b = rho(c+h)*sin(c+h);
                if (b)  cout << "y = " << b << endl;
            }
        } else if (!isnan(tan(c)) && !isinf(tan(c))) {
            if (c==maxV) b = rho(c+h)*sin(c+h) - tan(c)*rho(c+h)*cos(c+h);
            else if (c==minV) b = rho(c)*sin(c) - tan(c)*rho(c-h)*cos(c-h);
            else b = rho(c+h)*sin(c+h)-tan(c)*rho(c+h)*cos(c+h);
            cout << "y = " << tan(c) << "x + " << b << endl;
        }
    }

    return 0;
}

void Graphic::on_function_change() // Присваивание к mFunction выбранного графика
{
    switch(mFunction) {
    case circle:
        mScale= 80;
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


void Graphic::paintEvent(QPaintEvent *event) // Рисуем график
{
    QPainter painter(this);

    painter.setBrush(mBackgroundColor); //  цвет фона
    painter.setPen(mShapeColor); // цвет рисунка

    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.drawRect(this->rect());
    QPoint center = this->rect().center(); // центр холста

    QPointF prevPoint = compute_function (0); // задаем начальную точку
    QPoint prevPixel;
    prevPixel.setX(prevPoint.x()*2*mScale + center.x());
    prevPixel.setY(prevPoint.y()*2*mScale + center.y());

    QPen pen4;
    pen4.setWidth(3);
    pen4.setColor(Qt::black);
    painter.setPen(pen4);
    painter.drawPoint(mPos1);
    painter.drawPoint(mPos2);
    //Рисуем линию

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
    for (float i = 0; i <= 2*center.x(); i+=20) {
        painter.drawLine(QPoint(i, 2+center.y()), QPoint(i, -2+center.y()));
    }
    painter.drawLine(QPoint(0, center.y()), QPoint(2*center.x(), center.y())); // Oy
    for (float i = 0; i <= 2*center.x(); i+=20) {
        painter.drawLine(QPoint(2+center.x(), i), QPoint(-2+center.x(), i));
    }

    float step = mIntervalLength/50 / mStepCount;
    for(float i=0; i<= mIntervalLength/50; i+=step) {
        painter.setPen(Qt::black);

        // Объявляем точку и задаем ее координаты
        QPointF point = compute_function(i);
        QPoint pixel;
        pixel.setX(point.x()*2*mScale + center.x());
        pixel.setY(-point.y()*2*mScale + center.y());

        //Асимптоты гиперболоидной спирали
        if(mFunction==hyperbolicSpiral and i==step){
        painter.setPen(Qt::green);
        QPointF point3 = compute_function(i);
        for (float k = 0; k <= 2*center.x(); k+=40) {
             painter.drawLine(QPoint(k,(-point3.y()*2*mScale + center.y())), QPoint(k+30,(-point3.y()*2*mScale + center.y()))); //рисует асимптоту штрих-пунтиром

        }
        }
        // Нахождение экстремумов (неудачная попытка сравнения соседних точек, пока неизвестно, почему)
        float x0 = point.x();
        float y0 = point.y();
        QPointF point1 = compute_function(i+step*10);
        float x1 = point1.x();
        float y1 = point1.y();
        QPointF point2 = compute_function(i-step*10);
        float x2 = point2.x();
        float y2 = point2.y();
        if ((x0 > x1 && x0 > x2) || (x0 < x1 && x0 < x2) || (y0 > y1 && y0 > y2) || (y0 < y1 && y0 < y2)) {
            //Создаем участок шириной 3 красного цвета для сброса скорости
            QPen pen1;
            pen1.setWidth(5);
            pen1.setColor(Qt::red);
            painter.setPen(pen1);
            painter.drawPoint(pixel);
        } else {
            // Рисование графика
            painter.drawLine(pixel, prevPixel); // Соединяем точки
        }
        prevPixel = pixel; //задаем предыдущую точку
    }
}

