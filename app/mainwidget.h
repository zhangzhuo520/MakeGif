#ifndef MAINWIDGET_H
#define MAINWIDGET_H
#include <QWidget>
#include "app_global.h"
class MainWidgetPrivate;
class QKeyEvent;
class APP_EXPORT MainWidget : public QWidget
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(MainWidget)
public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

public slots:
    void slot_screen_shot();
    void slot_record_gif();

protected:
//    virtual void keyPressEvent(QKeyEvent *event);

private:
    MainWidgetPrivate *d_ptr;
};

#endif // MAINWIDGET_H
