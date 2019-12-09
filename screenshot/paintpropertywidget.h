#ifndef     PAINTPROPERTYWIDGET_H
#define PAINTPROPERTYWIDGET_H
#include <QWidget>
#include "datastruct.h"
class QPaintEvent;
class ColorManagerWidget;
class QGraphicsDropShadowEffect;
class WidthWidget;
class PaintPropertyWidget : public QWidget
{
    Q_OBJECT
public:
    PaintPropertyWidget(QWidget *parent = nullptr);
    ~PaintPropertyWidget();
    void set_paint_property(const PaintProperty&);
protected:
    void paintEvent(QPaintEvent *);

signals:
    void signal_paint_property(PaintProperty);

public slots:
    void slot_select_color(QColor);
    void slot_select_width(int);

private:
    void initShadoweffect();
    void initWidgets();

    int m_startx;
    int m_trianglewidth;
    int m_triangleheight;
    QGraphicsDropShadowEffect* m_shadoweffect;
    ColorManagerWidget *m_color_widget;
    WidthWidget *m_width_widget;
    PaintProperty m_paint_property;
};

#endif // PAINTPROPERTYWIDGET_H
