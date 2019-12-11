#include "screenshotbar.h"
#include <QLabel>
#include "pushbutton.h"
#include "screenshotwidget.h"
#include "paintpropertywidget.h"
#include <QHBoxLayout>
#include <QPainter>
#include <QDebug>

ScreenShotBar::ScreenShotBar(QWidget *parent):
    QWidget(parent),
    m_enter(false),
    m_screen_widget(dynamic_cast <ScreenShotWidget *>(parent))
{
    initUi();
    m_property_list << new PaintProperty(LINE, Qt::black, 1)
                    << new PaintProperty(ARROW, Qt::black, 1)
                    << new PaintProperty(BOX, Qt::black, 1);

}

ScreenShotBar::~ScreenShotBar()
{

}

void ScreenShotBar::initUi()
{
    QHBoxLayout *hlayout = new QHBoxLayout(this);
    m_line_btn = new PushButton("Line", this);
    m_line_btn->setObjectName("Line");
    m_box_btn = new PushButton("Box", this);
    m_box_btn->setObjectName("Box");
    m_arrow_btn = new PushButton("Arrow", this);
    m_arrow_btn->setObjectName("Arrow");
    m_ok_btn = new PushButton("OK", this);
    m_cancel_btn = new PushButton("Cancel", this);
    hlayout->addWidget(m_line_btn);
    hlayout->addWidget(m_box_btn);
    hlayout->addWidget(m_arrow_btn);
    hlayout->addWidget(m_cancel_btn);
    hlayout->addWidget(m_ok_btn);
    setLayout(hlayout);
    connect(m_line_btn, SIGNAL(pressed()), this, SLOT(slotShowPropertyWidget()));
    connect(m_box_btn, SIGNAL(pressed()), this, SLOT(slotShowPropertyWidget()));
    connect(m_arrow_btn, SIGNAL(pressed()), this, SLOT(slotShowPropertyWidget()));
    connect(m_ok_btn, SIGNAL(pressed()), this, SIGNAL(signal_ok_btnclick()));
    connect(m_cancel_btn, SIGNAL(pressed()), this, SIGNAL(signal_cancel_btnclick()));
}

void ScreenShotBar::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen(Qt::green);
    QBrush brush(QColor(255, 255, 255));
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

void ScreenShotBar::slotShowPropertyWidget()
{
    PushButton *btn = dynamic_cast <PushButton *> (sender());
    m_screen_widget->showPaintPropertyWidget(mapToGlobal(btn->pos()));
    PaintProperty pproperty;
    if(btn->objectName()  == "Line")
    {
        pproperty.paint_type = LINE;
        pproperty.color = Qt::red;
        pproperty.width = 2;
    }
    else  if(btn->objectName()  == "Box")
    {
        pproperty.paint_type = BOX;
        pproperty.color = Qt::red;
        pproperty.width = 2;
    }
    else  if(btn->objectName()  =="Arrow")
    {
        pproperty.paint_type = ARROW;
        pproperty.color = Qt::red;
        pproperty.width = 2;
    }

    emit signal_paint_property(pproperty);
}

