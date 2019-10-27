#ifndef MAINWIDGET_P_H
#define MAINWIDGET_P_H
#include <QObject>

class MainWidget;
class ImageLabel;
class PushButton;
class ScreenShotWidget;
class RecordGifWidget;
class ScreenShotBar;
class GifBar;
class MainWidgetPrivate:public QObject
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(MainWidget)
    enum recordMode{
        RECORD_GIF,
        RECORD_PIC,
        NONE
    };
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
    RecordGifWidget *m_recordgif_widget;
    recordMode m_record_mode;
};

#endif // MAINWIDGET_P_H
