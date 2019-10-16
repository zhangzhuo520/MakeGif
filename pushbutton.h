#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H
#include <QPushButton>

class PushButton : public QPushButton
{
public:
   explicit  PushButton(QWidget *parent = nullptr);
    ~PushButton();
};

#endif // PUSHBUTTON_H
