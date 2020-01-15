#include "shapemosaic.h"
#include <QPainter>
#include <QDebug>
shapeMosaic::shapeMosaic():
    Shape(this),
    m_start_pos(0, 0),
    m_end_pos(0, 0),
    m_is_pressed(false)
{

}

shapeMosaic::~shapeMosaic()
{

}

QRectF shapeMosaic::boundingBox()
{
    return QRect(0, 0, 0, 0);
}

void shapeMosaic::drawShape(QPainter * painter)
{
    if(m_is_pressed)
    {
       QPen pen;

       pen.setWidth(9);
       pen.setColor(QColor(0, 255, 255, 50));
        painter->setPen(pen);
        painter->drawLine(m_start_pos, m_end_pos);
        m_start_pos = m_end_pos;
        m_point_list.append(m_start_pos);
    }
}

void shapeMosaic::mouseDoubleClick(QMouseEvent * e)
{

}

void shapeMosaic::mousePressEvent(QMouseEvent * e)
{
    if(e->button() == Qt::LeftButton && m_algorithm.pointInRect(m_paint_range, e->pos()))
    {
        m_is_pressed = true;
        m_start_pos = m_end_pos = e->pos();
    }
}

void shapeMosaic::mouseMoveEvent(QMouseEvent * e)
{
    if(m_is_pressed)
        m_end_pos =  m_algorithm.pointLimitRect(m_paint_range, e->pos());
}

void shapeMosaic::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        m_is_pressed = false;
    }
}
