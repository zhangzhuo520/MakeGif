#include "screenshotwidget.h"
#include "screenshotwidget_p.h"
#include "../app/mainwidget.h"
#include "colorpicker.h"
#include "paintpropertywidget.h"
#include "markwidget.h"
#include "shape.h"
#include <windows.h>
#include <QLabel>
#include <QPaintEvent>
#include <QPainter>
#include <QRegion>
#include <QDebug>
#include <QPainterPath>
#include <QApplication>
#include <QDesktopWidget>
#include <QScreen>
#include <QWindow>
#include <QDateTime>
#include <QStandardPaths>
#include <QDebug>
#include <cstring>
#include <QtMath>
#include "screenshotbar.h"
ScreenShotWidgetPrivate::ScreenShotWidgetPrivate(ScreenShotWidget *widget, QWidget *parent):
    q_ptr(widget),
    m_main_widget(dynamic_cast<MainWidget *> (parent)),
    m_mouse_press(false),
    m_cut_state(NONE),
    m_cut_area(0,  0,  0, 0),
    m_mask_color(0, 0, 0, 1)
{
}

ScreenShotWidgetPrivate::~ScreenShotWidgetPrivate()
{

}

void ScreenShotWidgetPrivate::initProperty()
{
    Q_Q(ScreenShotWidget);
    q->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
    q->setMouseTracking(true);
}

void ScreenShotWidgetPrivate::initSreenPixmap()
{

}

void ScreenShotWidgetPrivate::initWidget()
{
    Q_Q(ScreenShotWidget);
    m_screenshot_bar = new ScreenShotBar(q);
    m_screenshot_bar->setFixedSize(QSize(500, 45));
    m_screenshot_bar->hide();

    m_screen_pixmap = getScreenPixmap();
    m_color_picker = new ColorPicker(q, m_screen_pixmap);
    m_color_picker->show();

    m_mark_widget = new MarkWidget(q, m_screen_pixmap);

    m_painter_property_widget = new PaintPropertyWidget(q);
    m_painter_property_widget->setFixedSize(400, 90);
    m_painter_property_widget->hide();
}

QSharedPointer <QPixmap> ScreenShotWidgetPrivate::getScreenPixmap()
{
        if (m_screen_pixmap == nullptr) {
            QScreen *screen = QGuiApplication::primaryScreen();
            QRect temp_rect = getScreenRect();
            m_screen_pixmap.reset(new QPixmap(screen->grabWindow(0, temp_rect.x(),
                                temp_rect.y(), temp_rect.width(),
                                temp_rect.height())));
        }
        return m_screen_pixmap;
}

QRect ScreenShotWidgetPrivate::getScreenRect()
{
    QRect screen_rect;
    int screen_num = QApplication::screens().size();

    screen_rect = QApplication::desktop()->rect();
    if (screen_num != 1)
    {
        int temp = screen_rect.width() - (screen_rect.width() / screen_num);
        screen_rect = QRect(-temp, 0, screen_rect.width(), screen_rect.height());
    }
    return screen_rect;
}

QRect ScreenShotWidgetPrivate::getDefaultRect(const QPoint & start, const QPoint & end)
{
    int rect_top = start.y() < end.y() ? start.y() : end.y();
    int rect_bottom = start.y() > end.y() ? start.y() : end.y();
    int rect_left = start.x() < end.x() ? start.x() : end.x();
    int rect_right = start.x() > end.x() ? start.x() : end.x();
    return QRect(QPoint(rect_left, rect_top), QPoint(rect_right, rect_bottom));
}

ScreenShotWidget::ScreenShotWidget(QWidget *parent):
    d_ptr(new ScreenShotWidgetPrivate(this, parent))
{
    Q_D(ScreenShotWidget);
    d->initProperty();
    d->initWidget();
    setAttribute(Qt::WA_DeleteOnClose);
    connect(d->m_screenshot_bar, SIGNAL(signal_ok_btnclick()), this, SLOT(slot_area_cut_done()));
    connect(d->m_screenshot_bar, SIGNAL(signal_cancel_btnclick()), this, SLOT(slot_close_cut()));
    connect(d->m_screenshot_bar, SIGNAL(signal_paint_property(PaintProperty)), this, SLOT(slot_screenbar_property(PaintProperty)));
    connect(d->m_painter_property_widget, SIGNAL(signal_paint_property(PaintProperty)), this, SLOT(slot_paint_property(PaintProperty)));
    connect(d->m_mark_widget, SIGNAL(signalUpdate()), this, SLOT(update()));
}

