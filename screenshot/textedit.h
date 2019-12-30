#ifndef TEXTEDIT_H
#define TEXTEDIT_H
#include <QLineEdit>

class TextEdit : public QLineEdit
{
public:
    explicit TextEdit(QWidget *parent = nullptr);
    ~TextEdit();
};

#endif // TEXTEDIT_H
