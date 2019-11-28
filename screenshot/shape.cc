#include "shape.h"

Shape::Shape(Shape *shape)
{
   m_shape_list.append(shape);
}
