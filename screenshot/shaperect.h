#ifndef SHAPERECT_H
#define SHAPERECT_H
#include "shape.h"
#include <QRect>
#include <QPointF>
class ShapeRect : public Shape
{
public:
    ShapeRect();
    explicit ShapeRect(const QRectF & rect);
    ShapeRect(const QPointF & topleft, const QPointF & bottomright);
    ShapeRect(const QPointF & topleft, double width, double height);
    ~ShapeRect();

    virtual ShapeType getType() {return RECT; }

    virtual void drawShape(QPainter *);

    virtual void mouseDoubleClick(QMouseEvent *);
    virtual void mousePressEvent(QMouseEvent *);
    virtual void mouseMoveEvent(QMouseEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *);

private:
    QRectF m_rect;
};

#endif // SHAPERECT_H
