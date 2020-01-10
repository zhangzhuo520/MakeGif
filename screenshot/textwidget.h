#ifndef TEXTWIDGET_H
#define TEXTWIDGET_H
#include <QWidget>

class Combobox;
class Label;
class TextWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TextWidget(QWidget *parent = nullptr);
    ~TextWidget();

signals:
    void signalTextSize(QString);

public slots:
void slotTextSize(QString);


private:
    void initUi();

    Combobox *m_combobox;
    Label *m_label;
};

#endif // TEXTWIDGET_H
