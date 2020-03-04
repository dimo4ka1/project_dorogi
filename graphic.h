#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <QWidget>
#include <QColor>
class Graphic : public QWidget // Я так назвал виджет, обычно это не на что не влияет
{
    Q_OBJECT
public:
    explicit Graphic(QWidget *parent = 0);

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

    enum Functions{circle, clover,Archimedes,snail, hyperbolicSpiral, Bernuli}; // enum -команда, позволяющая перечислить список констант. Functions - список переменных,в курсе это были Shape(как-то так).
                                                    //Список внутри скобок, это название графиков, его можно изменять.

    void setBackgroundColor(QColor color){ mBackgroundColor = color;} //Функция, которая объявляет цвет
        QColor BackgroundColor() const{ return mBackgroundColor;}

    void setFunction(Functions function){mFunction= function; on_function_change();} // Обьявляю функцию, которая присваетвает переменнной mFunction значение из списка.
        Functions function () const{return mFunction; }                             //Потом это понадобиться

    void setScale(float scale){mScale= scale; repaint();} //Функция, которая присваевает размер введенный в окошке
        float scale  () const{return mScale; }

    void setIntervalLength(float intervalLength){mIntervalLength= intervalLength; repaint();} //Функция, которая присваевает интервал углу из окна
        float intervalLength () const{return mIntervalLength; }

    void setAValue(float aValue){ mAValue = aValue; repaint(); } //Функция, которая присваевает интервал углу из окна
        float aValue () const{ return mAValue; }

protected:
        void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

signals:


private:
       QPointF compute_function(float t);//Объявляю главную функцию
       QPointF compute_circle(float t);//Объявляю функцию, отвечающую за параметрическое уравнение, данной фигуры
       QPointF compute_clover(float t, float a);//Объявляю функцию, отвечающую за параметрическое уравнение, данной фигуры
       QPointF compute_Archimedes(float t, float a);//Объявляю функцию, отвечающую за параметрическое уравнение, данной фигуры
       QPointF compute_snail(float t, float a);//Объявляю функцию, отвечающую за параметрическое уравнение, данной фигуры
       QPointF compute_hyperbolicSpiral(float t, float a);
       QPointF compute_Bernuli(float t, float a);
       void on_function_change();//Объявляю функцию, отвечающую за размер,угл, кол-во точек на графике
       QColor mBackgroundColor;// Цвет
       Functions mFunction;// переменная, отвечающая за тип графика, ключевая часть програмы

       float mScale;//размер
       float mIntervalLength;//интервал угла
       int mStepCount;//количество точек на графике
       float mAValue; //коэффициент a
};

#endif // GRAPHIC_H
