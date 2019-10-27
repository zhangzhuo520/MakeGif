#include "screenshotwidget.h"
#include "screenshotwidget_p.h"
#include "mainwidget.h"
#include <QLabel>
#include <QPaintEvent>
#include <QPainter>
#include <QRegion>
#include <QDebug>
#include <QPainterPath>
#include <QApplication>
#include <QDesktopWidget>
#include <QScreen>
#include <QWindow>
#include <QDateTime>
#include <QStandardPaths>
#include "screenshotbar.h"
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
    m_screenshot_bar = new ScreenShotBar(q);
    m_screenshot_bar->hide();

}


ScreenShotWidget::ScreenShotWidget(QWidget *parent):
    d_ptr(new ScreenShotWidgetPrivate(this, parent))
{
    Q_D(ScreenShotWidget);
    d->init();
    connect(d->m_screenshot_bar, SIGNAL(signal_ok_btnclick()), this, SLOT(slot_area_cut_done()));
    connect(d->m_screenshot_bar, SIGNAL(signal_cancel_btnclick()), this, SLOT(close()));
}

ScreenShotWidget::~ScreenShotWidget()
{

}

void ScreenShotWidget::slot_area_cut_done()
{
    Q_D(ScreenShotWidget);
    d->m_screen = windowHandle()->screen();
    QPixmap pic = d->m_screen->grabWindow(QApplication::desktop()->winId(),  d->m_cut_area.left(), d->m_cut_area.top(), d->m_cut_area.width(), d->m_cut_area.height());
    QString path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) + "/" + QDateTime::currentDateTime() .toString("yyyy-MM-dd-hh-mm-ss") + ".png";
    pic.save(path,  "PNG");
    qDebug() << "save image :" << path;
    close();
    d->m_cut_area.setRect(0, 0, 0, 0);
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
    if(d->m_cut_done)
    {
        QPoint point(d->m_cut_area.right() - d->m_screenshot_bar->width(), d->m_cut_area.bottom() + 2);
        d->m_screenshot_bar->move(point);
        d->m_screenshot_bar->show();
    }
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

