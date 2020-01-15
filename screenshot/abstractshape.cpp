#include "abstractshape.h"
#include "abstractshape_p.h"
AbstractShape::AbstractShape():
    d_ptr(new AbstractShapePrivate(this))
{

}

AbstractShape::~AbstractShape()
{

}

AbstractShapePrivate::AbstractShapePrivate(AbstractShape *shape ):
    q_ptr(shape)
{

}

AbstractShapePrivate::~AbstractShapePrivate()
{

}
