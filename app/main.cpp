#include "mainwidget.h"
#include <QtWidgets/QApplication>
#include "../deftools/appinit.h"
#include "../deftools/apphelper.h"
/**************GifCutter********************/
const QString STYLE_PATH = ":/images/qss/style.qss";
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    tools::AppInit *initApp = new  tools::AppInit;
    initApp->loadInfo();
    tools::Helper::setStyle(STYLE_PATH);
    MainWidget w;
    w.show();


    return a.exec();
}
