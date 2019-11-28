#include "shaperect.h"

ShapeRect::ShapeRect():
    Shape(this),
    m_rect(0, 0, 0, 0)
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

void ShapeRect::drawShape(QPainter *)
{

}

void ShapeRect::mouseDoubleClick(QMouseEvent * e)
{

}

void ShapeRect::mousePressEvent(QMouseEvent * e)
{

}

void ShapeRect::mouseMoveEvent(QMouseEvent * e)
{

}

void ShapeRect::mouseReleaseEvent(QMouseEvent *)
{

}
