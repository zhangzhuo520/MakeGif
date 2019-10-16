#ifndef RECORDGIFWIDGET_H
#define RECORDGIFWIDGET_H
#include <QWidget>
class RecordGifWidgetPrivate;
class RecordGifWidget : public QWidget
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(RecordGifWidget)
public:
    explicit RecordGifWidget(QWidget *parent  = nullptr);
    ~RecordGifWidget();

 private:
    RecordGifWidgetPrivate *d_ptr;
};

#endif // RECORDGIFWIDGET_H
