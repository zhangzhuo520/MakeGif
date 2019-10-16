#include "property.h"
#include <QDebug>

Property::Property(QObject *parent):
    QObject(parent)
{
    setProperty("1111", true);
   qDebug() << this->property("1111");
}

Property::~Property()
{

}
