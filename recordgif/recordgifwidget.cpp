#include "recordgifwidget.h"
#include "recordgifwidget_p.h"
#include "framelesshelper.h"
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
//    m_frameless_helper = new tools::FramelessHelper(q);
//    m_frameless_helper->activateOn(q);
//    m_frameless_helper->setBorderWidth(5);
//    m_frameless_helper->setWidgetMovable(true);
//    m_frameless_helper->setWidgetResizable(true);
//    m_frameless_helper->setRubberBandOnMove(true);
//    m_frameless_helper->setRubberBandOnResize(true);

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
    connect(d->m_gif_bar, SIGNAL(signalXChange(QString)), this, SLOT(slotXChange(QString)));
    connect(d->m_gif_bar, SIGNAL(signalYChange(QString)), this, SLOT(slotYChange(QString)));
    connect(d->m_gif_bar, SIGNAL(signalFpsChange(QString)), this, SLOT(slotFpsChange(QString)));
    connect(d->m_gif_thread, SIGNAL(signalFrameCount(int)), this, SLOT(slotFrameCount(int)));
}

RecordGifWidget::~RecordGifWidget()
{

}

void RecordGifWidget::updateRecordRect()
{
    Q_D(RecordGifWidget);
    d->m_gif_thread->setRecordRect(QRect(x() + 5, y() + 5, width() - 10, height() - 50));
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

void RecordGifWidget::slotXChange(const QString & str)
{
    Q_D(RecordGifWidget);
    QRect rect = d->m_gif_thread->gifRect();
    rect.setWidth(str.toInt());
}

void RecordGifWidget::slotYChange(const QString &str)
{
    Q_D(RecordGifWidget);
    QRect rect = d->m_gif_thread->gifRect();
    rect.setHeight(str.toInt());
}

void RecordGifWidget::slotFpsChange(const QString &str)
{
    Q_D(RecordGifWidget);
    d->m_gif_thread->setFps(str.toInt());
}

void RecordGifWidget::slotFrameCount(int count )
{
    Q_D(RecordGifWidget);
    d->m_gif_bar->setRecordInfo("current record " + QString::number(count) + "frame ");
}

void RecordGifWidget::resizeEvent(QResizeEvent *)
{
    Q_D(RecordGifWidget);
    if(d->m_gif_thread->getThreadState() == GifRecordThread::STOP)
    {
        regeomtry();
        updateRecordRect();
    }
}

void RecordGifWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen(QColor(255, 255, 255));
    pen.setWidth(10);
    painter.setPen(pen);
    painter.drawRect(0, 0, width(), height());
}

void RecordGifWidget::moveEvent(QMoveEvent *)
{
    updateRecordRect();
}

void RecordGifWidget::regeomtry()
{
    Q_D(RecordGifWidget);
    d->m_gif_bar->setGeometry(5, height() - 45, width() - 10, 40);
    d->m_gif_bar->setRecordHeight(QString::number(height() - 50));
    d->m_gif_bar->setRecordWidth(QString::number(width() - 10));
}
