#ifndef     PAINTPROPERTYWIDGET_H
#define PAINTPROPERTYWIDGET_H
#include "abstractpropertywidget.h"
#include "datastruct.h"
class QPaintEvent;
class ColorManagerWidget;
class QGraphicsDropShadowEffect;
class WidthWidget;
class PaintPropertyWidget : public AbstractPropertyWidget
{
    Q_OBJECT
public:
    PaintPropertyWidget(QWidget *parent = nullptr);
    ~PaintPropertyWidget();

public slots:
    void slotSelectColor(QColor);
    void slotSelectWidth(int);

private:
    void initWidgets();
    ColorManagerWidget *m_color_widget;
    WidthWidget *m_width_widget;
};

#endif // PAINTPROPERTYWIDGET_H
