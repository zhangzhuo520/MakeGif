#ifndef DATASTRUCT_H
#define DATASTRUCT_H
#include <QColor>
#include <QBrush>
#include <QObject>
#include <qnamespace.h>
enum PaintType
{
    ARROW = 0,
    TEXT,
    PEN,
    BOX,
    CIRCLE,
    MASK,
    NONE
};

typedef struct paintproperty
{
    paintproperty():
        paint_type(NONE),
        color(Qt::black),
        width(1),
        brush_style(0),
        line_style(0)
    {}

    paintproperty(const paintproperty & property)
    {
        color = property.color;
        width = property.width;
        paint_type = property.paint_type;
        line_style = property.line_style;
        brush_style = property.brush_style;

    }

    paintproperty(const PaintType& t, const QColor& c,  int w):
        paint_type(t),
        color(c),
        width(w){}

    paintproperty& operator=(const paintproperty& p)
    {
        this->color = p.color;
        this->paint_type = p.paint_type;
        this->width = p.width;
        this->brush_style = p.brush_style;
        this->line_style = p.line_style;
        return *this;
    }

    PaintType paint_type;
    QColor color;
    int width;
    int brush_style;
    int line_style;
}PaintProperty;

class PaintPropertyList : public QList <PaintProperty *>
{
public:
    PaintPropertyList();
    ~PaintPropertyList();
};

Q_DECLARE_METATYPE(PaintProperty)

#endif // DATASTRUCT_H
