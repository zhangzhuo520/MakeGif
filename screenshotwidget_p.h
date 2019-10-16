#ifndef SCREENSHOTWIDGET_P_H
#define SCREENSHOTWIDGET_P_H
#include <QObject>
#include <QRect>
class ScreenShotWidget;
class MainWidget;
class QLabel;
class ScreenShotWidgetPrivate
{
    Q_DECLARE_PUBLIC(ScreenShotWidget)
public:
    explicit ScreenShotWidgetPrivate(ScreenShotWidget *widget = nullptr, QWidget *parent = nullptr);
    ~ScreenShotWidgetPrivate();

    void init();

    ScreenShotWidget *q_ptr;
    MainWidget *m_main_widget;
    QLabel *m_label;
    bool m_mouse_press;
    bool m_cut_done;
    QRect m_cut_area;
    QPoint m_mouse_pos;
};

#endif // SCREENSHOTWIDGET_P_H
