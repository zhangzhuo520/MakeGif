#include "appinit.h"
#include "apphelper.h"
namespace tools {

AppInit::AppInit(QObject *parent)
    : QObject(parent)
{
    m_mouse_pressed = false;
    qApp->installEventFilter(this);
}

bool AppInit::eventFilter(QObject *obj, QEvent *evt)
{
    QWidget *wdt = (QWidget *)obj;
    if (!wdt->property("CanMove").toBool()) {
        return QObject::eventFilter(obj, evt);
    }

    QMouseEvent *event = static_cast<QMouseEvent *>(evt);
    if (event->type() == QEvent::MouseButtonPress) {
        if (event->button() == Qt::LeftButton) {
            m_mouse_pressed = true;
            m_mouse_point = event->globalPos() - wdt->pos();
            return true;
        }
    } else if (event->type() == QEvent::MouseButtonRelease) {
        m_mouse_pressed = false;
        return true;
    } else if (event->type() == QEvent::MouseMove) {
        if (m_mouse_pressed && (event->buttons() && Qt::LeftButton)) {
            wdt->move(event->globalPos() - m_mouse_point);
            return true;
        }
    }

    return QObject::eventFilter(obj, evt);
}

void AppInit::loadInfo()
{
    Helper::setChinese();
    qApp->setFont(QFont(App::appFontName, App::appFontSize));

    App::appPath = QApplication::applicationDirPath();

}

}
