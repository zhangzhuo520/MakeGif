#include "shape.h"
Shape::ShapeList Shape:: m_shape_list;
Shape::Shape(Shape *shape)
{
   m_shape_list.append(shape);
}
