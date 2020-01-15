#ifndef SHAPE_H
#define SHAPE_H
#include <QList>
#include <QColor>
#include <QBrush>
#include "abstractshape.h"
#include "algorithm.h"
class QPainter;
class QMouseEvent;
class AbstrcatShape;

//template <class BaseType = AbstrcatShape>
class Shape
{
public:
    enum ShapeType
    {
        LINE,
        POINT,
        ARROW,
        CIRCLE,
        RECT,
        TEXT,
        MOSAIC,
        NONE
    };

    explicit Shape(Shape *);
    virtual ~Shape() {}

     QList <Shape *> static shapeList()  {return m_shape_list;}
    QRect getDefaultBoundingBox(const QPoint & start, const QPoint & end);
    void setPaintRange(const QRect& range);

    virtual QRectF boundingBox() = 0;
    virtual void drawShape(QPainter *) = 0;
    virtual void mousePressEvent(QMouseEvent *) = 0;
    virtual void mouseReleaseEvent(QMouseEvent *) = 0;
    virtual void mouseMoveEvent(QMouseEvent *)= 0;
    virtual void mouseDoubleClick(QMouseEvent *) = 0;

   virtual ShapeType getType() {return NONE;}

protected:
    QColor m_shap_color;
    QBrush m_shape_brush;
    QRect m_paint_range;
    ShapeAlgorithm m_algorithm;
private:
    static  QList <Shape *> m_shape_list;
};

//typedef  Shape<AbstractShape>   Shape;

#endif // SHAPE_H
