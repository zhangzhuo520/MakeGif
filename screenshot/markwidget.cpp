#include "markwidget.h"
#include <QMouseEvent>
#include <QDebug>
#include <QPainter>
#include <QColor>
#include <QPen>
#include <QFontMetrics>
#include <QGuiApplication>
#include <QBrush>
//#include <Q
#include "shaperect.h"
#include "shapearrow.h"
#include "shapeline.h"
#include "shapecircle.h"
#include "shapepen.h"
#include "shapetext.h"
#include "shapemosaic.h"
#include "screenshotwidget.h"
#include "textedit.h"
MarkWidget::MarkWidget(QWidget *widget, QSharedPointer <QPixmap> screen):
    m_drawing(false),
    m_is_resize(false),
    m_image(screen.data()->toImage()),
    m_screen_image(screen.data()->toImage()),
    m_screen_widget(dynamic_cast<ScreenShotWidget *> (widget)),
  m_text_edit(new TextEdit(m_screen_widget))
{
        m_text_edit->hide();
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
    updateFont();
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

        mousePressEvent(dynamic_cast <QMouseEvent *> (event));
        event->accept();
        emit signalUpdate();
        return false;
    }
    case QEvent::MouseButtonRelease:
    {
        m_is_resize = false;
        mouseReleaseEvent(dynamic_cast <QMouseEvent *> (event));
        event->accept();
        emit signalUpdate();
        return true;
    }
    case QEvent::MouseMove:
    {
        if(m_is_resize)
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
    case PEN:
        m_shape = new ShapePen;
        break;
    case ARROW:
        m_shape = new ShapeArrow;
        break;
    case CIRCLE:
        m_shape = new ShapeCircle;
        break;
    case TEXT:
    {
        m_shape = new ShapeText(m_text_edit, m_font);
        break;
    }
    case MOSAIC:
    {
        m_shape = new shapeMosaic;
        break;
    }
    default:
        break;
    }
    m_drawing = true;
    m_shape->setPaintRange(m_cut_area);

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
    if(m_paint_property.paint_type == PEN ||
            m_paint_property.paint_type == MOSAIC )
    {
        painter.begin(&m_image);
    }
    else
    {
        m_image = m_screen_image;
        painter.begin(&m_image);
    }
    painter.setRenderHint(QPainter::Antialiasing, true);
    QPen pen;
    pen.setColor(m_paint_property.color);
    pen.setWidth(m_paint_property.width);
    pen.setStyle(Qt::PenStyle(m_paint_property.line_style));
    QBrush brush;
    brush.setColor(m_paint_property.color);
    brush.setStyle(Qt::BrushStyle(m_paint_property.brush_style));
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
    if(Shape::shapeList().count() == 0) return true;
    QRectF first_rect = Shape::shapeList().at(0)->boundingBox();
    int left(first_rect.left()), right(first_rect.right()), top(first_rect.top()), bottom(first_rect.right());
    foreach (Shape *shape, m_shape->shapeList())
    {
        QRectF rect = shape->boundingBox();
        left = left < rect.left() ? left : rect.left();
        right = right > rect.right() ? right : rect.right();
        top = top < rect.top() ? top : rect.top();
        bottom = bottom > rect.bottom() ? bottom : rect.bottom();
    }
    QRect temp_rect(QPoint(left, top), QPoint(right, bottom));
    return  pointInRect(temp_rect, pos);
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

void MarkWidget::updateFont()
{
    if(m_paint_property.paint_type == TEXT)
    {
        m_font = QFont("Times", m_paint_property.width, QFont::Thin);
        QFontMetrics fonmetcris(m_font);
        m_text_edit->setFont(m_font);
        QPalette palette = m_text_edit->palette();
        palette.setColor(QPalette::Text,  m_paint_property.color);
        m_text_edit->setPalette(palette);
        m_text_edit->setFixedHeight(fonmetcris.height() + 10);
    }
}
