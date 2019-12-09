#ifndef SCREENSHOTBAR_H
#define SCREENSHOTBAR_H
#include <QWidget>
#include "datastruct.h"

class PushButton;
class QPaintEvent;
class QEvent;
class ScreenShotWidget;
class ScreenShotBar : public QWidget
{
    Q_OBJECT
public:
    explicit ScreenShotBar(QWidget *parent = nullptr);
    ~ScreenShotBar();
    typedef QList <PaintProperty *> PPropertyList;
    void initUi();

    virtual void paintEvent(QPaintEvent *);
    virtual void enterEvent(QEvent *);
    virtual void leaveEvent(QEvent *);
    bool mouseEnter();
signals:
    void signal_ok_btnclick();
    void signal_cancel_btnclick();
    void signal_paint_property(PaintProperty);

public slots:
    void slotShowPropertyWidget();

private:
    PushButton *m_line_btn;
    PushButton *m_arrow_btn;
    PushButton *m_box_btn;
    PushButton *m_ok_btn;
    PushButton *m_cancel_btn;
    PPropertyList m_property_list;
    ScreenShotWidget *m_screen_widget;
    bool m_enter;
};

#endif // SCREENSHOTBAR_H
