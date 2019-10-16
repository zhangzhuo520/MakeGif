#include "recordgifwidget.h"
#include "recordgifwidget_p.h"

RecordGifWidgetPrivate::RecordGifWidgetPrivate(RecordGifWidget *widget):
    q_ptr(widget)
{

}

RecordGifWidget::RecordGifWidget(QWidget *parent):
    d_ptr(new RecordGifWidgetPrivate(this))
{

}

RecordGifWidget::~RecordGifWidget()
{

}
