#include "recordgifwidget.h"
#include "recordgifwidget_p.h"
#include "deftools/framelesshelper.h"
#include "gifrecordthread.h"
#include "gifbar.h"
#include <QPainter>
#include <QPen>
RecordGifWidgetPrivate::RecordGifWidgetPrivate(RecordGifWidget *widget, QWidget *parent):
    m_main_widget(parent),
    q_ptr(widget)
{

}

RecordGifWidgetPrivate::~RecordGifWidgetPrivate()
{

}

void RecordGifWidgetPrivate::init()
{
    Q_Q(RecordGifWidget);
    q->setWindowFlags(Qt::FramelessWindowHint);
    q->setAttribute(Qt::WA_TranslucentBackground);
    q->move(300, 300);
    m_frameless_helper = new tools::FramelessHelper(q);
    m_frameless_helper->activateOn(q);
    m_frameless_helper->setBorderWidth(5);
    m_frameless_helper->setWidgetMovable(true);
    m_frameless_helper->setWidgetResizable(true);
    m_frameless_helper->setRubberBandOnMove(true);
    m_frameless_helper->setRubberBandOnResize(true);

    m_gif_bar = new GifBar(q);
    m_gif_bar->setObjectName("GifBar");
    m_gif_bar->show();

    m_gif_thread = new GifRecordThread(q);
}

RecordGifWidget::RecordGifWidget(QWidget *parent):
    d_ptr(new RecordGifWidgetPrivate(this, parent))
{
    Q_D(RecordGifWidget);
    d->init();
    connect(d->m_gif_bar, SIGNAL(startRecord()), this, SLOT(slotStartRecord()));
    connect(d->m_gif_bar, SIGNAL(stopRecord()), this, SLOT(slotStopRecord()));
    connect(d->m_gif_bar, SIGNAL(pauseRecord()), this, SLOT(slotPauseRecord()));
    connect(d->m_gif_bar, SIGNAL(signalXChange(QString)), this, SLOT())
    connect(d->m_gif_bar, SIGNAL(signalYChange(QString)), d->m_gif_thread, SLTO())

}

RecordGifWidget::~RecordGifWidget()
{

}

QRect RecordGifWidget::recordRect()
{
    Q_D(RecordGifWidget);
    d->m_record_rect.setX(x() + 5);
    d->m_record_rect.setY(y() + 5);
    d->m_record_rect.setWidth(width() - 10);
    d->m_record_rect.setHeight(height() - 50);
    return d->m_record_rect;
}

void RecordGifWidget::slotStartRecord()
{
    Q_D(RecordGifWidget);
    d->m_gif_thread->slotStartRecord();
}

void RecordGifWidget::slotPauseRecord()
{
    Q_D(RecordGifWidget);
    d->m_gif_thread->slotStartRecord();
}

void RecordGifWidget::slotStopRecord()
{
    Q_D(RecordGifWidget);
    d->m_gif_thread->slotStopRecord();
}

bool RecordGifWidget::eventFilter(QObject *watched, QEvent *event)
{

}

void RecordGifWidget::resizeEvent(QResizeEvent *)
{
    regeomtry();
}

void RecordGifWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen(QColor(0, 0, 0));
    pen.setWidth(10);
    painter.setPen(pen);
    painter.drawRect(0, 0, width(), height());
}

void RecordGifWidget::enterEvent(QEvent *event)
{
}

void RecordGifWidget::leaveEvent(QEvent *)
{
}

void RecordGifWidget::showEvent(QShowEvent *)
{
    Q_D(RecordGifWidget);
    d->m_gif_bar->show();
}


void RecordGifWidget::regeomtry()
{
    Q_D(RecordGifWidget);
    d->m_gif_bar->setGeometry(5, height() - 45, width() - 10, 40);
    d->m_gif_bar->setRecordHeight(y() + 5);
    d->m_gif_bar->setRecordWidth(x() + 5);
}
