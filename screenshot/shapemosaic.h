#ifndef SHAPEMOSAIC_H
#define SHAPEMOSAIC_H
#include "shape.h"
#include <QPoint>

class shapeMosaic : public Shape
{
public:
    explicit shapeMosaic();
    ~shapeMosaic();

    virtual ShapeType getType() override  {return MOSAIC; }

protected:
    virtual void drawShape(QPainter *) ;
    virtual void mouseDoubleClick(QMouseEvent *) ;
    virtual void mousePressEvent(QMouseEvent *) ;
    virtual void mouseMoveEvent(QMouseEvent *) ;
    virtual void mouseReleaseEvent(QMouseEvent *) ;
    virtual QRectF boundingBox() override;

private:
    QPoint m_start_pos;
    QPoint m_end_pos;
    QVector <QPoint> m_point_list;
    bool m_is_pressed;
};

#endif // SHAPEMOSAIC_H
