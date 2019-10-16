#ifndef MAINWIDGET_P_H
#define MAINWIDGET_P_H
#include <QObject>

class MainWidget;
class ImageLabel;
class PushButton;
class ScreenShotWidget;
class MainWidgetPrivate
{
    Q_DECLARE_PUBLIC(MainWidget)
public:
    explicit MainWidgetPrivate(MainWidget *widget = nullptr);
    ~MainWidgetPrivate();

    void initProperty();
    void initUi();

private:
    MainWidget *q_ptr;
    ImageLabel *m_image_label;
    PushButton *m_screenshot_btn;
    PushButton *m_recordgif_btn;
    ScreenShotWidget *m_screenshot_widget;
};

#endif // MAINWIDGET_P_H
