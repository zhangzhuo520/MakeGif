#include "shapearrow.h"
#include <QPainter>
#include <QDebug>
ShapeArrow::ShapeArrow():
    Shape(this),
    m_drawing(false)
{

}

ShapeArrow::~ShapeArrow()
{

}

void ShapeArrow::drawShape(QPainter * painter)
{
    double par = 15.0;
    double slopy = atan2((m_end_point.y() - m_start_point.y()),
                         (m_end_point.x() - m_start_point.x()));
    double cos_y = cos(slopy);
    double sin_y = sin(slopy);
    QPoint head_point1 = QPoint(m_end_point.x() + int(-par*cos_y - (par / 2.0 * sin_y)),
                           m_end_point.y() + int(-par*sin_y + (par / 2.0 * cos_y)));
    QPoint head_point2 = QPoint(m_end_point.x() + int(-par*cos_y + (par / 2.0 * sin_y)),
                           m_end_point.y() - int(par / 2.0*cos_y + par * sin_y));
    QPoint head_points[3] = { m_end_point, head_point1, head_point2 };

    painter->drawPolygon(head_points, 3);

    int offset_x = int(par*sin_y / 3);
    int offset_y = int(par*cos_y / 3);
    QPoint body_point1, body_point2;
    body_point1 = QPoint(m_end_point.x() + int(-par*cos_y - (par / 2.0*sin_y)) +
                    offset_x, m_end_point.y() + int(-par*sin_y + (par / 2.0*cos_y)) - offset_y);
    body_point2 = QPoint(m_end_point.x() + int(-par*cos_y + (par / 2.0*sin_y) - offset_x),
                    m_end_point.y() - int(par / 2.0*cos_y + par*sin_y) + offset_y);
    QPoint body_points[3] = { m_start_point, body_point1, body_point2 };
    painter->drawPolygon(body_points, 3);
}

void ShapeArrow::mouseDoubleClick(QMouseEvent *)
{

}

void ShapeArrow::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton && m_algorithm.pointInRect(m_paint_range, e->pos()))
    {
        m_drawing = true;
        m_start_point = m_end_point = e->pos();
    }
}

void ShapeArrow::mouseMoveEvent(QMouseEvent *e)
{
    if(m_drawing)
        m_end_point =  m_algorithm.pointLimitRect(m_paint_range, e->pos());
}

void ShapeArrow::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {

        m_drawing = false;
    }
}

QRectF ShapeArrow::boundingBox()
{
    return getDefaultBoundingBox(m_start_point, m_end_point);
}