ScreenShotWidget::~ScreenShotWidget()
{

}

ScreenShotWidgetPrivate::BorderType ScreenShotWidget::stayCutAreaBorder(const QRect &rect, int border)
{
    QPoint pos = QCursor::pos();
    if(abs(pos.y() - rect.top()) < border && abs(pos.x() - rect.left()) < border)
    {
        setCursor(Qt::SizeFDiagCursor);
        return ScreenShotWidgetPrivate::TOP_LEFT;
    }
    else if(abs(pos.y() - rect.top()) < border && abs(pos.x() - rect.right()) < border)
    {
        setCursor(Qt::SizeBDiagCursor);
        return ScreenShotWidgetPrivate::TOP_RIGHT;
    }
    else if(abs(pos.y() - rect.bottom()) < border && abs(pos.x() - rect.left()) < border)
    {
        setCursor(Qt::SizeBDiagCursor);
        return ScreenShotWidgetPrivate::BOTTOM_LEFT;
    }
    else if(abs(pos.y() - rect.bottom()) < border && abs(pos.x() - rect.right()) < border)
    {
        setCursor(Qt::SizeFDiagCursor);
        return ScreenShotWidgetPrivate::BOTTOM_RIGHT;
    }
    else if(abs(pos.y() - rect.top()) < border && (pos.x() > rect.left()) && (pos.x() < rect.right()))
    {
        setCursor(Qt::SizeVerCursor);
        return ScreenShotWidgetPrivate::TOP;
    }
    else if(abs(pos.y() - rect.bottom()) < border && (pos.x() > rect.left()) && (pos.x() < rect.right()))
    {
        setCursor(Qt::SizeVerCursor);
        return ScreenShotWidgetPrivate::BOTTOM;
    }
    else if(abs(pos.x() - rect.left()) < border && (pos.y() > rect.top()) && (pos.y() < rect.bottom()))
    {
        setCursor(Qt::SizeHorCursor);
        return ScreenShotWidgetPrivate::LEFT;
    }
    else if(abs(pos.x() - rect.right()) < border && (pos.y() > rect.top()) && (pos.y() < rect.bottom()))
    {
        setCursor(Qt::SizeHorCursor);
        return ScreenShotWidgetPrivate::RIGHT;
    }
    else if(pos.x() > rect.left() && (pos.x() < rect.right()) &&
            pos.y() < rect.bottom() && pos.y() > rect.top())
    {
        setCursor(Qt::SizeAllCursor);
        return ScreenShotWidgetPrivate::ON_RECT;
    }
    setCursor(Qt::ArrowCursor);
    return ScreenShotWidgetPrivate::NOBORDER;
}

void ScreenShotWidget::slot_area_cut_done()
{
    Q_D(ScreenShotWidget);
//    QPixmap pic = QGuiApplication::primaryScreen()->grabWindow(QApplication::desktop()->winId(),  d->m_cut_area.left(), d->m_cut_area.top(), d->m_cut_area.width(), d->m_cut_area.height());
    QPixmap pic = QPixmap::fromImage(d->m_mark_widget->image().copy(d->m_cut_area));
    QString path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) + "/" + QDateTime::currentDateTime() .toString("yyyy-MM-dd-hh-mm-ss") + ".png";
    pic.save(path,  "PNG");
    qDebug() << "save image :" << path;
    slot_close_cut();
}

void ScreenShotWidget::slot_close_cut()
{
    Q_D(ScreenShotWidget);
    d->m_cut_state = ScreenShotWidgetPrivate::NONE;
    d->m_screenshot_bar->hide();
    d->m_cut_area.setRect(0, 0, 0, 0);
    d->m_mask_color.setAlpha(1);
    update();
    close();
}

void ScreenShotWidget::slot_screenbar_property(PaintProperty property)
{
    Q_D(ScreenShotWidget);
    d->m_paint_property = property;
    d->m_painter_property_widget->setPaintProperty(property);
    d->m_mark_widget->setPaintProperty(property);
}

void ScreenShotWidget::slot_paint_property(PaintProperty property)
{
    Q_D(ScreenShotWidget);
    d->m_paint_property = property;
    d->m_mark_widget->setPaintProperty(property);
}

