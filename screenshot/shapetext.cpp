#include "shapetext.h"
#include "textedit.h"
#include <QPainter>

ShapeText::ShapeText(TextEdit * edit):
    Shape(this),
    m_text_edit(edit),
    m_text_pos(0, 0)
{

}

ShapeText::~ShapeText()
{

}

QRectF ShapeText::boundingBox()
{

}

void ShapeText::drawShape(QPainter *painter)
{
    painter->setFont(QFont("Timers" , 18,  QFont::Thin));
    painter->drawText(m_text_pos, m_text_edit->text());
    m_text_edit->clear();
}

void ShapeText::mouseDoubleClick(QMouseEvent *)
{

}

void ShapeText::mousePressEvent(QMouseEvent *e)
{
    if(m_text_edit->isHidden() || m_text_edit->text().isEmpty())
    {
        m_text_edit->show();
        m_text_edit->move(e->pos());
    }
    else
    {
        m_text_pos.setX(m_text_edit->pos().x() + 3);
        m_text_pos.setY(m_text_edit->pos().y() + 21);
        m_text_edit->hide();
    }
}

void ShapeText::mouseMoveEvent(QMouseEvent *)
{

}

void ShapeText::mouseReleaseEvent(QMouseEvent *)
{

}
