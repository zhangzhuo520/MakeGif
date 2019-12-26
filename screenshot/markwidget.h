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
class ScreenShotWidget;
class MarkWidget : public QObject
{
    Q_OBJECT
public:
    MarkWidget(QWidget *widget = nullptr, QSharedPointer <QPixmap> screen = nullptr);
    ~MarkWidget();

    QImage image();

    void setBgImage(QSharedPointer <QPixmap>);
    void setPaintProperty(PaintProperty);
    void setCutArea(const QRect&);
    bool handleEvent(QEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);
    bool coverBorder();
    bool touchShape(const QPoint&);
    bool pointInRect(const QRect&, const QPoint& pos);


signals:
    void signalUpdate();


private:
    bool m_drawing;
    bool m_is_resize;
    QImage m_image;
    QImage m_screen_image;
    PaintProperty m_paint_property;
    Shape *m_shape;
    QRect m_cut_area;
    ScreenShotWidget *m_screen_widget;
};

#endif // MARKWIDGET_H
