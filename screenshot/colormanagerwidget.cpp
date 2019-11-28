#include "colormanagerwidget.h"
#include "colorlabel.h"
#include <QHBoxLayout>
ColorManagerWidget::ColorManagerWidget(QWidget *paren)
{
    m_color_list  << QColor(0, 0, 0)
                   << QColor(51, 51, 51)
                   << QColor(102, 102, 102)
                   << QColor(153, 153, 153)
                   << QColor(204, 204, 204)
                   << QColor(221, 221, 221)
                   << QColor(238, 238, 238)
                   << QColor(255, 255, 255)

                   << QColor(139, 0, 0)
                   << QColor(154, 205, 50)
                   << QColor(175, 238, 238)
                   << QColor(0, 191, 255)
                   << QColor(139, 69, 19)
                   << QColor(102, 205,170)
                   << QColor(123, 104,238)
                   << QColor(0,0,205)


                   << QColor(85,107,47)
                   << QColor(100,149,237)
                   << QColor(218,112,214)
                   << QColor(148,0,211)
                   << QColor(107, 142, 35)
                   << QColor(147, 112, 219)
                   << QColor(220,20,60)
                   << QColor(255,0,0)

                   << QColor(32, 178,170)
                   << QColor(238,130,238)
                   << QColor(255, 105,180)
                   << QColor(255,0,255)
                   << QColor(70,130,180)
                   << QColor(255,182,193)
                   << QColor(255, 140, 0)
                   << QColor(0,0,255)
                   << QColor(139, 0, 139)
                   << QColor(230, 145, 56)
                   << QColor(255, 215, 0)
                   << QColor(0, 128, 0)
                   << QColor(79, 80, 81)
                   << QColor(192,197,204)
                   << QColor(210, 105, 30)
                   << QColor(240, 230, 140)

                   << QColor(50,205,50)
                   << QColor(0, 255, 0)
                   << QColor(218, 165, 32)
                   << QColor(127, 255, 212)
                   << QColor(0, 128, 128)
                   << QColor(8, 83, 148)
                   << QColor(52, 28, 117)
                   << QColor(255, 255, 0)

                   << QColor(102, 0, 0)
                   << QColor(120, 63, 4)
                   << QColor(127, 96, 0)
                   << QColor(39, 78, 19)
                   << QColor(12, 52, 61)
                   << QColor(7, 55, 99)
                   << QColor(32, 18, 77)
                   << QColor(71, 17, 48);
}

void ColorManagerWidget::initColorLabel()
{
    QHBoxLayout *layout = new QHBoxLayout;
    layout->setMargin(2);
    layout->setSpacing(0);
    for(int i = 0; i < 10; i ++)
    {
        m_colorlabel_list.append(new ColorLabel(this, m_colorlabel_list.at(i)));
        connect(m_colorlabel_list[i], SIGNAL(signalSelectColor(QColor)), this, SLOT(slotSelectColor(QColor)));
        layout->addWidget(m_colorlabel_list[i]);
    }
    setLayout(layout);
}

ColorManagerWidget::~ColorManagerWidget()
{

}
