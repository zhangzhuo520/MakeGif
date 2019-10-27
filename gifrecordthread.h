#ifndef GIFRECORDTHREAD_H
#define GIFRECORDTHREAD_H
#include <QThread>
#include <QObject>
#include <QRect>
#include "gif.h"

class QTimer;
class GifRecordThread : public QObject
{
    Q_OBJECT
public:
    explicit GifRecordThread(QObject *obj = nullptr);
    ~GifRecordThread();
    void setRecordRect(const QRect&);
    void setFps(const int&);
    int frameCount() const;

public slots:
    void slotStartRecord();
    void slotStopRecord();
    void slotSaveImage();
    void slotStopThread();

private:
    QObject *m_parent_object;
    QThread *m_record_thead;

    QString m_gif_path;
    QRect m_gif_rect;
    int m_fps;
    QTimer* m_timer;
    int m_frame_count;
    bool m_is_pause;


    Gif m_gif;
    Gif::GifWriter *m_gif_writer;
};

#endif // GIFRECORDTHREAD_H