bool ScreenShotWidget::event(QEvent *event)
{
    Q_D(ScreenShotWidget);
    if( d->m_mark_widget != nullptr)
        if(!d->m_mark_widget->handleEvent(event))
        {
            return true;
        }
    return  QWidget::event(event);
}

void ScreenShotWidget::mouseMoveEvent(QMouseEvent *event)
{
    Q_D(ScreenShotWidget);
    QPoint pickerPos(event->pos().x() + 10, event->pos().y() + 25);
    if(event->pos().x() + 10 + d->m_color_picker->width()> QApplication::desktop()->width())
    {
        pickerPos.setX(event->pos().x() - 10 - d->m_color_picker->width());
    }

    if(event->pos().y() + 25 +  d->m_color_picker->height()> QApplication::desktop()->height())
    {
        pickerPos.setY(event->pos().y() - 25 - d->m_color_picker->height());
    }
    d->m_color_picker->move(pickerPos);

    if(d->m_cut_state == ScreenShotWidgetPrivate::NONE)
    {
        ::EnableWindow((HWND)winId(), FALSE);
        getSmallestWindowFromCursor(d->m_cut_area);
        ::EnableWindow((HWND)winId(), TRUE);
    }
    else if(d->m_mouse_press && d->m_cut_state == ScreenShotWidgetPrivate::CUT)
    {
        d->m_cut_area = d->getDefaultRect(d->m_press_pos, event->pos());
    }
    else if(d->m_cut_state == ScreenShotWidgetPrivate::SAVE)
    {
//        static int i = 0;
//        qDebug() << "111111111111" << i ++ << event->pos() << d->m_mark_widget->touchShape(event->pos());
//        if(d->m_mark_widget->touchShape(event->pos()) && Shape::shapeList().count() != 0) return;
        if(!d->m_mouse_press)
        {
            stayCutAreaBorder(d->m_cut_area, 5);
        }
        else
        {
            int x_offset = event->pos().x() - d->m_press_pos.x();
            int y_offset = event->pos().y() - d->m_press_pos.y();
            int area_top = d->m_temp_rect.top() + y_offset;
            int area_bottom = d->m_temp_rect.bottom() + y_offset;
            int area_left = d->m_temp_rect.left() + x_offset;
            int area_right = d->m_temp_rect.right() + x_offset;

            switch (d->m_border_type) {
            case ScreenShotWidgetPrivate::TOP:
                d->m_cut_area.setTop(area_top);
                break;
            case ScreenShotWidgetPrivate::BOTTOM:
                d->m_cut_area.setBottom(area_bottom);
                break;
            case ScreenShotWidgetPrivate::LEFT:
                d->m_cut_area.setLeft(area_left);
                break;
            case ScreenShotWidgetPrivate::RIGHT:
                d->m_cut_area.setRight(area_right);
                break;
            case ScreenShotWidgetPrivate::TOP_LEFT:
                d->m_cut_area.setTop(area_top);
                d->m_cut_area.setLeft(area_left);
                break;
            case ScreenShotWidgetPrivate::TOP_RIGHT:
                d->m_cut_area.setTop(area_top);
                d->m_cut_area.setRight(area_right);
                break;
            case ScreenShotWidgetPrivate::BOTTOM_LEFT:
                d->m_cut_area.setBottom(area_bottom);
                d->m_cut_area.setLeft(area_left);
                break;
            case ScreenShotWidgetPrivate::BOTTOM_RIGHT:
                d->m_cut_area.setBottom(area_bottom);
                d->m_cut_area.setRight(area_right);
                break;
            case ScreenShotWidgetPrivate::ON_RECT:
            {
                if(area_top < 0)
                {
                    area_top = 0;
                    area_bottom = d->m_temp_rect.height();
                }
                if(area_bottom > QApplication::desktop()->height())
                {
                    area_bottom = QApplication::desktop()->height();
                    area_top = area_bottom - d->m_temp_rect.height();
                }
                if(area_left < 0)
                {
                    area_left = 0;
                    area_right = d->m_temp_rect.width();
                }
                if(area_right > QApplication::desktop()->width())
                {
                    area_right = QApplication::desktop()->width();
                    area_left = area_right - d->m_temp_rect.width();
                }

                d->m_cut_area.setTop(area_top);
                d->m_cut_area.setBottom(area_bottom);
                d->m_cut_area.setLeft(area_left);
                d->m_cut_area.setRight(area_right);
                break;
            }
            case ScreenShotWidgetPrivate::NOBORDER:
                d->m_screenshot_bar->show();
                break;
            default:
                break;
            }
        }
    }

    update();
    QWidget::mouseMoveEvent(event);
}

