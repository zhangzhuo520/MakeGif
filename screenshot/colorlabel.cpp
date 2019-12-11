#include "colorlabel.h"
#include <QPainter>

ColorLabel::ColorLabel(QWidget *parent, const QColor &color):
    QLabel(parent),
    m_color(color),
    m_select(false),
    m_enter(false)
{
    setFixedSize(20, 20);
}

ColorLabel::~ColorLabel()
{

}

void ColorLabel::setSelect(bool flag)
{
    m_select = flag;
    update();
    if(m_select)
        emit signalSelectColor(m_color);
}

bool ColorLabel::select()
{
   return m_select;
}

void ColorLabel::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::NoPen);
    painter.setBrush(m_color);
    painter.drawRect(rect());
    if(m_select || m_enter)
    {
        painter.setBrush(Qt::green);
        painter.drawRect(QRect(5, 5, 10, 10));
    }
}

void ColorLabel::mousePressEvent(QMouseEvent *)
{
    m_select = true;
    update();
    emit signalSelectColor(m_color);
}

void ColorLabel::enterEvent(QEvent *)
{
    m_enter = true;
    update();
}

void ColorLabel::leaveEvent(QEvent *)
{
    m_enter = false;
    update();
}
