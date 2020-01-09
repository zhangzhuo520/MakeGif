#ifndef ABSTRACTPROPERTYWIDGET_H
#define ABSTRACTPROPERTYWIDGET_H
#include <QWidget>
#include "datastruct.h"
class QPaintEvent;
class ColorManagerWidget;
class QGraphicsDropShadowEffect;
class WidthWidget;
class AbstractPropertyWidget : public QWidget
{
    Q_OBJECT
public:
    AbstractPropertyWidget(QWidget *parent = nullptr);
    ~AbstractPropertyWidget();
    virtual void setPaintProperty(const PaintProperty&);
protected:
    void paintEvent(QPaintEvent *);

signals:
    void signalPaintProperty(PaintProperty);

protected:
    void initShadoweffect();
    int m_startx;
    int m_trianglewidth;
    int m_triangleheight;
    QGraphicsDropShadowEffect* m_shadoweffect;
    PaintProperty m_paint_property;
};

#endif // ABSTRACTPROPERTYWIDGET_H
