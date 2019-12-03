#ifndef WIDTHWIDGET_H
#define WIDTHWIDGET_H
#include <QWidget>

class WidthLabel;
class WidthWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WidthWidget(QWidget *parent = nullptr);
    void initWidgets();
    ~WidthWidget();

public slots:
    void slotSelectChange();

private:
    WidthLabel *m_thick_label;
    WidthLabel *m_normal_label;
    WidthLabel *m_thin_label;

};

#endif // WIDTHWIDGET_H
