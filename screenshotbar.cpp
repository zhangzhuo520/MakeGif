#include "screenshotbar.h"
#include <QLabel>
#include "pushbutton.h"
#include <QHBoxLayout>



ScreenShotBar::ScreenShotBar(QWidget *parent):
    QWidget(parent)
{
    initUi();
}

ScreenShotBar::~ScreenShotBar()
{

}

void ScreenShotBar::initUi()
{
    QHBoxLayout *hlayout = new QHBoxLayout(this);
    m_ok_btn = new PushButton("OK", this);
    m_cancel_btn = new PushButton("Cancel", this);
    hlayout->addWidget(m_cancel_btn);
    hlayout->addWidget(m_ok_btn);
    setLayout(hlayout);
    connect(m_ok_btn, SIGNAL(pressed()), this, SIGNAL(signal_ok_btnclick()));
    connect(m_cancel_btn, SIGNAL(pressed()), this, SIGNAL(signal_cancel_btnclick()));
}
