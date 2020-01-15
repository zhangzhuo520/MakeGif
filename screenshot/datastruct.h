#ifndef DATASTRUCT_H
#define DATASTRUCT_H
#include <QColor>
#include <QBrush>
#include <QObject>
#include <QMap>
#include <qnamespace.h>
enum PaintType
{
    ARROW = 0,
    TEXT,
    PEN,
    BOX,
    CIRCLE,
    MOSAIC,
    NONE
};


typedef struct paintproperty
{
    paintproperty(PaintType type):
        paint_type(type),
        color(Qt::red),
        brush_color(Qt::black),
        width(1),
        brush_style(1),
        line_style(1)
    {}

    paintproperty():
        paint_type(NONE),
        color(Qt::black),
        brush_color(Qt::black),
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
        brush_color = property.brush_color;

    }

    paintproperty(const PaintType& t, const QColor& c,  int w,  int bs, int ls):
        paint_type(t),
        color(c),
        brush_color(c),
        width(w),
        brush_style(bs),
        line_style(ls)
    {}

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
    QColor brush_color;
    int width;
    int brush_style;
    int line_style;
}PaintProperty;
Q_DECLARE_METATYPE(PaintProperty)

class PropertyMap : public QMap <PaintType, PaintProperty>
{
public:
    PropertyMap()
    {
        insert(ARROW, PaintProperty(ARROW));
        insert(TEXT, PaintProperty(TEXT));
        insert(PEN, PaintProperty(PEN));
        insert(BOX, PaintProperty(BOX, Qt::red, 1, 0, 1));
        insert(CIRCLE, PaintProperty(CIRCLE, Qt::red, 1, 0, 1));
        insert(MOSAIC, PaintProperty(MOSAIC));
    }

    ~PropertyMap(){}
};



#endif // DATASTRUCT_H
