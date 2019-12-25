#include "shaperect.h"
#include <QPainter>
#include <QDebug>
ShapeRect::ShapeRect():
    Shape(this),
    m_rect(0, 0, 0, 0),
    m_is_pressed(false)
{

}

ShapeRect::ShapeRect(const QRectF &rect):
    Shape(this),
    m_rect(rect)
{

}

ShapeRect::ShapeRect(const QPointF &topleft, const QPointF &bottomright):
    Shape(this),
    m_rect(topleft, bottomright)
{

}

ShapeRect::ShapeRect(const QPointF &topleft, double width, double height):
    Shape(this),
    m_rect(topleft.x(), topleft.y(), width, height)
{

}

ShapeRect::~ShapeRect()
{

}

QRectF ShapeRect::boundingBox()
{
    qDebug() << "boundingBox : " << m_rect;
    return m_rect;
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
    m_is_pressed = true;
    m_rect.setTopLeft(e->pos());
    m_start_pos = m_end_pos = e->pos();
}

void ShapeRect::mouseMoveEvent(QMouseEvent * e)
{
    if(m_is_pressed)
    {
        m_end_pos = e->pos();
    }
}

void ShapeRect::mouseReleaseEvent(QMouseEvent *e)
{
    qDebug() <<  "mouseReleaseEvent : " << e->pos();
    m_rect.setBottomRight(e->pos());
    m_is_pressed = false;
}
