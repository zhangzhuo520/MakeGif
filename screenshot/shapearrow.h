#ifndef SHAPEARROW_H
#define SHAPEARROW_H
#include "shape.h"
#include <QPoint>
class ShapeArrow : public Shape
{
public:
    ShapeArrow();
    ~ShapeArrow();
    virtual ShapeType getType() {return ARROW; }

protected:
    virtual void drawShape(QPainter *);
    virtual void mouseDoubleClick(QMouseEvent *);
    virtual void mousePressEvent(QMouseEvent *);
    virtual void mouseMoveEvent(QMouseEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *);
    virtual QRectF boundingBox();

private:
    bool m_drawing;
    QPoint m_start_point;
    QPoint m_end_point;
};

#endif // SHAPEARROW_H
