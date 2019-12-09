#ifndef COLORLABEL_H
#define COLORLABEL_H
#include <QLabel>
#include <QColor>

class QPaintEvent;
class QMouseEvent;
class QEvent;

class ColorLabel : public QLabel
{
    Q_OBJECT
public:
   explicit  ColorLabel(QWidget *parent,  const QColor & color);
    ~ColorLabel();
    void setSelect(bool);
    bool select();

protected:
    virtual void paintEvent(QPaintEvent *);
    virtual void mousePressEvent(QMouseEvent *);
    virtual void enterEvent(QEvent *);
    virtual void leaveEvent(QEvent *);

signals:
    void signalSelectColor(QColor);

 private:
    QColor m_color;
    bool m_select;
    bool m_enter;
};

#endif // COLORLABEL_H
