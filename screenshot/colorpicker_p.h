#ifndef COLORPICKER_P_H
#define COLORPICKER_p_H
#include <QObject>
#include <QPixmap>
class QPixmap;
class ColorPicker;
class QScreen;
class QThread;
class GrabImageWorker;
class ColorPickerPrivate : public QObject
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(ColorPicker)

public:
    explicit ColorPickerPrivate(ColorPicker *widget = nullptr, QSharedPointer <QPixmap> screen = nullptr);
    ~ColorPickerPrivate();

    void init();

    QColor m_select_color;
    ColorPicker *q_ptr;
    QSharedPointer <QPixmap> m_screen_pixmap;
};

#endif // COLORPICKER_p_H