void ScreenShotWidget::mousePressEvent(QMouseEvent *event)
{
    Q_D(ScreenShotWidget);

    d->m_press_pos = event->pos();
    if(d->m_cut_state == ScreenShotWidgetPrivate::NONE)
    {
        d->m_cut_state = ScreenShotWidgetPrivate::CUT;
        d->m_mouse_press = true;
        d->m_mask_color.setAlpha(150);
    }
    else if( d->m_cut_state == ScreenShotWidgetPrivate::SAVE)
    {
        d->m_border_type = stayCutAreaBorder(d->m_cut_area, 10);
        d->m_temp_rect = d->m_cut_area;
        d->m_mouse_press = true;
        if( d->m_border_type != ScreenShotWidgetPrivate::NOBORDER)
            d->m_screenshot_bar->hide();
    }

    update();
    QWidget::mousePressEvent(event);
}

void ScreenShotWidget::mouseReleaseEvent(QMouseEvent *event)
{
    Q_D(ScreenShotWidget);
    QPoint point(d->m_cut_area.right() - d->m_screenshot_bar->width(), d->m_cut_area.bottom() + 10);
    d->m_mouse_press = false;
    if(d->m_cut_state == ScreenShotWidgetPrivate::CUT)
    {
        d->m_cut_state = ScreenShotWidgetPrivate::SAVE;
        d->m_color_picker->hide();
        if(d->m_cut_area.right() - d->m_screenshot_bar->width() < 0)
        {
            point.setX(d->m_cut_area.left());
        }

        if(d->m_cut_area.bottom() + 10 + d->m_screenshot_bar->height() > QApplication::desktop()->height())
        {
            point.setY(d->m_cut_area.top() - 10 - d->m_screenshot_bar->height());
            if(d->m_cut_area.top() - 10 - d->m_screenshot_bar->height() < 0)
            {
                point.setY(d->m_cut_area.bottom() - 10 - d->m_screenshot_bar->height());
            }
        }
    }
    else if( d->m_cut_state == ScreenShotWidgetPrivate::SAVE)
    {
        d->m_temp_rect =  d->m_cut_area;
        if(d->m_cut_area.right() - d->m_screenshot_bar->width() < 0)
        {
            point.setX(d->m_cut_area.left());
        }

        if(d->m_cut_area.bottom() + 10 + d->m_screenshot_bar->height() > QApplication::desktop()->height())
        {
            point.setY(d->m_cut_area.top() - 10 - d->m_screenshot_bar->height());
            if(d->m_cut_area.top() - 10 - d->m_screenshot_bar->height() < 0)
            {
                point.setY(d->m_cut_area.bottom() - 10 - d->m_screenshot_bar->height());
            }
        }
    }

    if(d->m_cut_state == ScreenShotWidgetPrivate::SAVE || d->m_cut_state == ScreenShotWidgetPrivate::CUT)
    {
        d->m_screenshot_bar->move(point);
        d->m_screenshot_bar->show();

        d->m_mark_widget->setCutArea(d->m_cut_area);
    }

    update();
    QWidget::mouseReleaseEvent(event);
}

