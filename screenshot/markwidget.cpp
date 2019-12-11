#include "markwidget.h"
#include <QMouseEvent>
#include <QDebug>
#include <QPainter>
#include <QColor>
#include <QPen>
#include "shaperect.h"

MarkWidget::MarkWidget(QSharedPointer <QPixmap> pixmap):
    m_screen_image(pixmap.data()->toImage())
{
}

MarkWidget::~MarkWidget()
{

}

QImage MarkWidget::image()
{
    return m_screen_image.copy(m_cut_area);
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
        m_shape = new ShapeRect;
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
    m_shape->mousePressEvent(event);
}

void MarkWidget::mouseReleaseEvent(QMouseEvent *event)
{
    m_shape->mouseReleaseEvent(event);
}

void MarkWidget::mouseMoveEvent(QMouseEvent *event)
{
    m_shape->mouseMoveEvent(event);
}

void MarkWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(&m_screen_image);
    QPen pen;
    pen.setColor(m_paint_property.color);
    pen.setWidth(m_paint_property.width);
    m_shape->drawShape(&painter);
}


//void MarkWidget::drawArrows(const QPoint& startPoint, const QPoint& endPoint, QPainter &paiter)
//{
//    paiter.setRenderHint(QPainter::Antialiasing, true);
//    QPen pen;
////    pen.setColor(color_);
//    pen.setWidth(1);
//    paiter.setPen(pen);
////    paiter.setBrush(color_);


//    double par = 15.0;
//    double slopy = atan2((endPoint.y() - startPoint.y()),
//                         (endPoint.x() - startPoint.x()));
//    double cos_y = cos(slopy);
//    double sin_y = sin(slopy);
//    QPoint head_point1 = QPoint(endPoint.x() + int(-par*cos_y - (par / 2.0 * sin_y)),
//                           endPoint.y() + int(-par*sin_y + (par / 2.0 * cos_y)));
//    QPoint head_point2 = QPoint(endPoint.x() + int(-par*cos_y + (par / 2.0 * sin_y)),
//                           endPoint.y() - int(par / 2.0*cos_y + par * sin_y));
//    QPoint head_points[3] = { endPoint, head_point1, head_point2 };

//    paiter.drawPolygon(head_points, 3);


//    int offset_x = int(par*sin_y / 3);
//    int offset_y = int(par*cos_y / 3);
//    QPoint body_point1, body_point2;
//    body_point1 = QPoint(endPoint.x() + int(-par*cos_y - (par / 2.0*sin_y)) +
//                    offset_x, endPoint.y() + int(-par*sin_y + (par / 2.0*cos_y)) - offset_y);
//    body_point2 = QPoint(endPoint.x() + int(-par*cos_y + (par / 2.0*sin_y) - offset_x),
//                    endPoint.y() - int(par / 2.0*cos_y + par*sin_y) + offset_y);
//    QPoint body_points[3] = { startPoint, body_point1, body_point2 };
//    paiter.drawPolygon(body_points, 3);
//}
