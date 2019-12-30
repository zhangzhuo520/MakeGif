#ifndef SHAPELINE_H
#define SHAPELINE_H
#include "shape.h"
#include <QLine>
class ShapeLine : public Shape
{
public:
    ShapeLine();
    explicit ShapeLine(const QLine & rect);
    ~ShapeLine();

    virtual ShapeType getType() {return LINE; }
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

#endif // SHAPELINE_H
