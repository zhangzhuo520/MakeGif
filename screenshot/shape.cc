#include "shape.h"
QList <Shape *> Shape:: m_shape_list;
Shape::Shape(Shape *shape):
    m_paint_range(0, 0, 0 ,0)
{
    m_shape_list.append(shape);
}

QRect Shape::getDefaultBoundingBox(const QPoint & start, const QPoint & end)
{
    int rect_top = start.y() < end.y() ? start.y() : end.y();
    int rect_bottom = start.y() > end.y() ? start.y() : end.y();
    int rect_left = start.x() < end.x() ? start.x() : end.x();
    int rect_right = start.x() > end.x() ? start.x() : end.x();
    return QRect(QPoint(rect_left, rect_top), QPoint(rect_right, rect_bottom));
}

void Shape::setPaintRange(const QRect &range)
{
    m_paint_range.setTopLeft(range.topLeft());
    m_paint_range.setBottomRight(range.bottomRight());
}
