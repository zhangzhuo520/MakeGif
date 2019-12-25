#include "markwidget.h"
#include <QMouseEvent>
#include <QDebug>
#include <QPainter>
#include <QColor>
#include <QPen>
#include <QGuiApplication>
#include <QBrush>
#include "shaperect.h"
#include "shapearrow.h"
#include "screenshotwidget.h"

MarkWidget::MarkWidget(QWidget *widget, QSharedPointer <QPixmap> screen):
    m_drawing(false),
    m_is_resize(false),
    m_image(screen.data()->toImage()),
    m_screen_image(screen.data()->toImage()),
    m_screen_widget(dynamic_cast<ScreenShotWidget *> (widget))
{

}

MarkWidget::~MarkWidget()
{

}

QImage MarkWidget::image()
{
    return m_image;
}

void MarkWidget::setBgImage(QSharedPointer<QPixmap> pixmap)
{
   m_screen_image = m_image = pixmap.data()->toImage();
}

void MarkWidget::setPaintProperty(PaintProperty property)
{
    m_paint_property = property;
}

void MarkWidget::setCutArea(const QRect & rect)
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
        if(coverBorder())
        {
            m_is_resize = true;
            return true;
        }

        if(!pointInRect(m_cut_area, QCursor::pos()))
            return true;

        mousePressEvent(dynamic_cast <QMouseEvent *> (event));
        event->accept();
        emit signalUpdate();
        return false;
    }
    case QEvent::MouseButtonRelease:
    {
        m_is_resize = false;
        if(!pointInRect(m_cut_area, QCursor::pos()))
            return true;
        mouseReleaseEvent(dynamic_cast <QMouseEvent *> (event));
        event->accept();
        emit signalUpdate();
        return true;
    }
    case QEvent::MouseMove:
    {
        if(m_is_resize)
            return true;
        if(!pointInRect(m_cut_area, QCursor::pos()))
            return true;
        mouseMoveEvent(dynamic_cast <QMouseEvent *> (event));
        event->accept();
        emit signalUpdate();
        coverBorder();
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
    switch (m_paint_property.paint_type)
    {
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
    m_drawing = true;
    m_shape->mousePressEvent(event);
}

void MarkWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if(m_drawing)
    {
        m_screen_image = m_image;
        m_shape->mouseReleaseEvent(event);
        m_drawing = false;
    }
}

void MarkWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(!m_drawing) return;
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

bool MarkWidget::coverBorder()
{
    QPoint pos =QCursor::pos();
    int border = 5;
    QRect rect = m_cut_area;
    if(abs(pos.y() - rect.top()) < border && abs(pos.x() - rect.left()) < border)
    {
        m_screen_widget->setCursor(Qt::SizeFDiagCursor);
        return true;
    }
    else if(abs(pos.y() - rect.top()) < border && abs(pos.x() - rect.right()) < border)
    {
        m_screen_widget->setCursor(Qt::SizeBDiagCursor);
        return true;
    }
    else if(abs(pos.y() - rect.bottom()) < border && abs(pos.x() - rect.left()) < border)
    {
        m_screen_widget->setCursor(Qt::SizeBDiagCursor);
        return true;
    }
    else if(abs(pos.y() - rect.bottom()) < border && abs(pos.x() - rect.right()) < border)
    {
        m_screen_widget->setCursor(Qt::SizeFDiagCursor);
        return true;
    }
    else if(abs(pos.y() - rect.top()) < border && (pos.x() > rect.left()) && (pos.x() < rect.right()))
    {
        m_screen_widget->setCursor(Qt::SizeVerCursor);
        return true;
    }
    else if(abs(pos.y() - rect.bottom()) < border && (pos.x() > rect.left()) && (pos.x() < rect.right()))
    {
        m_screen_widget->setCursor(Qt::SizeVerCursor);
        return true;
    }
    else if(abs(pos.x() - rect.left()) < border && (pos.y() > rect.top()) && (pos.y() < rect.bottom()))
    {
        m_screen_widget->setCursor(Qt::SizeHorCursor);
        return true;
    }
    else if(abs(pos.x() - rect.right()) < border && (pos.y() > rect.top()) && (pos.y() < rect.bottom()))
    {
        m_screen_widget->setCursor(Qt::SizeHorCursor);
        return true;
    }
    m_screen_widget->setCursor(Qt::ArrowCursor);
    return false;
}

bool MarkWidget::touchShape(const QPoint & pos)
{
    if(Shape::getShapeList().count() == 0) return true;
    QRectF first_rect = Shape::getShapeList().at(0)->boundingBox();
    int left(first_rect.left()), right(first_rect.right()), top(first_rect.top()), bottom(first_rect.right());
    foreach (Shape *shape, m_shape->getShapeList())
    {
        QRectF rect = shape->boundingBox();
        left = left < rect.left() ? left : rect.left();
        right = right > rect.right() ? right : rect.right();
        top = top < rect.top() ? top : rect.top();
        bottom = bottom > rect.bottom() ? bottom : rect.bottom();
        qDebug() <<  "22222222222222222touchShape : "  <<  left << right << top << bottom;
    }
    QRect temp_rect(QPoint(left, top), QPoint(right, bottom));
    qDebug() << pointInRect(temp_rect, pos);
    return pointInRect(temp_rect, pos);
}

bool MarkWidget::pointInRect(const QRect &rect, const QPoint &pos)
{
    if(pos.x() > rect.left() && pos.x() < rect.right() &&
            pos.y() > rect.top() && pos.y() < rect.bottom())
    {
        return true;
    }
    return false;
}
