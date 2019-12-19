#include "mainwidget.h"
#include <QtWidgets/QApplication>
#include "../deftools/appinit.h"

/**************GifCutter********************/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    tools::AppInit *initApp = new  tools::AppInit;
    initApp->loadInfo();
    MainWidget w;
    w.show();


    return a.exec();
}
