#ifndef RECORDGIFWIDGET_H
#define RECORDGIFWIDGET_H
#include <QWidget>
class RecordGifWidgetPrivate;
class RecordGifWidget : public QWidget
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(RecordGifWidget)
    Q_PROPERTY(int borderWidth READ getBorderWidth WRITE setBorderWidth)
    Q_PROPERTY(QColor bgColor READ getBgColor WRITE setBgColor)
public:
    explicit RecordGifWidget(QWidget *parent  = nullptr);
    ~RecordGifWidget();


    static GifWidget *Instance();
    explicit GifWidget(QWidget *parent = 0);

public Q_SLOTS:
    void setBorderWidth(int borderWidth);
    void setBgColor(const QColor &bgColor);

protected:
    bool eventFilter(QObject *watched, QEvent *event);
    void resizeEvent(QResizeEvent *);
    void paintEvent(QPaintEvent *);

private:
    RecordGifWidgetPrivate *d_ptr;
};


