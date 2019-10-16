#ifndef PROPERTY_H
#define PROPERTY_H

#include <QObject>
class Property : public QObject
{
    Q_OBJECT
public:
    explicit Property(QObject *parent = nullptr);
    ~Property();
};

#endif // PROPERTY_H
