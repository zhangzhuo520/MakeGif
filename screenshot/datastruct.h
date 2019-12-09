#ifndef DATASTRUCT_H
#define DATASTRUCT_H
#include <QColor>
#include <QObject>
enum PaintType
{
    NONE,
    LINE,
    ARROW,
    BOX,
    CIRCLE,
    TEXT
};

typedef struct paintproperty
{
    paintproperty():
        paint_type(NONE),
        color(Qt::black),
        width(1)
    {}
    ~paintproperty(){}

    paintproperty& operator =( const struct paintproperty & obj)
    {
        this->paint_type = obj.paint_type;
        this->color = obj.color;
        this->width = obj.width;
        return *this;
    }

    PaintType paint_type;
    QColor color;
    int width;
}PaintProperty;

Q_DECLARE_METATYPE(PaintProperty)

#endif // DATASTRUCT_H
