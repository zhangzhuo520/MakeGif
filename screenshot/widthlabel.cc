#include "widthlabel.h"
#include <QPainter>
#include <QBrush>
WidthLabel::WidthLabel(QWidget *parent, int level):
    QLabel(parent),
    m_level(level),
    m_color(Qt::gray),
    m_select(false)
{

}

WidthLabel::~WidthLabel()
{

}

void WidthLabel::setSelect(bool flag)
{
    m_select = flag;
    m_color = Qt::gray;
    update();
    if(m_select)
        emit signalSelectChange();
}

bool WidthLabel::select()
{
    return m_select;
}

void WidthLabel::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::NoPen);
    painter.setBrush(m_color);
    int ewidth = 0;
    if(m_level == 1) ewidth = 5;
    else if(m_level == 2) ewidth = 7;
    else if(m_level == 3) ewidth = 9;
    painter.drawEllipse(QPoint(width() / 2, height() / 2), ewidth, ewidth);
}

void WidthLabel::mousePressEvent(QMouseEvent *)
{
    m_color = Qt::green;
    m_select = true;
    emit signalSelectChange();
}

void WidthLabel::enterEvent(QEvent *)
{
    m_color = Qt::green;
    update();
}

void WidthLabel::leaveEvent(QEvent *)
{
    if(!m_select)
    m_color = Qt::gray;
    update();
}
