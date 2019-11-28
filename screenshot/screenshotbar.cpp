#include "screenshotbar.h"
#include <QLabel>
#include "pushbutton.h"
#include <QHBoxLayout>
#include <QPainter>
#include <QDebug>

ScreenShotBar::ScreenShotBar(QWidget *parent):
    QWidget(parent),
    m_enter(false)
{
    initUi();
}

ScreenShotBar::~ScreenShotBar()
{

}

void ScreenShotBar::initUi()
{
    QHBoxLayout *hlayout = new QHBoxLayout(this);
    m_line_btn = new PushButton("Line", this);
    m_box_btn = new PushButton("Box", this);
    m_arrow_btn = new PushButton("Arrow", this);
    m_ok_btn = new PushButton("OK", this);
    m_cancel_btn = new PushButton("Cancel", this);
    hlayout->addWidget(m_line_btn);
    hlayout->addWidget(m_box_btn);
    hlayout->addWidget(m_arrow_btn);
    hlayout->addWidget(m_cancel_btn);
    hlayout->addWidget(m_ok_btn);
    setLayout(hlayout);
//    connect(m_line_btn, SIGNAL(pressed()), this, signal)
    connect(m_ok_btn, SIGNAL(pressed()), this, SIGNAL(signal_ok_btnclick()));
    connect(m_cancel_btn, SIGNAL(pressed()), this, SIGNAL(signal_cancel_btnclick()));
}

void ScreenShotBar::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen(Qt::green);
    QBrush brush(QColor(210, 210, 210));
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(0, 0, width() - 1, height() - 1);
}

void ScreenShotBar::leaveEvent(QEvent *)
{
    m_enter = false;
}

void ScreenShotBar::enterEvent(QEvent *)
{
    setCursor(Qt::ArrowCursor);
    m_enter = true;
}

bool ScreenShotBar::mouseEnter()
{
    return m_enter;
}

