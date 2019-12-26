#ifndef SHAPERECT_H
#define SHAPERECT_H
#include "shape.h"
#include <QRect>
#include <QPointF>
class ShapeRect : public Shape
{
public:
    ShapeRect();
    explicit ShapeRect(const QRect & rect);
    ~ShapeRect();

    virtual ShapeType getType() {return RECT; }
    virtual QRectF boundingBox();

protected:
    virtual void drawShape(QPainter *);
    virtual void mouseDoubleClick(QMouseEvent *);
    virtual void mousePressEvent(QMouseEvent *);
    virtual void mouseMoveEvent(QMouseEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *);

private:
    bool m_is_pressed;
    QPoint m_start_pos;
    QPoint m_end_pos;
};

#endif // SHAPERECT_H
