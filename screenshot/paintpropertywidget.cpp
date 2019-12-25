#include "paintpropertywidget.h"
#include "colormanagerwidget.h"
#include "widthwidget.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QGraphicsDropShadowEffect>
#include <QHBoxLayout>
const int SHADOW_WIDTH = 15;                 // 窗口阴影宽度;
const int TRIANGLE_WIDTH = 24;               // 小三角的宽度;
const int TRIANGLE_HEIGHT = 14;              // 小三角的高度;
const int BORDER_RADIUS = 5;                 // 窗口边角的弧度;

PaintPropertyWidget::PaintPropertyWidget(QWidget *parent):
    QWidget(parent),
    m_startx(40),
    m_trianglewidth(TRIANGLE_WIDTH),
    m_triangleheight(TRIANGLE_HEIGHT)
{
    setWindowFlags(Qt::FramelessWindowHint);
    initShadoweffect();
    initWidgets();
    connect(m_color_widget, SIGNAL(signal_select_color(QColor)), this, SLOT(slot_select_color(QColor)));
    connect(m_width_widget, SIGNAL(singal_select_width(int)), this, SLOT(slot_select_width(int)));
}

PaintPropertyWidget::~PaintPropertyWidget()
{

}

void PaintPropertyWidget::setPaintProperty(const PaintProperty & property)
{
    m_paint_property = property;
}

void PaintPropertyWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(255, 255, 255, 200));    // 小三角区域;
    QPainterPath painterPath;
    QPolygon trianglePolygon;

    trianglePolygon << QPoint(m_startx, m_triangleheight + SHADOW_WIDTH);
    trianglePolygon << QPoint(m_startx + m_trianglewidth / 2, SHADOW_WIDTH);
    trianglePolygon << QPoint(m_startx + m_trianglewidth, m_triangleheight + SHADOW_WIDTH);
    painterPath.addRoundedRect(QRect(SHADOW_WIDTH, m_triangleheight + SHADOW_WIDTH,\
                            width() - SHADOW_WIDTH * 2, height() - SHADOW_WIDTH * 2 - m_triangleheight),\
                            BORDER_RADIUS, BORDER_RADIUS);

    painterPath.addPolygon(trianglePolygon);
    painter.drawPath(painterPath);
}

void PaintPropertyWidget::slot_select_color(QColor color)
{
    m_paint_property.color = color;
    emit signal_paint_property(m_paint_property);
}

void PaintPropertyWidget::slot_select_width(int width)
{
    m_paint_property.width = width;
    emit signal_paint_property(m_paint_property);
}

void PaintPropertyWidget::initShadoweffect()
{
    m_shadoweffect = new QGraphicsDropShadowEffect(this);
    m_shadoweffect->setOffset(0, 0);
    m_shadoweffect->setColor(Qt::gray);
    m_shadoweffect->setBlurRadius(SHADOW_WIDTH);
    setGraphicsEffect(m_shadoweffect);
}

void PaintPropertyWidget::initWidgets()
{
    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->setContentsMargins(20, 33, 20, 18);
    hbox->setSpacing(0);
    m_color_widget = new ColorManagerWidget(this);
    m_width_widget = new WidthWidget(this);
    hbox->addWidget(m_width_widget);
    hbox->addWidget(m_color_widget);
    hbox->setStretch(0, 1);
    hbox->setStretch(1, 3);
    setLayout(hbox);
}
