#include "algorithm.h"

ShapeAlgorithm::ShapeAlgorithm()
{

}

ShapeAlgorithm::~ShapeAlgorithm()
{

}

QRect ShapeAlgorithm::correctRect(const QPoint & start, const QPoint & end)
{
    int rect_top = start.y() < end.y() ? start.y() : end.y();
    int rect_bottom = start.y() > end.y() ? start.y() : end.y();
    int rect_left = start.x() < end.x() ? start.x() : end.x();
    int rect_right = start.x() > end.x() ? start.x() : end.x();
    return QRect(QPoint(rect_left, rect_top), QPoint(rect_right, rect_bottom));
}

bool ShapeAlgorithm::pointInRect(const QRect &rect, const QPoint &pos)
{
        if(pos.x() > rect.left() && pos.x() < rect.right() &&
                pos.y() > rect.top() && pos.y() < rect.bottom())
        {
            return true;
        }
        return false;
}

QPoint ShapeAlgorithm::pointLimitRect(const QRect &rect, const QPoint &pos)
{
    QPoint temp_pos(pos);
    if(pos.x() < rect.left()) temp_pos.setX(rect.left());
    if(pos.x() > rect.right()) temp_pos.setX(rect.right());
    if(pos.y() < rect.top()) temp_pos.setY(rect.top());
    if(pos.y() > rect.bottom()) temp_pos.setY(rect.bottom());
    return temp_pos;
}
