#ifndef SHAPE_H
#define SHAPE_H
#include <QList>
#include <QColor>
#include <QBrush>
class QPainter;
class QMouseEvent;
class Shape
{
    typedef QList <Shape *> ShapeList;
    typedef QList <Shape *>::iterator ShapeIterator;
public:
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
    ShapeList getShapeList() const {return m_shape_list;}

    virtual void drawShape(QPainter *) = 0;
    virtual void mousePressEvent(QMouseEvent *) {}
    virtual void mouseReleaseEvent(QMouseEvent *) {}
    virtual void mouseMoveEvent(QMouseEvent *){}
    virtual void mouseDoubleClick(QMouseEvent *) {}

   virtual ShapeType getType() {return NUNE;}

   QColor m_shap_color;
   QBrush m_shape_brush;
private:
   QList <Shape *> m_shape_list;
};

#endif // SHAPE_H
