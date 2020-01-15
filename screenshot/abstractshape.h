#ifndef ABSTRACTSHAPE_H
#define ABSTRACTSHAPE_H
#include <QObject>

class AbstractShapePrivate;
class AbstractShape : public QObject
{
    Q_OBJECT
public:
    explicit AbstractShape();
    ~AbstractShape();

private:
    AbstractShapePrivate *d_ptr;
    Q_DISABLE_COPY(AbstractShape)
    Q_DECLARE_PRIVATE(AbstractShape)
//    Q_PRIVATE_SLOT(d_func(),  void slotUpdate(int))
};

#endif // ABSTRACTSHAPE_H
