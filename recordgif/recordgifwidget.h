#ifndef RECORDGIFWIDGET_H
#define RECORDGIFWIDGET_H
#include <QtWidgets/QWidget>
#include "recordgif_global.h"
class RecordGifWidgetPrivate;
class RECORDGIF_EXPORT RecordGifWidget : public QWidget
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(RecordGifWidget)
public:
    explicit RecordGifWidget(QWidget *parent  = nullptr);
    ~RecordGifWidget();
    void updateRecordRect();

public slots:
    void slotStartRecord();
    void slotPauseRecord();
    void slotStopRecord();

    void slotXChange(const QString&);
    void slotYChange(const QString&);
    void slotFpsChange(const QString&);
    void slotFrameCount(int);

protected:
    void resizeEvent(QResizeEvent *);
    void paintEvent(QPaintEvent *);
    void moveEvent(QMoveEvent *);

private:
    void regeomtry();
    RecordGifWidgetPrivate *d_ptr;
};
#endif

