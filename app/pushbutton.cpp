#include "pushbutton.h"
#include <QtWidgets/QSizePolicy>
PushButton::PushButton(QWidget *parent):
    QPushButton(" ", parent)
{
}

PushButton::PushButton(const QString &text, QWidget *parent):
    QPushButton(text, parent)
{

}

PushButton::PushButton(const QIcon &icon, const QString &text, QWidget *parent):
        QPushButton(icon, text, parent)
{

}

PushButton::~PushButton()
{

}
