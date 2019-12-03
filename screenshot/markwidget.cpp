#include "markwidget.h"
#include <QMouseEvent>
#include <QDebug>
#include <QPainter>
#include <QColor>

MarkWidget::MarkWidget(QSharedPointer <QPixmap> pixmap):
    m_image(pixmap.data()->toImage())
{

}

MarkWidget::~MarkWidget()
{

}

void MarkWidget::handleEvent(QEvent *event)
{
    switch (event->type())
    {
    case QEvent::MouseButtonPress:
    {
        mousePressEvent(dynamic_cast <QMouseEvent *> (event));
        break;
    }
    case QEvent::MouseButtonRelease:
    {
        mouseReleaseEvent(dynamic_cast <QMouseEvent *> (event));
        break;
    }
    case QEvent::MouseMove:
    {
        mouseMoveEvent(dynamic_cast <QMouseEvent *> (event));
        break;
    }
    default:
        break;
    }
}

void MarkWidget::mousePressEvent(QMouseEvent *event)
{
//    qDebug() << "press: " << event->pos();
}

void MarkWidget::mouseReleaseEvent(QMouseEvent *event)
{
//    qDebug() << "release: " << event->pos();
}

void MarkWidget::mouseMoveEvent(QMouseEvent *event)
{
//    qDebug() << "move: " << event->pos();
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
