#include "widthwidget.h"
#include "widthlabel.h"
#include <QHBoxLayout>
WidthWidget::WidthWidget(QWidget *parent):
    QWidget(parent)
{
    initWidgets();
}

void WidthWidget::initWidgets()
{
    QHBoxLayout *hbox = new QHBoxLayout;
    m_thin_label = new WidthLabel(this, 1);
    m_thin_label->setObjectName("Thin");
    m_normal_label = new WidthLabel(this, 2);
    m_normal_label->setObjectName("Normal");
    m_thick_label = new WidthLabel(this, 3);
    m_thick_label->setObjectName("Thick");
    hbox->addWidget(m_thin_label);
    hbox->addWidget(m_normal_label);
    hbox->addWidget(m_thick_label);
    setLayout(hbox);
    connect(m_thin_label, SIGNAL(signalSelectChange()), this, SLOT(slotSelectChange()));
    connect(m_normal_label, SIGNAL(signalSelectChange()), this, SLOT(slotSelectChange()));
    connect(m_thick_label, SIGNAL(signalSelectChange()), this, SLOT(slotSelectChange()));
}

WidthWidget::~WidthWidget()
{

}

void WidthWidget::slotSelectChange()
{
    int width = 0;
   if(sender()->objectName() == "Thin")
   {
       m_normal_label->setSelect(false);
       m_thick_label->setSelect(false);
       width = 1;
   }
   else if(sender()->objectName() == "Thick")
   {
       m_normal_label->setSelect(false);
       m_thin_label->setSelect(false);
       width = 2;
   }
   else if(sender()->objectName() == "Normal")
   {
       m_thin_label->setSelect(false);
       m_thick_label->setSelect(false);
       width = 3;
   }

   emit singal_select_width(width);
}
