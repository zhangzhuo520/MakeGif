#ifndef APP_H
#define APP_H
#include "deftools_golbal.h"
class QString;
namespace DEFTOOLS_EXPORT tools {

class App
{
public:
    static QString appPath;
    static int appFontSize;
    static QString appFontName;

    static void readConfig();
    static QString readConfig(const QString sGroup, const QString skey);
    static QString readConfig(const QString skey);

    static void writeConfig();
    static void writeConfig(const QString sGroup, const QString skey, QString sValue);
    static void writeConfig(const QString skey, QString sValue);
};

}
#endif // APP_H
