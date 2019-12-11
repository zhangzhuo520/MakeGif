#include "gifbar.h"
#include "appinit.h"
#include <QString>
#include <QPushButton>
#include <QHBoxLayout>
#include <QPainter>
#include <QDebug>
#include <QLabel>
#include <QLineEdit>
#include <QSpacerItem>
GifBar::GifBar(QWidget *parent):
    QWidget(parent),
    m_record_flag(false)
{
    QHBoxLayout *hlayout = new QHBoxLayout(this);
    hlayout->setMargin(3);
    hlayout->setSpacing(10);
    m_fps_label = new QLabel("FPS: ", this);
    m_fps_edit = new QLineEdit(this);
    m_fps_edit->setText("25");
    m_xlabel = new QLabel("Width :", this);
    m_xedit = new QLineEdit(this);
    m_xedit->setText("800");
    m_ylabel = new QLabel("Height: ", this);
    m_yedit = new QLineEdit(this);
    m_yedit->setText("600");
    m_record_info = new QLabel(this);
    m_start_button = new QPushButton("Start", this);
    m_stop_button = new QPushButton("Stop", this);

    hlayout->addWidget(m_fps_label);
    hlayout->addWidget(m_fps_edit);
    hlayout->addSpacerItem(new QSpacerItem(300, 20, QSizePolicy::Expanding));
    hlayout->addWidget(m_xlabel);
    hlayout->addWidget(m_xedit);
    hlayout->addWidget(m_ylabel);
    hlayout->addWidget(m_yedit);
    hlayout->addSpacerItem(new QSpacerItem(300, 20, QSizePolicy::Expanding));
    hlayout->addWidget(m_record_info);
    hlayout->addWidget(m_start_button);
    hlayout->addWidget(m_stop_button);

    connect(m_start_button, SIGNAL(pressed()), SLOT(slotStartClick()));
    connect(m_stop_button, SIGNAL(pressed()), this, SLOT(slotStopClick()));
    connect(m_xedit, SIGNAL(textChanged(QString)), SIGNAL(signalXChange(QString)));
    connect(m_yedit, SIGNAL(textChanged(QString)), SIGNAL(signalYChange(QString)));
    connect(m_fps_edit, SIGNAL(textChanged(QString)), SIGNAL(signalFpsChange(QString)));
}

GifBar::~GifBar()
{

}

void GifBar::setRecordWidth(const QString & width)
{
    m_xedit->setText(width);
}

QString GifBar::recordWidth()
{
    return m_xedit->text();
}

void GifBar::setRecordHeight(const QString &height)
{
    m_yedit->setText(height);
}

QString GifBar::recordHeight()
{
    return m_yedit->text();
}

QString GifBar::fps()
{
    return m_fps_edit->text();
}

void GifBar::setRecordInfo(const QString &str)
{
    m_record_info->setText(str);
}

void GifBar::slotStartClick()
{
if(m_record_flag)
{
    m_start_button->setText("Start");
    m_record_flag = false;
    emit pauseRecord();
}
else
{
    emit startRecord();
    m_start_button->setText("Pause");
    m_record_flag = true;
}

}

void GifBar::slotStopClick()
{
    m_record_flag = false;
    m_start_button->setText("Start");
    emit stopRecord();
}

void GifBar::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setBrush(Qt::white);
    painter.drawRect(0, 0, width(), height());
}
