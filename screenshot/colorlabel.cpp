#include "colorlabel.h"
#include <QPainter>
ColorLabel::ColorLabel(QWidget *parent, const QColor &color):
    QLabel(parent),
    m_color(color)
{
    setFixedSize(20, 20);
}

ColorLabel::~ColorLabel()
{

}

void ColorLabel::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(m_color);
    painter.setBrush(m_color);
    painter.drawRect(rect());
}