void ScreenShotWidget::paintEvent(QPaintEvent *event)
{
    Q_D(ScreenShotWidget);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.drawImage(rect(), d->m_mark_widget->image());

    QPen pen(QColor(0, 0, 0, 0));
    QBrush brush(d->m_mask_color);
    painter.setPen(pen);
    painter.setBrush(brush);
    QPainterPath rect_path;
    rect_path.addRect(QRect(0, 0, width(), height()));
    if(d->m_mouse_press || d->m_cut_state != ScreenShotWidgetPrivate::NONE)
    {
        QPainterPath temp_path;
        temp_path.addRect(d->m_cut_area);
        rect_path = rect_path - temp_path;
    }
    painter.drawPath(rect_path);
    pen.setColor(Qt::green);
    pen.setWidth(2);
    painter.setPen(pen);
    brush.setColor(QColor(0, 0, 0, 1));
    painter.setBrush(brush);
    painter.drawRect(d->m_cut_area);

    int point_border = 6;
    int top = d->m_cut_area.top() - point_border / 2;
    int bottom = d->m_cut_area.bottom() - point_border / 2;
    int left = d->m_cut_area.left() - point_border / 2;
    int right = d->m_cut_area.right() - point_border / 2;
    int width = d->m_cut_area.width();
    int height = d->m_cut_area.height();
    QSize point_size(point_border, point_border);
    brush.setColor(Qt::green);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    painter.drawRect(QRect(QPoint(left, top), point_size));
    painter.drawRect(QRect(QPoint(left, top + height / 2), point_size));
    painter.drawRect(QRect(QPoint(right, top), point_size));
    painter.drawRect(QRect(QPoint(right, top +  height/ 2), point_size));
    painter.drawRect(QRect(QPoint(left, bottom), point_size));
    painter.drawRect(QRect(QPoint(right, bottom), point_size));
    painter.drawRect(QRect(QPoint(left + width / 2, bottom), point_size));
    painter.drawRect(QRect(QPoint(left + width / 2, top), point_size));

    brush.setColor(QColor(0, 0, 0));
    pen.setColor(QColor(255, 255, 255));
    painter.setPen(pen);
    painter.setBrush(brush);
    QString text = QString::number(d->m_cut_area.width()) + " x " +  QString::number(d->m_cut_area.height());
    painter.drawText(d->m_cut_area.left(), d->m_cut_area.top() - 15, text);
    QWidget::paintEvent(event);
}

void ScreenShotWidget::keyPressEvent(QKeyEvent *event)
{
    Q_D(ScreenShotWidget);
    if (event->key() == Qt::Key_Escape)
    {
        close();
    }
    QWidget::keyPressEvent(event);
}

void ScreenShotWidget::showEvent(QShowEvent *)
{
    Q_D(ScreenShotWidget);
    d->m_screenshot_bar->hide();

    QPoint pickerPos(QCursor::pos().x() + 10, QCursor::pos().y() + 25);
    d->m_color_picker->move(pickerPos);
    d->m_color_picker->show();
}

bool ScreenShotWidget::getSmallestWindowFromCursor(QRect& out_rect)
{
    HWND hwnd;
    POINT pt;
    ::GetCursorPos(&pt);
    hwnd = ::ChildWindowFromPointEx(::GetDesktopWindow(), pt, CWP_SKIPDISABLED | CWP_SKIPINVISIBLE);
    if (hwnd != NULL)
    {
        HWND temp_hwnd;
        temp_hwnd = hwnd;
        while (true)
        {
            ::GetCursorPos(&pt);
            ::ScreenToClient(temp_hwnd, &pt);
            temp_hwnd = ::ChildWindowFromPointEx(temp_hwnd, pt, CWP_ALL);
            if (temp_hwnd == NULL || temp_hwnd == hwnd)
                break;
            hwnd = temp_hwnd;
        }
        RECT temp_window;
        ::GetWindowRect(hwnd, &temp_window);
        out_rect.setRect(temp_window.left,temp_window.top,
                         temp_window.right - temp_window.left,
                         temp_window.bottom - temp_window.top);


        return true;
    }
    return false;
}

void ScreenShotWidget::showPaintPropertyWidget(const QPoint& point)
{
    Q_D(ScreenShotWidget);
    QPoint pos(point.x(), point.y() + 20);
    d->m_painter_property_widget->move(pos);
    d->m_painter_property_widget->show();
}

PaintPropertyWidget *ScreenShotWidget::getPropertyWidget()
{
    Q_D(ScreenShotWidget);
    return d->m_painter_property_widget;
}

bool ScreenShotWidget::getCurrentWindowFromCursor(QRect &out_rect)
{
    HWND hwnd;
    POINT pt;

    ::GetCursorPos(&pt);

    hwnd = ::ChildWindowFromPointEx(::GetDesktopWindow(), pt, CWP_SKIPDISABLED | CWP_SKIPINVISIBLE);
    if (hwnd != NULL) {
        RECT temp_window;
        ::GetWindowRect(hwnd, &temp_window);
        out_rect.setRect(temp_window.left, temp_window.top,
                         temp_window.right - temp_window.left,
                         temp_window.bottom - temp_window.top);
        return true;
    }
    return false;
}

