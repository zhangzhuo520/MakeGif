#ifndef ABSTRACTSHAPEPRIVATE_H
#define ABSTRACTSHAPEPRIVATE_H
#include <QColor>
#include <QBrush>
#include <QObject>
class AbstractShape;
class AbstractShapePrivate
{
public:
    explicit AbstractShapePrivate(AbstractShape *);
    ~AbstractShapePrivate();

    void slotUpdate(int) { }

    inline void setColor(const QColor& color) { m_color = color; }
    inline QColor color() const { return m_color; }

    inline void setBrushColor(const QColor & color) { m_brush_color = color;}
    inline QColor brushColor() const { return m_brush_color;}

    inline setWidth(int w) { m_width = w; }
    inline int width() const { return m_width; }

    inline void setLineStyle(int linestyle) { m_line_style = linestyle; }
    inline int lineStyle() const { return m_line_style; }

    inline void setBrushStyle(int style) {m_brush_style = style;}
    inline int brushStyle() const { return m_brush_style;}

    QColor m_color;
    QColor m_brush_color;
    int m_width;
    int m_brush_style;
    int m_line_style;

private:
    AbstractShape *q_ptr;
    Q_DECLARE_PUBLIC(AbstractShape)
};

#endif // ABSTRACTSHAPEPRIVATE_H
