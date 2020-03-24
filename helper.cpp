/*#include "graphic.cpp"
#include"graphic.h"
#include"math.h"
#include<QPainter>
#include<QPaintEvent>
void circle(){
 QPoint center = this->rect().center();
int stepCount= 256;
float intervalLength = 2 * M_PI;
float scale = 40;
float step = intervalLength / stepCount;
for(float i=0; i<= intervalLength; i+=step ){
    QPointF point = compute_graphic(i);

    QPoint pixel;
    pixel.setX(point.x()*scale +center.x());
    pixel.setY(point.y()*scale + center.y());

    painter.drawPoint(pixel);

}
}*/
