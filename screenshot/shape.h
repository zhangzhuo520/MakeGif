#ifndef SHAPE_H
#define SHAPE_H
#include <QList>
#include <QColor>
#include <QBrush>
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

    virtual QRectF boundingBox() = 0;

    virtual void drawShape(QPainter *) = 0;
    virtual void mousePressEvent(QMouseEvent *) {}
    virtual void mouseReleaseEvent(QMouseEvent *) {}
    virtual void mouseMoveEvent(QMouseEvent *){}
    virtual void mouseDoubleClick(QMouseEvent *) {}

   virtual ShapeType getType() {return NUNE;}

   QColor m_shap_color;
   QBrush m_shape_brush;
private:
   static ShapeList m_shape_list;
};

#endif // SHAPE_H
