#ifndef SHAPETEXT_H
#define SHAPETEXT_H
#include "shape.h"

class TextEdit;
class ShapeText : public Shape
{
public:
    ShapeText(TextEdit *);
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
};


#endif // SHAPETEXT_H
