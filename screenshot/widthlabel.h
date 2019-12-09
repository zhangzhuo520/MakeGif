#ifndef WIDTHLABEL_H
#define WIDTHLABEL_H
#include <QLabel>
#include <QColor>
#include <QEnterEvent>
class QPaintEvent;
class QMouseEvent;
class WidthLabel : public QLabel
{
    Q_OBJECT
public:
    explicit WidthLabel(QWidget *parent = nullptr, int level = 0);
    ~WidthLabel();
    void setSelect(bool);
    bool select();

signals:
    void signalSelectChange();

protected:
    virtual void paintEvent(QPaintEvent *);
    virtual void mousePressEvent(QMouseEvent *);
    virtual void enterEvent(QEvent *event);
    virtual void leaveEvent(QEvent *event);

private:
    int m_level;
    QColor m_color;
    bool m_select;
};

#endif // WIDTHLABEL_H
