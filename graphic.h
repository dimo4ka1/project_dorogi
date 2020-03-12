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

    enum Functions{circle, clover,Archimedes,snail, hyperbolicSpiral, Bernulli};

    void setBackgroundColor(QColor color){ mBackgroundColor = color; } //Функция, которая объявляет цвет
    QColor BackgroundColor() const { return mBackgroundColor; }

    void setFunction(Functions function) { mFunction= function; on_function_change(); } // Обьявляю функцию, которая присваетвает переменнной mFunction значение из списка.
    Functions function () const { return mFunction; }                             //Потом это понадобиться

    void setScale(float scale) { mScale= scale; repaint(); } //Функция, которая присваевает размер введенный в окошке
    float scale  () const { return mScale; }

    void setIntervalLength(float intervalLength) { mIntervalLength= intervalLength; repaint(); } //Функция, которая присваевает интервал углу из окна
    float intervalLength () const {  return mIntervalLength; }

    void setAValue(float aValue) { mAValue = aValue; repaint(); } //Функция, которая присваевает интервал углу из окна
    float aValue () const { return mAValue; }

    void setStepCount (int count) { mStepCount = count; repaint(); }
    int stepCount () const { return mStepCount; }

protected:
        void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

signals:


private:
       QPointF compute_function(float t);                  // Объявляю главную функцию
       QPointF compute_circle(float t);                    // Круг
       QPointF compute_clover(float t, float a);           // Полярная роза
       QPointF compute_Archimedes(float t, float a);       // Спираль Архимеда
       QPointF compute_snail(float t, float a);            // Кардиоида
       QPointF compute_hyperbolicSpiral(float t, float a); // Гиперболическая спираль
       QPointF compute_Bernulli(float t, float a);         // Лемниската Бернулли
       QPointF compute_FEdit(float t, float a);            // Введенная функция

       void on_function_change(); // Объявляю функцию, отвечающую за размер, угол, кол-во точек на графике
       QColor mBackgroundColor; // Цвет
       QColor mShapeColor;
       Functions mFunction; // Переменная, отвечающая за тип графика, ключевая часть програмы

       float mScale;  // Размер
       float mIntervalLength; // Интервал угла
       int mStepCount; // Количество точек на графике
       float mAValue; // Коэффициент a
};

#endif // GRAPHIC_H
