#ifndef COLORMANAGERWIDGET_H
#define COLORMANAGERWIDGET_H
#include <QWidget>
#include <QList>
#include <QColor>
class ColorLabel;
class ColorManagerWidget : public QWidget
{
public:
    explicit ColorManagerWidget(QWidget *paren = nullptr);
    void initColorLabel();
    ~ColorManagerWidget();

public slots:
    void slotSelectColor(QColor);

private:
    QList <ColorLabel *> m_colorlabel_list;
    QList <QColor> m_color_list;
};

#endif // COLORMANAGERWIDGET_H
