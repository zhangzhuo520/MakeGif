#ifndef SCREENSHOTBAR_H
#define SCREENSHOTBAR_H
#include <QWidget>
#include "datastruct.h"

class PushButton;
class QPaintEvent;
class QEvent;

class ScreenShotBar : public QWidget
{
    Q_OBJECT
public:
    explicit ScreenShotBar(QWidget *parent = nullptr);
    ~ScreenShotBar();

    void initUi();

    virtual void paintEvent(QPaintEvent *);
    virtual void enterEvent(QEvent *);
    virtual void leaveEvent(QEvent *);
    bool mouseEnter();
signals:
    void signal_ok_btnclick();
    void signal_cancel_btnclick();
    void signal_paint_property(PaintProperty);

private:
    PushButton *m_line_btn;
    PushButton *m_arrow_btn;
    PushButton *m_box_btn;
    PushButton *m_ok_btn;
    PushButton *m_cancel_btn;
    PaintProperty m_paint_property;
    bool m_enter;
};

#endif // SCREENSHOTBAR_H
