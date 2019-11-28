#include "colorpicker.h"
#include "colorpicker_p.h"
#include "deftools/apphelper.h"

#include <QMouseEvent>
#include <QPainter>
#include <QPixmap>
#include <QApplication>
#include <QDesktopWidget>
#include <QMoveEvent>
#include <QDebug>
#include <QThread>
#include <QTime>

ColorPickerPrivate::ColorPickerPrivate(ColorPicker *widget, QSharedPointer <QPixmap> screen):
    q_ptr(widget),
    m_screen_pixmap(screen.data())
{

}

ColorPickerPrivate::~ColorPickerPrivate()
{

}

void ColorPickerPrivate::init()
{
    Q_Q(ColorPicker);
    q->setAttribute(Qt::WA_TranslucentBackground);
    q->setMouseTracking(true);
}

ColorPicker::ColorPicker(QWidget *parent, QSharedPointer <QPixmap> screen):
    QWidget(parent),
    d_ptr(new ColorPickerPrivate(this, screen))
{
    setParent(parent);
    Q_D(ColorPicker);
    d->init();
    resize(ColorPickWidth, ColorPickheight);
}

ColorPicker::~ColorPicker()
{

}

void ColorPicker::moveEvent(QMoveEvent *event)
{
    Q_D(ColorPicker);
    update();
    QWidget::moveEvent(event);
}

void ColorPicker::paintEvent(QPaintEvent *)
{
    Q_D(ColorPicker);
    QPainter painter(this);
    QPen pen(Qt::black);
    pen.setWidth(2);
    QBrush brush(Qt::black, Qt::SolidPattern);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(rect());

    pen.setColor(Qt::white);
    painter.setPen(pen);
    painter.drawRect(rect().left() + 1, rect().top() + 1, width() - 2, height() - 52);
    int pixmap_width = ColorPickWidth - 6;
    int pixmap_height = ColorPickheight - 56;
    QPixmap pixmap = d->m_screen_pixmap.data()->copy(\
                QCursor::pos().x() - pixmap_width / multiple / 2,\
                QCursor::pos().y() - pixmap_height / multiple / 2,\
                pixmap_width / multiple,\
                pixmap_height / multiple);

    painter.drawPixmap(QRect(rect().left() + 3, rect().top() + 3, width() - 6, height() - 56), pixmap);

    pen.setColor(QColor(250, 0, 0, 180));
    pen.setWidth(4);
    painter.setPen(pen);

    painter.drawLine(QPoint(6, (height() - 56) / 2), QPoint(width() - 3, (height() - 56) / 2));
    painter.drawLine(QPoint((width() - 8) / 2, 6), QPoint((width() - 8) / 2, height() - 54));

    pen.setColor(Qt::white);
    painter.setPen(pen);
    painter.drawText(QPointF(3, height() - 28), "POS:  (" + QString::number(QCursor::pos().x()) + "," + \
                     QString::number(QCursor::pos().y()) + ")", 9, 2);
    painter.drawText(QPointF(3, height() - 8), "RGB:  (" + QString::number(d->m_select_color.red()) + "," + \
                     QString::number(d->m_select_color.green()) + "," + QString::number(d->m_select_color.blue()) + ")", 9, 2);
}

