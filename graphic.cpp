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
QPointF Graphic::compute_circle(float t)
{
    float cos_t = cos(t);
    float sin_t = sin(t);
    float x=cos_t;
    float y = sin_t;
    return QPointF(x,y);
}
QPointF Graphic::compute_clover(float t)
{
    float cos_t = cos(t);
    float sin_t = sin(t);
    float x=cos(2*t)*cos_t;
    float y = cos(2*t)*sin_t;
    return QPointF(x,y);
}
QPointF Graphic::compute_Archimedes(float t)
{
    float cos_t = cos(t);
    float sin_t = sin(t);
    float x=t*cos_t;
    float y =t*sin_t;
    return QPointF(x,y);
}
QPointF Graphic::compute_snail(float t)
{
    float cos_t = cos(t);
    float sin_t = sin(t);
    float x=(1-2*cos_t)*cos_t;
    float y =(1-2*cos_t)*sin_t;
    return QPointF(x,y);
}

void Graphic::on_function_change(){

    switch(mFunction){
        case circle:
        mScale= 40;
        mStepCount =1024;
        mIntervalLength=M_PI*2*50;
        break;
        case clover:
        mScale = 40;
        mStepCount =1024;
        mIntervalLength=M_PI*2*50;
        break;
    case Archimedes:
        mScale = 40;
        mStepCount =2048;
        mIntervalLength=M_PI*2*50;
        break;
    case snail:
        mScale = 40;
        mStepCount =1024;
        mIntervalLength=M_PI*2*50;
        break;
    }

}
QPointF Graphic::compute_function(float t){
switch(mFunction){
case circle:
    return compute_circle(t);
    break;
case clover:
    return compute_clover(t);
    break;
case Archimedes:
    return compute_Archimedes(t);
    break;
case snail:
    return compute_snail(t);
    break;
default:
    break;

}
return QPointF(0,0);

}
 void Graphic::paintEvent(QPaintEvent *event)
 {
     QPainter painter(this);

     painter.setBrush(mBackgroundColor);
     painter.setRenderHint(QPainter::Antialiasing, true);
     painter.drawRect(this->rect());
     QPoint center = this->rect().center();





     float step = mIntervalLength/50 / mStepCount;
     for(float i=0; i<= mIntervalLength/50; i+=step ){
         QPointF point = compute_function(i);

         QPoint pixel;
         pixel.setX(point.x()*2*mScale +center.x());
         pixel.setY(point.y()*2*mScale + center.y());

         painter.drawPoint(pixel);

     }
 }

