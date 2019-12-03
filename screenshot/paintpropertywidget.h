#ifndef     PAINTPROPERTYWIDGET_H
#define PAINTPROPERTYWIDGET_H
#include <QWidget>

class QPaintEvent;
class ColorManagerWidget;
class QGraphicsDropShadowEffect;
class WidthWidget;
class PaintPropertyWidget : public QWidget
{
public:
    PaintPropertyWidget(QWidget *parent = nullptr);
    ~PaintPropertyWidget();

protected:
    void paintEvent(QPaintEvent *);


private:
    void initShadoweffect();
    void initWidgets();

    int m_startx;
    int m_trianglewidth;
    int m_triangleheight;
    QGraphicsDropShadowEffect* m_shadoweffect;
    ColorManagerWidget *m_color_widget;
    WidthWidget *m_width_widget;
};

#endif // PAINTPROPERTYWIDGET_H
