#ifndef COLORPICKER_H
#define COLORPICKER_H
#include <QWidget>
#include <qsharedpointer.h>
class ColorPickerPrivate;
class QPaintEvent;
class QMoveEvent;
class QShowEvent;
class QScreen;

const int ColorPickWidth = 150;
const int ColorPickheight = 150;
const int multiple = 5;
class ColorPicker: public QWidget
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(ColorPicker)

public:
    explicit ColorPicker(QWidget *parent = nullptr, QSharedPointer <QPixmap> screen = nullptr);
    ~ColorPicker();

    virtual void moveEvent(QMoveEvent *event);
    virtual void paintEvent(QPaintEvent *event);

private:
    ColorPickerPrivate *d_ptr;
    QPixmap *m_screen_pixmap;
};

#endif // COLORPICKER_H
