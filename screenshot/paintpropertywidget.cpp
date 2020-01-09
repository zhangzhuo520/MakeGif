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
    connect(m_color_widget, SIGNAL(signal_select_color(QColor)), this, SLOT(slot_select_color(QColor)));
    connect(m_width_widget, SIGNAL(singal_select_width(int)), this, SLOT(slot_select_width(int)));
}

PaintPropertyWidget::~PaintPropertyWidget()
{

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
