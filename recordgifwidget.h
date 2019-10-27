#ifndef RECORDGIFWIDGET_H
#define RECORDGIFWIDGET_H
#include <QDialog>
class RecordGifWidgetPrivate;
class RecordGifWidget : public QWidget
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(RecordGifWidget)
public:
    explicit RecordGifWidget(QWidget *parent  = nullptr);
    ~RecordGifWidget();
    QRect recordRect();

public slots:
    void slotStartRecord();
    void slotPauseRecord();
    void slotStopRecord();

    void slot

protected:
    bool eventFilter(QObject *watched, QEvent *event);
    void resizeEvent(QResizeEvent *);
    void paintEvent(QPaintEvent *);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void showEvent(QShowEvent *);

private:
    void regeomtry();
    RecordGifWidgetPrivate *d_ptr;
};
#endif

