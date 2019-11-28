#include "mainwidget.h"
#include "mainwidget_p.h"
#include "imagelabel.h"
#include "pushbutton.h"
#include "deftools/appinit.h"
#include "pushbutton.h"
#include "screenshot/screenshotwidget.h"
#include "recordgif/recordgifwidget.h"
#include "recordgif/gifbar.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QApplication>
#include <QKeyEvent>
#include <QString>
#include <QDebug>  // must add qdebug module， or setProperty will be mistake

MainWidgetPrivate::MainWidgetPrivate(MainWidget *widget):
    q_ptr(widget),
    m_record_mode(NONE)
{

}

MainWidgetPrivate::~MainWidgetPrivate()
{

}

void MainWidgetPrivate::initProperty()
{
    Q_Q(MainWidget);
    q->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
    q->setProperty("CanMove", true);
}

void MainWidgetPrivate::initUi()
{
    Q_Q(MainWidget);
    m_image_label  = new ImageLabel(q);
    m_screenshot_btn = new PushButton(q);
    m_screenshot_btn->setText("截图");
    m_recordgif_btn = new PushButton(q);
    m_recordgif_btn->setText("Gif录制");
    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->setSpacing(0);
    hlayout->setMargin(0);
    hlayout->addWidget(m_image_label);
    hlayout->addWidget(m_screenshot_btn);
    hlayout->addWidget(m_recordgif_btn);
    q->setLayout(hlayout);

    m_recordgif_widget = new RecordGifWidget(q);
    m_recordgif_widget->resize(800, 600);
    m_recordgif_widget->move(300, 300);
    m_recordgif_widget->hide();
}


MainWidget::MainWidget(QWidget *parent):
    QWidget(parent),
    d_ptr(new MainWidgetPrivate(this))
{
    Q_D(MainWidget);
    resize(400, 100);
    d->initProperty();
    d->initUi();

    connect(d->m_screenshot_btn, SIGNAL(pressed()), this, SLOT(slot_screen_shot()));
    connect(d->m_recordgif_btn, SIGNAL(pressed()), this, SLOT(slot_record_gif()));
}

MainWidget::~MainWidget()
{

}

void MainWidget::slot_screen_shot()
{
    Q_D(MainWidget);
    d->m_screenshot_widget = new ScreenShotWidget(this);
    d->m_screenshot_widget->showFullScreen();
}

void MainWidget::slot_record_gif()
{
    Q_D(MainWidget);
    d->m_recordgif_widget->show();
}

void MainWidget::keyPressEvent(QKeyEvent *event)
{

}

