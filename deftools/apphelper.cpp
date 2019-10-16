#include "apphelper.h"
#include "app.h"
#include <qdebug.h>
namespace tools {

IconHelper *IconHelper::s_instance = 0;

IconHelper::IconHelper(QObject *parent)
    :QObject(parent)
{
    int fontId = QFontDatabase::addApplicationFont(":/pic/picture/fontawesome-webfont.ttf");
    QString fontName = QFontDatabase::applicationFontFamilies(fontId).at(0);
    m_iconfont = QFont(fontName);
}

void IconHelper::setIcon(QLabel *lab, QChar chr)
{
    m_iconfont.setPointSize(App::appFontSize);
    lab->setFont(m_iconfont);
    lab->setText(chr);
}

void IconHelper::setIcon(QPushButton *btn, QChar chr)
{
    m_iconfont.setPointSize(App::appFontSize);
    btn->setFont(m_iconfont);
    btn->setText(chr);
}

}
