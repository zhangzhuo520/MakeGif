#ifndef LABEL_H
#define LABEL_H
#include <QLabel>

class Label : public QLabel
{
    Q_OBJECT
public:
    explicit Label(QWidget *parent = nullptr);
    ~Label();
};

#endif // LABEL_H
