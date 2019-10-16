#ifndef APP_H
#define APP_H

class QString;
namespace  tools {

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
