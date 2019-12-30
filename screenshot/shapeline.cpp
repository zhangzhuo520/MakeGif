#include "shapeline.h"
#include <QPainter>

ShapeLine::ShapeLine():
    ShapeLine(QLine(0, 0, 0, 0))
{

}

ShapeLine::ShapeLine(const QLine &line):
    Shape(this),
    m_is_pressed(false),
    m_start_pos(line.p1()),
    m_end_pos(line.p2())
{

}


ShapeLine::~ShapeLine()
{

}

QRectF ShapeLine::boundingBox()
{
    return  getDefaultBoundingBox(m_start_pos, m_end_pos);
}

void ShapeLine::drawShape(QPainter * painter)
{
    painter->drawLine(m_start_pos, m_end_pos);
}

void ShapeLine::mouseDoubleClick(QMouseEvent * e)
{

}

void ShapeLine::mousePressEvent(QMouseEvent * e)
{
    if(e->button() == Qt::LeftButton && m_algorithm.pointInRect(m_paint_range, e->pos()))
    {
        m_is_pressed = true;
        m_start_pos = m_end_pos = e->pos();
    }
}

void ShapeLine::mouseMoveEvent(QMouseEvent * e)
{
    if(m_is_pressed)
        m_end_pos =  m_algorithm.pointLimitRect(m_paint_range, e->pos());
}

void ShapeLine::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        m_is_pressed = false;
    }
}
