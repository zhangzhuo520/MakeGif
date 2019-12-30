#ifndef SHAPECIRCLE_H
#define SHAPECIRCLE_H
#include "shape.h"

class ShapeCircle : public Shape
{
public:
    ShapeCircle();
    explicit ShapeCircle(const QRect & rect);
    ~ShapeCircle();

    virtual ShapeType getType() {return CIRCLE; }
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

#endif // SHAPECIRCLE_H
