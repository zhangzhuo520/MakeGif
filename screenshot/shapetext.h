#ifndef SHAPETEXT_H
#define SHAPETEXT_H
#include "shape.h"
#include <QFont>
class TextEdit;
class ShapeText : public Shape
{
public:
    ShapeText(TextEdit *, QFont);
    ~ShapeText();

    virtual ShapeType getType() {return TEXT; }
    virtual QRectF boundingBox();

protected:
    virtual void drawShape(QPainter *);
    virtual void mouseDoubleClick(QMouseEvent *);
    virtual void mousePressEvent(QMouseEvent *);
    virtual void mouseMoveEvent(QMouseEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *);

private:
    TextEdit *m_text_edit;
    QPoint m_text_pos;
    QString m_text;
    QFont m_font;
};


#endif // SHAPETEXT_H
