#include "textpropertywidget.h"
#include "../widgets/combobox.h"
#include "../widgets/label.h"
#include "textwidget.h"
#include "colormanagerwidget.h"
#include <QHBoxLayout>

TextPropertyWidget::TextPropertyWidget(QWidget *parent):
    AbstractPropertyWidget(parent)
{
    initUi();
}

TextPropertyWidget::~TextPropertyWidget()
{

}

void TextPropertyWidget::initUi()
{
    QHBoxLayout *hboxlayout = new QHBoxLayout;
    hboxlayout->setContentsMargins(20, 33, 20, 18);
    hboxlayout->setSpacing(0);
    m_colormanger_widget = new ColorManagerWidget(this);
    m_textwidget = new TextWidget(this);
    hboxlayout->addWidget(m_textwidget);
    hboxlayout->addWidget(m_colormanger_widget);
    hboxlayout->setStretch(0, 1);
    hboxlayout->setStretch(1, 3);
    setLayout(hboxlayout);

    connect(m_colormanger_widget, SIGNAL(signalSelectColor(QColor)), this, SLOT(slotSelectColor(QColor)));
    connect(m_textwidget, SIGNAL(signalTextSize(QString)), this, SLOT(slotSelectSize(QString)));
}

void TextPropertyWidget::slotSelectColor(QColor color)
{
    m_paint_property.color = color;
   emit signalPaintProperty(m_paint_property);
}

void TextPropertyWidget::slotSelectSize(QString size)
{
    m_paint_property.width = size.toInt();
   emit signalPaintProperty(m_paint_property);
}

