#include "markwidget.h"
#include <QMouseEvent>
#include <QDebug>
#include <QPainter>
#include <QColor>
#include <QPen>
#include <QBrush>
#include "shaperect.h"
#include "shapearrow.h"
MarkWidget::MarkWidget(QSharedPointer <QPixmap> pixmap):
    m_screen_image(pixmap.data()->toImage()),
    m_image(pixmap.data()->toImage()),
    m_drawing(false)
{

}

MarkWidget::~MarkWidget()
{

}

QImage MarkWidget::image()
{
    return m_image.copy(m_cut_area);
}

void MarkWidget::set_paint_property(PaintProperty property)
{
    m_paint_property = property;
    switch (m_paint_property.paint_type) {
    case BOX:
        m_shape = new ShapeRect;
        break;
    case LINE:
        m_shape = new ShapeRect;
        break;
    case ARROW:
        m_shape = new ShapeArrow;
        break;
    case CIRCLE:
        m_shape = new ShapeRect;
        break;
    case TEXT:
        m_shape = new ShapeRect;
        break;
    default:
        break;
    }
}

void MarkWidget::set_cut_area(const QRect & rect)
{
    m_cut_area.setRect(rect.x(), rect.y(), rect.width(), rect.height());
}

bool MarkWidget::handleEvent(QEvent *event)
{
    if(m_paint_property.paint_type == PaintType:: NONE)
    {
        return true;
    }

    switch (event->type())
    {
    case QEvent::MouseButtonPress:
    {
        mousePressEvent(dynamic_cast <QMouseEvent *> (event));
        event->accept();
        emit signalUpdate();
        return false;
    }
    case QEvent::MouseButtonRelease:
    {
        mouseReleaseEvent(dynamic_cast <QMouseEvent *> (event));
        event->accept();
        emit signalUpdate();
        return false;
    }
    case QEvent::MouseMove:
    {
        mouseMoveEvent(dynamic_cast <QMouseEvent *> (event));
        event->accept();
        emit signalUpdate();
        return false;
    }
    case QEvent::Paint:
    {
        paintEvent(dynamic_cast <QPaintEvent *> (event));
        return true;
    }
    default:
        break;
    }
    return true;
}

void MarkWidget::mousePressEvent(QMouseEvent *event)
{
    m_drawing = true;
    m_shape->mousePressEvent(event);
}

void MarkWidget::mouseReleaseEvent(QMouseEvent *event)
{
    m_drawing = false;
    m_screen_image = m_image;
    m_shape->mouseReleaseEvent(event);
}

void MarkWidget::mouseMoveEvent(QMouseEvent *event)
{
    m_shape->mouseMoveEvent(event);
}

void MarkWidget::paintEvent(QPaintEvent *)
{
    if(!m_drawing) return;
    QPainter painter;
    m_image = m_screen_image;
    painter.begin(&m_image);
    painter.setRenderHint(QPainter::Antialiasing, true);
    QPen pen;
    pen.setColor(m_paint_property.color);
    pen.setWidth(m_paint_property.width);
    QBrush brush;
    brush.setColor(Qt::red);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    painter.setPen(pen);
    m_shape->drawShape(&painter);
    painter.end();
}



