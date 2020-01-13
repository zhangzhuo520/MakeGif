#ifndef SCREENSHOTWIDGET_P_H
#define SCREENSHOTWIDGET_P_H
#include <QObject>
#include <QRect>
#include "datastruct.h"

class ScreenShotWidget;
class MainWidget;
class QLabel;
class ScreenShotBar;
class QScreen;
class ColorPicker;
class MarkWidget;
class PaintPropertyWidget;
class TextPropertyWidget;
class ScreenShotWidgetPrivate
{
    Q_DECLARE_PUBLIC(ScreenShotWidget)
public:
    enum CutState{
        NONE,
        CUT,
        SAVE
    };

    enum BorderType
    {
        TOP = 0,
        BOTTOM,
        LEFT,
        RIGHT,
        TOP_LEFT,
        TOP_RIGHT,
        BOTTOM_LEFT,
        BOTTOM_RIGHT,
        ON_RECT,
        NOBORDER
    };


    explicit ScreenShotWidgetPrivate(ScreenShotWidget *widget = nullptr, QWidget *parent = nullptr);
    ~ScreenShotWidgetPrivate();

    void initProperty();
    void initSreenPixmap();
    void initWidget();

    QSharedPointer <QPixmap> getScreenPixmap();
    QRect getScreenRect();

    QRect getDefaultRect(const QPoint&, const QPoint&);

    ScreenShotWidget *q_ptr;
    MainWidget *m_main_widget;
    ScreenShotBar *m_screenshot_bar;

    PaintPropertyWidget *m_painter_property_widget;
    TextPropertyWidget *m_text_property_widget;

    QLabel *m_label;
    bool m_mouse_press;
    CutState m_cut_state;
    QRect m_cut_area;
    QRect m_temp_rect;
    QPoint m_press_pos;
    QColor m_mask_color;
    ColorPicker *m_color_picker;
    BorderType m_border_type;
    MarkWidget *m_mark_widget = nullptr;
    PaintProperty m_paint_property;
    PropertyMap m_property_map;
    QSharedPointer <QPixmap> m_screen_pixmap = nullptr;
};

#endif // SCREENSHOTWIDGET_P_H
