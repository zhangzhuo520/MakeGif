#include "ShapePen.h"
#include <QPainter>
#include <QDebug>
ShapePen::ShapePen():
    Shape(this),
    m_start_pos(0, 0),
    m_end_pos(0, 0),
    m_is_pressed(false)
{

}

ShapePen::~ShapePen()
{

}

QRectF ShapePen::boundingBox()
{
    return QRect(0, 0, 0, 0);
}

void ShapePen::drawShape(QPainter * painter)
{
    if(m_is_pressed)
        painter->drawLine(m_start_pos, m_end_pos);
}

void ShapePen::mouseDoubleClick(QMouseEvent * e)
{

}

void ShapePen::mousePressEvent(QMouseEvent * e)
{
    if(e->button() == Qt::LeftButton && m_algorithm.pointInRect(m_paint_range, e->pos()))
    {
        m_start_pos = e->pos();
    }
}

void ShapePen::mouseMoveEvent(QMouseEvent * e)
{
    if(m_is_pressed)
        m_end_pos =  m_algorithm.pointLimitRect(m_paint_range, e->pos());
}

void ShapePen::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        m_is_pressed = false;
    }
}
