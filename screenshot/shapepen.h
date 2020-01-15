#ifndef SHAPEPEN_H
#define SHAPEPEN_H
#include "shape.h"
#include <QPoint>
class ShapePen : public Shape
{
public:
    explicit ShapePen();
    ~ShapePen();

    virtual ShapeType getType() override  {return ARROW; }

protected:
    virtual void drawShape(QPainter *) override;
    virtual void mouseDoubleClick(QMouseEvent *) override;
    virtual void mousePressEvent(QMouseEvent *) override;
    virtual void mouseMoveEvent(QMouseEvent *) override;
    virtual void mouseReleaseEvent(QMouseEvent *) override;
    virtual QRectF boundingBox() override;

private:
    QPoint m_start_pos;
    QPoint m_end_pos;
    QVector <QPoint> m_point_list;
    bool m_is_pressed;
};

#endif // SHAPEPEN_H
