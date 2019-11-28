#include "colorlabel.h"
#include <QPainter>
ColorLabel::ColorLabel(QWidget *parent, const QColor &color)
{

}

ColorLabel::~ColorLabel()
{

}

void ColorLabel::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setPen(m_color);
    painter.setBrush(m_color);
    painter.drawRect(rect());
}
