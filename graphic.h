#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <QWidget>
#include <QColor>
class Graphic : public QWidget
{
    Q_OBJECT
public:
    explicit Graphic(QWidget *parent = 0);

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

    enum Functions{circle, clover,Archimedes,snail};

    void setBackgroundColor(QColor color){ mBackgroundColor = color;}
        QColor BackgroundColor() const{ return mBackgroundColor;}

    void setFunction(Functions function){mFunction= function; on_function_change();}
        Functions function () const{return mFunction; }

    void setScale(float scale){mScale= scale; repaint();}
        float scale  () const{return mScale; }

    void setIntervalLength(float intervalLength){mIntervalLength= intervalLength; repaint();}
        float intervalLength () const{return mIntervalLength; }

protected:
        void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

signals:


private:
       QPointF compute_function(float t);
       QPointF compute_circle(float t);
       QPointF compute_clover(float t);
       QPointF compute_Archimedes(float t);
       QPointF compute_snail(float t);
       void on_function_change();
       QColor mBackgroundColor;
       Functions mFunction;

       float mScale;
       float mIntervalLength;
       int mStepCount;
};

#endif // GRAPHIC_H
