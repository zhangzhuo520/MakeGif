#ifndef APPINIT_H
#define APPINIT_H

#include <QObject>
#include <QPoint>

namespace  tools {

class AppInit : public QObject
{
    Q_OBJECT
public:
    explicit AppInit(QObject *parent = 0);

    void loadInfo();

private:
    QPoint m_mouse_point;
    bool m_mouse_pressed;

protected:
    bool eventFilter(QObject *obj, QEvent *evt);

signals:

public slots:
};

}
#endif // APPINIT_H
