#include "abstractpropertywidget.h"
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

AbstractPropertyWidget::AbstractPropertyWidget(QWidget *parent):
    QWidget(parent),
    m_startx(40),
    m_trianglewidth(TRIANGLE_WIDTH),
    m_triangleheight(TRIANGLE_HEIGHT)
{
    setWindowFlags(Qt::FramelessWindowHint);
    initShadoweffect();
}

AbstractPropertyWidget::~AbstractPropertyWidget()
{

}

void AbstractPropertyWidget::initShadoweffect()
{
    m_shadoweffect = new QGraphicsDropShadowEffect(this);
    m_shadoweffect->setOffset(0, 0);
    m_shadoweffect->setColor(Qt::gray);
    m_shadoweffect->setBlurRadius(SHADOW_WIDTH);
    setGraphicsEffect(m_shadoweffect);
}

void AbstractPropertyWidget::setPaintProperty(const PaintProperty & property)
{
    m_paint_property = property;
}

void AbstractPropertyWidget::paintEvent(QPaintEvent *)
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


