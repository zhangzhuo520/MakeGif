#ifndef SCREENSHOTWIDGET_H
#define SCREENSHOTWIDGET_H
#include <QtWidgets/QWidget>
#include "screenshotwidget_p.h"
class MainWidget;
class ScreenShotWidgetPrivate;
class QPaintEvent;
class QMouseEvent;
class QShowEvent;
class ScreenShotWidget : public QWidget
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(ScreenShotWidget)
public:
    explicit ScreenShotWidget(QWidget *paren = nullptr);
    ~ScreenShotWidget();
    ScreenShotWidgetPrivate::BorderType stayCutAreaBorder(const QRect &, int);

    bool getCurrentWindowFromCursor(QRect &out_rect);

    bool getSmallestWindowFromCursor(QRect& out_rect);

    void showPropertyWidget(const QPoint&);

public slots:
    void slotAreaCutdone();
    void slotCloseCut();
    void slotScreenbarProperty(PaintProperty);
    void slotPaintProperty(PaintProperty);

protected:
    bool event(QEvent *event) Q_DECL_OVERRIDE;
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void paintEvent(QPaintEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void showEvent(QShowEvent *event);


private:
    ScreenShotWidgetPrivate *d_ptr;
};

#endif // SCREENSHOTWIDGET_H
