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
    m_screen_widget(dynamic_cast <ScreenShotWidget *>(parent)),
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
    m_mask_btn = new PushButton( this);
    m_mask_btn->setObjectName("MaskBtn");
    m_box_btn = new PushButton( this);
    m_box_btn->setObjectName("BoxBtn");
    m_arrow_btn = new PushButton(this);
    m_arrow_btn->setObjectName("ArrowBtn");
    m_circle_btn = new PushButton(this);
    m_circle_btn->setObjectName("CircleBtn");
    m_text_btn = new PushButton(this);
    m_text_btn->setObjectName("TextBtn");
    m_pen_btn = new PushButton(this);
    m_pen_btn->setObjectName("PenBtn");


    m_ok_btn = new PushButton(this);
    m_ok_btn->setObjectName("OkBtn");
    m_cancel_btn = new PushButton( this);
    m_cancel_btn->setObjectName("CancelBtn");
    hlayout->addWidget(m_arrow_btn);
    hlayout->addWidget(m_text_btn);
    hlayout->addWidget(m_pen_btn);
    hlayout->addWidget(m_box_btn);
    hlayout->addWidget(m_circle_btn);
    hlayout->addWidget(m_mask_btn);
    hlayout->addWidget(m_cancel_btn);
    hlayout->addWidget(m_ok_btn);
    setLayout(hlayout);
    connect(m_mask_btn, SIGNAL(pressed()), this, SLOT(slotShowPropertyWidget()));
    connect(m_box_btn, SIGNAL(pressed()), this, SLOT(slotShowPropertyWidget()));
    connect(m_arrow_btn, SIGNAL(pressed()), this, SLOT(slotShowPropertyWidget()));
    connect(m_circle_btn, SIGNAL(pressed()), this, SLOT(slotShowPropertyWidget()));
    connect(m_text_btn, SIGNAL(pressed()), this, SLOT(slotShowPropertyWidget()));
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
    if(btn->objectName()  == "MaskBtn")
    {
        pproperty.paint_type = MASK;
        pproperty.color = Qt::red;
        pproperty.width = 1;
        pproperty.line_style = 1;
        pproperty.brush_style = 0;
    }
    else  if(btn->objectName()  == "BoxBtn")
    {
        pproperty.paint_type = BOX;
        pproperty.color = Qt::red;
        pproperty.width = 1;
        pproperty.line_style = 1;
        pproperty.brush_style = 0;
    }
    else  if(btn->objectName()  =="ArrowBtn")
    {
        pproperty.paint_type = ARROW;
        pproperty.color = Qt::red;
        pproperty.width = 1;
        pproperty.line_style = 1;
        pproperty.brush_style = 1;
    }
    else  if(btn->objectName()  =="CircleBtn")
    {
        pproperty.paint_type = CIRCLE;
        pproperty.color = Qt::red;
        pproperty.width = 1;
        pproperty.line_style = 1;
        pproperty.brush_style = 0;

    }
    else  if(btn->objectName()  =="TextBtn")
    {
        pproperty.paint_type = TEXT;
        pproperty.color = Qt::red;
        pproperty.width = 1;
        pproperty.line_style = 1;
        pproperty.brush_style = 1;
    }
    else if(btn->objectName() == "PenBtn")
    {
        pproperty.paint_type = PEN;
        pproperty.color = Qt::red;
        pproperty.width = 1;
        pproperty.line_style = 1;
        pproperty.brush_style = 0;
    }

    emit signal_paint_property(pproperty);
}

