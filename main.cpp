#include "mainwidget.h"
#include <QApplication>
#include "deftools/appinit.h"

/**************GifCutter********************/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    tools::AppInit *initApp = new  tools::AppInit;
    initApp->loadInfo();
    MainWidget w;
    w.show();

    return a.exec();
}
