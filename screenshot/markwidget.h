#ifndef MARKWIDGET_H
#define MARKWIDGET_H
#include <QSharedPointer>
#include <QImage>
#include "datastruct.h"
class QEvent;
class QMouseEvent;
class QPixmap;
class MarkWidget
{
public:
    MarkWidget(QSharedPointer <QPixmap> pixmap = nullptr);
    ~MarkWidget();

    void handleEvent(QEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);

//    void drawArrows(const QPoint& startPoint, const QPoint& endPoint, QPainter &paiter);

private:

    QImage m_image;
    PaintProperty m_paint_property;
};

#endif // MARKWIDGET_H
