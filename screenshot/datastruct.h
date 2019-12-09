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

    paintproperty(const paintproperty & property)
    {
        color = property.color;
        width = property.width;
        paint_type = property.paint_type;
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
        return *this;
    }

    PaintType paint_type;
    QColor color;
    int width;
}PaintProperty;

class PaintPropertyList : public QList <PaintProperty *>
{
public:
    PaintPropertyList();
    ~PaintPropertyList();
};

Q_DECLARE_METATYPE(PaintProperty)

#endif // DATASTRUCT_H
