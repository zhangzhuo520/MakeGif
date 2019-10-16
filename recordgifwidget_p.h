#ifndef RECORDGIFWIDGET_P_H
#define RECORDGIFWIDGET_P_H
#include <QObject>
class RecordGifWidget;
class RecordGifWidgetPrivate
{
    Q_DECLARE_PUBLIC(RecordGifWidget)
public:
    explicit RecordGifWidgetPrivate(RecordGifWidget *widget);
    ~RecordGifWidgetPrivate();

    RecordGifWidget *q_ptr;

};

#endif // RECORDGIFWIDGET_P_H
