#ifndef COLORMANAGERWIDGET_H
#define COLORMANAGERWIDGET_H
#include <QWidget>
#include <QList>
#include <QColor>
class ColorLabel;
class QPaintEvent;
class ColorManagerWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ColorManagerWidget(QWidget *paren = nullptr);
    ~ColorManagerWidget();

public slots:
    void slotSelectColor(QColor);

protected:
    void paintEvent(QPaintEvent*);

private:
    void initColorLabel();
    void initColorList();
    QList <ColorLabel *> m_colorlabel_list;
    QList <QColor> m_color_list;
};

#endif // COLORMANAGERWIDGET_H
