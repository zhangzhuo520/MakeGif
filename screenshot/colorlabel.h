#ifndef COLORLABEL_H
#define COLORLABEL_H
#include <QLabel>
#include <QColor>

class QPaintEvent;
class ColorLabel : public QLabel
{
public:
   explicit  ColorLabel(QWidget *parent,  const QColor & color);
    ~ColorLabel();

    virtual void paintEvent(QPaintEvent *);

signals:
    void signalSelectColor(QColor);

 private:
    QColor m_color;
};

#endif // COLORLABEL_H
