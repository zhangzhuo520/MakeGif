#ifndef SCREENSHOTBAR_H
#define SCREENSHOTBAR_H
#include <QWidget>

class PushButton;
class ScreenShotBar : public QWidget
{
    Q_OBJECT
public:
    explicit ScreenShotBar(QWidget *parent = nullptr);
    ~ScreenShotBar();

    void initUi();
 signals:
    void signal_ok_btnclick();
    void signal_cancel_btnclick();

private:
    PushButton *m_ok_btn;
    PushButton *m_cancel_btn;
};

#endif // SCREENSHOTBAR_H
