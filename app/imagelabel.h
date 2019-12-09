#ifndef IMAGELABEL_H
#define IMAGELABEL_H
#include <QtWidgets/QLabel>
#include <QColor>
class QPaintEvent;
class ImageLabel : public QLabel
{
    Q_OBJECT
public:
    explicit ImageLabel(QWidget *parent  = nullptr);
    ~ImageLabel();

protected:
    virtual void paintEvent(QPaintEvent *);

private:
    int m_width;
    int m_height;
    QColor m_start_color;
    QColor m_center_color;
    QColor m_end_color;
};

#endif // IMAGELABEL_H
