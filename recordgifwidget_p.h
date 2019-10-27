#ifndef RECORDGIFWIDGET_P_H
#define RECORDGIFWIDGET_P_H

#include <QDialog>
#include <QRect>
#include "gif.h"

namespace tools {
    class FramelessHelper;
}
class GifRecordThread;
class QLineEdit;
class QLabel;
class GifBar;
class RecordGifWidget;
class RecordGifWidgetPrivate
{
    Q_DECLARE_PUBLIC(RecordGifWidget)
public:
    explicit RecordGifWidgetPrivate(RecordGifWidget *widget = nullptr, QWidget *parent = nullptr);
    ~RecordGifWidgetPrivate();

    void init();

    QWidget *m_main_widget;
    QRect m_record_rect;
    GifBar *m_gif_bar;
    QWidget *m_test_widget;
    tools::FramelessHelper *m_frameless_helper;
    RecordGifWidget *q_ptr;

    GifRecordThread *m_gif_thread;
};
#endif
