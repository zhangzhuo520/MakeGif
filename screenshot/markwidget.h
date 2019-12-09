#ifndef MARKWIDGET_H
#define MARKWIDGET_H
#include <QSharedPointer>
#include <QImage>
#include <QDebug>
#include "datastruct.h"
class QEvent;
class QMouseEvent;
class QPixmap;
class Shape;
class MarkWidget
{
public:
    MarkWidget(QSharedPointer <QPixmap> pixmap = nullptr);
    ~MarkWidget();

    void set_paint_property(PaintProperty);
    bool handleEvent(QEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);

//    void drawArrows(const QPoint& startPoint, const QPoint& endPoint, QPainter &paiter);

private:
    QImage m_image;
    PaintProperty m_paint_property;
    Shape *m_shape;
};

#endif // MARKWIDGET_H
