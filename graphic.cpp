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

        break;
        case clover:

        break;
    case Archimedes:

        break;
    case snail:

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



     int stepCount= 1024;
     float intervalLength = 2 * M_PI;
     float scale = 70;
     float step = intervalLength / stepCount;
     for(float i=0; i<= intervalLength; i+=step ){
         QPointF point = compute_function(i);

         QPoint pixel;
         pixel.setX(point.x()*scale +center.x());
         pixel.setY(point.y()*scale + center.y());

         painter.drawPoint(pixel);

     }
 }
