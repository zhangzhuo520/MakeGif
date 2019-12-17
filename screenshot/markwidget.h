#ifndef MARKWIDGET_H
#define MARKWIDGET_H
#include <QSharedPointer>
#include <QImage>
#include <QDebug>
#include <QRect>
#include <QObject>
#include "datastruct.h"
class QEvent;
class QMouseEvent;
class QPixmap;
class Shape;
class QPaintEvent;

class MarkWidget : public QObject
{
    Q_OBJECT
public:
    MarkWidget(QSharedPointer <QPixmap> pixmap = nullptr);
    ~MarkWidget();

    QImage image();
    void set_paint_property(PaintProperty);
    void set_cut_area(const QRect&);
    bool handleEvent(QEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);

signals:
    void signalUpdate();
//    void drawArrows(const QPoint& startPoint, const QPoint& endPoint, QPainter &paiter);


private:
    bool m_drawing;
    QImage m_image;
    QImage m_screen_image;
    PaintProperty m_paint_property;
    Shape *m_shape;
    QRect m_cut_area;
};

#endif // MARKWIDGET_H
