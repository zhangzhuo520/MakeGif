#include "shapecircle.h"
#include <QPainter>

ShapeCircle::ShapeCircle():
    ShapeCircle(QRect(0, 0, 0, 0))
{

}

ShapeCircle::ShapeCircle(const QRect &rect):
    Shape(this),
    m_is_pressed(false),
    m_start_pos(rect.topLeft()),
    m_end_pos(rect.bottomRight())
{

}


ShapeCircle::~ShapeCircle()
{

}

QRectF ShapeCircle::boundingBox()
{
    return  getDefaultBoundingBox(m_start_pos, m_end_pos);
}

void ShapeCircle::drawShape(QPainter * painter)
{
    QRect rect(m_start_pos,m_end_pos);
    painter->drawEllipse(rect);
}

void ShapeCircle::mouseDoubleClick(QMouseEvent * e)
{

}

void ShapeCircle::mousePressEvent(QMouseEvent * e)
{
    if(e->button() == Qt::LeftButton && m_algorithm.pointInRect(m_paint_range, e->pos()))
    {
        m_is_pressed = true;
        m_start_pos = m_end_pos = e->pos();
    }
}

void ShapeCircle::mouseMoveEvent(QMouseEvent * e)
{
    if(m_is_pressed)
        m_end_pos =  m_algorithm.pointLimitRect(m_paint_range, e->pos());
}

void ShapeCircle::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        m_is_pressed = false;
    }
}
