#ifndef APPHELPER_H
#define APPHELPER_H

#include <QObject>
#include <QFont>
#include <QFontDatabase>
#include <QMutex>
#include <QLabel>
#include <QPushButton>
#include <QApplication>
#include <QtCore>
#include <QtGui>
#if (QT_VERSION > QT_VERSION_CHECK(5,0,0))
#include <QtWidgets>
#endif
#include "apphelper.h"
#include "app.h"

namespace tools {

class IconHelper : public QObject
{
private:
    explicit IconHelper(QObject *parent = 0);

    QFont m_iconfont;
    static IconHelper *s_instance;

public:
    static IconHelper *getInstance()
    {
        static QMutex mutex;
        if (!s_instance)
        {
            QMutexLocker locker(&mutex);
            if (!s_instance)
            {
                s_instance = new IconHelper;
            }
        }
        return s_instance;
    }

    void setIcon(QLabel *lab, QChar chr);
    void setIcon(QPushButton *btn, QChar chr);
};


class Helper: public QObject
{
public:
    static void autoRunWithSystem(bool ifAutoRun, QString appName, QString appPath) {
        QSettings *reg = new QSettings(
            "HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",
            QSettings::NativeFormat);

        if (ifAutoRun) {
            reg->setValue(appName, appPath);
        } else {
            reg->setValue(appName, "");
        }
    }

    static void setStyle(const QString &qssFile) {
        QFile file(qssFile);
        if (file.open(QFile::ReadOnly)) {
            QString qss = QLatin1String(file.readAll());
            qApp->setStyleSheet(qss);
            file.close();
        }
    }

    static void setChinese() {
        QTranslator *translator = new QTranslator(qApp);
        translator->load(":/pic/picture/qt_zh_CN.qm");
        qApp->installTranslator(translator);
    }

    static void sleep(int sec) {
        QTime dieTime = QTime::currentTime().addMSecs(sec);

        while ( QTime::currentTime() < dieTime ) {
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        }
    }

    static void moveFormToCenter(QWidget *frm) {
        int frmX = frm->width();
        int frmY = frm->height();

        QDesktopWidget dwt;

        int deskWidth = dwt.availableGeometry().width();
        int deskHeight = dwt.availableGeometry().height();

        QPoint movePoint(deskWidth / 2 - frmX / 2, deskHeight / 2 - frmY / 2);
        frm->move(movePoint);
    }
};
}
#endif // ICONHELPER_H
