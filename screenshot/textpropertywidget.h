#ifndef TEXTPROPERTYWIDGET_H
#define TEXTPROPERTYWIDGET_H
#include "abstractpropertywidget.h"

class TextWidget;
class ColorManagerWidget;
class TextPropertyWidget : public AbstractPropertyWidget
{
    Q_OBJECT
public:
     explicit TextPropertyWidget(QWidget * parent  = nullptr);
     ~TextPropertyWidget();

    void initUi();

public slots:
    void slotSelectColor(QColor);
    void slotSelectSize(QString);

private:
    TextWidget *m_textwidget;
    ColorManagerWidget *m_colormanger_widget;

};

#endif // TEXTPROPERTYWIDGET_H
