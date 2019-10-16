#include "imagelabel.h"
#include <QPainter>
#include <QIcon>
#include <QLinearGradient>
#include <QPixmap>
ImageLabel::ImageLabel(QWidget *parent):
    QLabel(parent),
    m_width(width()),
    m_height(height()),
    m_start_color(Qt::white),
    m_center_color(Qt::yellow),
    m_end_color(Qt::white)
{

}

ImageLabel::~ImageLabel()
{

}

void ImageLabel::paintEvent(QPaintEvent *e)
{
        QIcon icon = QIcon("://images/cut.png");
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setPen(Qt::transparent);
        QLinearGradient linearGradient(m_width, 0, m_width, m_height);
        linearGradient.setSpread(QGradient::RepeatSpread);
        linearGradient.setColorAt(0.0, m_start_color);
        linearGradient.setColorAt(0.6, m_center_color);
        linearGradient.setColorAt(0.8, m_center_color);
        linearGradient.setColorAt(1.0, m_end_color);
        painter.setBrush(linearGradient);
        QRectF rectangle(0.0, 0.0, m_width, m_height - 3);
        painter.drawEllipse(rectangle);
        QPixmap pixmap = icon.pixmap(QSize(m_width - 5, m_height - 6),
                                     isEnabled() ? QIcon::Normal
                                                 : QIcon::Disabled,
                                     isEnabled() ? QIcon::On
                                                 : QIcon::Off);
        painter.drawPixmap(2, 3, pixmap);
        QLabel::paintEvent(e);
}
