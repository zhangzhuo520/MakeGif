#ifndef SHAPE_H
#define SHAPE_H
#include <QList>
#include <QColor>
#include <QBrush>
#include "algorithm.h"
class QPainter;
class QMouseEvent;
class Shape
{
public:
    typedef QList <Shape *> ShapeList;
    typedef QList <Shape *>::iterator ShapeIterator;
    enum ShapeType
    {
        LINE,
        POINT,
        ARROW,
        CIRCLE,
        RECT,
        NUNE
    };

    explicit Shape(Shape *);
    virtual ~Shape() {}

    ShapeList static getShapeList()  {return m_shape_list;}
    QRect getDefaultBoundingBox(const QPoint & start, const QPoint & end);
    void setPaintRange(const QRect& range);

    virtual QRectF boundingBox() = 0;
    virtual void drawShape(QPainter *) = 0;
    virtual void mousePressEvent(QMouseEvent *) = 0;
    virtual void mouseReleaseEvent(QMouseEvent *) = 0;
    virtual void mouseMoveEvent(QMouseEvent *)= 0;
    virtual void mouseDoubleClick(QMouseEvent *) = 0;

   virtual ShapeType getType() {return NUNE;}

   QColor m_shap_color;
   QBrush m_shape_brush;
   QRect m_paint_range;
   ShapeAlgorithm m_algorithm;
private:
   static ShapeList m_shape_list;

};

#endif // SHAPE_H
