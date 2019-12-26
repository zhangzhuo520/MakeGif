#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <QRect>
#include <QPoint>

class ShapeAlgorithm
{
public:
    ShapeAlgorithm();
    ~ShapeAlgorithm();

    QRect correctRect(const QPoint & start, const QPoint & end);
    bool pointInRect(const QRect&, const QPoint& pos);
    QPoint pointLimitRect(const QRect&, const QPoint& pos);

};

#endif // ALGORITHM_H
