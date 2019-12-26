#include "shaperect.h"
#include <QPainter>
#include <QDebug>
ShapeRect::ShapeRect():
    ShapeRect(QRect(0, 0, 0, 0))
{

}

ShapeRect::ShapeRect(const QRect &rect):
    Shape(this),
    m_is_pressed(false),
    m_start_pos(rect.topLeft()),
    m_end_pos(rect.bottomRight())
{

}


ShapeRect::~ShapeRect()
{

}

QRectF ShapeRect::boundingBox()
{
    return  getDefaultBoundingBox(m_start_pos, m_end_pos);
}

void ShapeRect::drawShape(QPainter * painter)
{
    painter->drawRect(QRect(m_start_pos, m_end_pos));
}

void ShapeRect::mouseDoubleClick(QMouseEvent * e)
{

}

void ShapeRect::mousePressEvent(QMouseEvent * e)
{
    if(e->button() == Qt::LeftButton && m_algorithm.pointInRect(m_paint_range, e->pos()))
    {
        m_is_pressed = true;
        m_start_pos = m_end_pos = e->pos();
    }
}

void ShapeRect::mouseMoveEvent(QMouseEvent * e)
{
    if(m_is_pressed)
        m_end_pos =  m_algorithm.pointLimitRect(m_paint_range, e->pos());
}

void ShapeRect::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        m_is_pressed = false;
    }
}
