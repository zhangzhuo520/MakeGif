#include "screenshotwidget.h"
#include "screenshotwidget_p.h"
#include "mainwidget.h"
#include <QLabel>
#include <QPaintEvent>
#include <QPainter>
#include <QRegion>
#include <QDebug>
#include <QPainterPath>
ScreenShotWidgetPrivate::ScreenShotWidgetPrivate(ScreenShotWidget *widget, QWidget *parent):
    q_ptr(widget),
    m_main_widget(dynamic_cast<MainWidget *> (parent)),
    m_mouse_press(false),
    m_cut_done(false),
    m_cut_area(0,  0,  0, 0),
    m_mouse_pos(0, 0)
{

}

ScreenShotWidgetPrivate::~ScreenShotWidgetPrivate()
{

}

void ScreenShotWidgetPrivate::init()
{
    Q_Q(ScreenShotWidget);
    q->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
    q->setAttribute(Qt::WA_TranslucentBackground);
}


ScreenShotWidget::ScreenShotWidget(QWidget *parent):
    d_ptr(new ScreenShotWidgetPrivate(this, parent))
{
    Q_D(ScreenShotWidget);
    d->init();
}

ScreenShotWidget::~ScreenShotWidget()
{

}

void ScreenShotWidget::mouseMoveEvent(QMouseEvent *event)
{
    Q_D(ScreenShotWidget);
    d->m_mouse_pos = event->pos();
    if(d->m_mouse_press)
    {
        d->m_cut_done = true;
        d->m_cut_area.setBottomRight(event->pos());
    }
    update();
    QWidget::mouseMoveEvent(event);
}

void ScreenShotWidget::mousePressEvent(QMouseEvent *event)
{
    Q_D(ScreenShotWidget);
    d->m_mouse_press = true;
    d->m_cut_area.setTopLeft(event->pos());
    d->m_cut_area.setBottomRight(event->pos());
    update();
    QWidget::mousePressEvent(event);
}

void ScreenShotWidget::mouseReleaseEvent(QMouseEvent *event)
{
    Q_D(ScreenShotWidget);
    d->m_mouse_press = false;
    update();
    QWidget::mouseReleaseEvent(event);
}

void ScreenShotWidget::paintEvent(QPaintEvent *event)
{
    Q_D(ScreenShotWidget);
    QPainter painter(this);
    painter.setPen(QColor(0, 0, 0, 0));
    painter.setBrush(QColor(255, 255, 255, 100));
   QPainterPath rect_path;
   rect_path.addRect(QRect(0, 0, width(), height()));
    if(d->m_mouse_press || d->m_cut_done)
    {
        QPainterPath temp_path;
        temp_path.addRect(d->m_cut_area);
        rect_path = rect_path - temp_path;
    }
    painter.drawPath(rect_path);
    QWidget::paintEvent(event);
}

void ScreenShotWidget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape)
    {
        close();
    }
    QWidget::keyPressEvent(event);

}

