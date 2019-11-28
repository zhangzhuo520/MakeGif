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
    enum ShapeType
    {
        LINE,
        POINT,
        ARROW,
        CIRCLE,
        RECT,
        NUNE
    };

    typedef QList <Shape *> ShapeList;
    typedef QList <Shape *>::iterator ShapeIterator;

    explicit Shape(Shape *);
    virtual ~Shape() {}
    ShapeList getShapeList() const {return m_shape_list;}

protected:
    virtual void drawShape(QPainter *) = 0;
    virtual void mousePressEvent(QMouseEvent *) = 0;
    virtual void mouseReleaseEvent(QMouseEvent *) = 0;
    virtual void mouseMoveEvent(QMouseEvent *) = 0;
    virtual void mouseDoubleClick(QMouseEvent *) = 0;

   virtual ShapeType getType() {return NUNE;}

   QColor m_shap_color;
   QBrush m_shape_brush;
private:
   QList <Shape *> m_shape_list;
};

#endif // SHAPE_H
