#ifndef COLORMANAGERWIDGET_H
#define COLORMANAGERWIDGET_H
#include <QtWidgets/QWidget>
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

signals:
    void signalSelectColor(QColor);

public slots:
    void slotSelectColor(QColor);

private:
    void initColorLabel();
    void initColorList();

    void mutexSelection(ColorLabel*);
    QList <ColorLabel *> m_colorlabel_list;
    QList <QColor> m_color_list;
};

#endif // COLORMANAGERWIDGET_H
