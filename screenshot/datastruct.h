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
    PaintType paint_type;
    QColor color;
    int width;
}PaintProperty;

Q_DECLARE_METATYPE(PaintProperty)

#endif // DATASTRUCT_H
