#include "textwidget.h"
#include "../widgets/combobox.h"
#include "../widgets/label.h"

#include <QHBoxLayout>
TextWidget::TextWidget(QWidget *parent):
    QWidget(parent)
{
    initUi();
}

TextWidget::~TextWidget()
{

}

void TextWidget::initUi()
{
    m_label = new Label(this);
    m_label->setObjectName("TextLabel");
    m_combobox = new Combobox(this);
    for(int i = 9; i < 23; i ++)
        m_combobox->addItem(QString::number(i));
    m_combobox->setObjectName("TextCombobox");
    QHBoxLayout *hboxlayout = new QHBoxLayout;
    hboxlayout->setContentsMargins(0, 0, 0, 0);
    hboxlayout->setSpacing(0);
    hboxlayout->addWidget(m_label);
    hboxlayout->addWidget(m_combobox);
    setLayout(hboxlayout);

    connect(m_combobox, SIGNAL(currentIndexChanged(QString)), this, SLOT(slotTextSize(QString)));
}

void TextWidget::slotTextSize(QString string)
{
    emit signalTextSize(string);
}
