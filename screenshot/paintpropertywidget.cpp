#include "paintpropertywidget.h"
#include "colormanagerwidget.h"
#include "widthwidget.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QGraphicsDropShadowEffect>
#include <QHBoxLayout>

const int SHADOW_WIDTH = 15;
const int TRIANGLE_WIDTH = 24;
const int TRIANGLE_HEIGHT = 14;
const int BORDER_RADIUS = 5;

PaintPropertyWidget::PaintPropertyWidget(QWidget *parent):
    AbstractPropertyWidget(parent)
{
    initWidgets();
    connect(m_color_widget, SIGNAL(signalSelectColor(QColor)), this, SLOT(slotSelectColor(QColor)));
    connect(m_width_widget, SIGNAL(signalSelectWidth(int)), this, SLOT(slotSelectWidth(int)));
}

PaintPropertyWidget::~PaintPropertyWidget()
{

}

void PaintPropertyWidget::slotSelectColor(QColor color)
{
    m_paint_property.color = color;
    emit signalPaintProperty(m_paint_property);
}

void PaintPropertyWidget::slotSelectWidth(int width)
{
    m_paint_property.width = width;
    emit signalPaintProperty(m_paint_property);
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
