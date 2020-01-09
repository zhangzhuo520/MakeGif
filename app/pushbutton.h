#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H
#include <QPushButton>
#include "app_global.h"
class APP_EXPORT PushButton : public QPushButton
{
    Q_OBJECT
//    Q_PROPERTY(bool selected READ check WRITE setChecked)
public:
   explicit  PushButton(QWidget *parent = Q_NULLPTR);
   PushButton(const QString &text, QWidget *parent = Q_NULLPTR);
   PushButton(const QIcon& icon, const QString &text, QWidget *parent = Q_NULLPTR);
    ~PushButton();
};

#endif // PUSHBUTTON_H
