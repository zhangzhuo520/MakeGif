#include "textedit.h"
#include <QPainter>

TextEdit::TextEdit(QWidget *parent):
    QLineEdit(parent)
{
    setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setStyleSheet("background:transparent;"\
                                      "border-width:0;"\
                                      "border-color:rgb(255, 0, 0);"\
                                      "font:red thin italic 18px \"Timers\";");
    resize(100, 50);
}

TextEdit::~TextEdit()
{

}

