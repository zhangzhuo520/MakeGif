#ifndef SCREENSHOTWIDGET_H
#define SCREENSHOTWIDGET_H
#include <QWidget>

class MainWidget;
class ScreenShotWidgetPrivate;
class QPaintEvent;
class QMouseEvent;
class ScreenShotWidget : public QWidget
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(ScreenShotWidget)
public:
    explicit ScreenShotWidget(QWidget *paren = nullptr);
    ~ScreenShotWidget();

public slots:
    void slot_area_cut_done();

protected:
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void paintEvent(QPaintEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);


private:
    ScreenShotWidgetPrivate *d_ptr;
};

#endif // SCREENSHOTWIDGET_H
