#ifndef GIFRECORDTHREAD_H
#define GIFRECORDTHREAD_H
#include <QThread>
#include <QObject>
#include <QRect>
#include <QWaitCondition>
#include "gif.h"
#include "recordgif_global.h"
class QTimer;
class RECORDGIF_EXPORT GifRecordThread : public QObject
{
    Q_OBJECT
public:
    enum ThreadState{
        RUN = 0,
        PAUSE,
        STOP
    };

    explicit GifRecordThread(QObject *obj = nullptr);
    ~GifRecordThread();
    void setRecordRect(const QRect&);
    void setFps(const int&);
    int frameCount() const;
    QRect &gifRect() {return m_gif_rect;}
    ThreadState getThreadState() {return m_thread_state;}

public slots:
    void slotStartRecord();
    void slotStopRecord();
    void slotRunThread();
    void slotStopThread();

signals:
    void signalFrameCount(int);

private:
    void saveImage();

    QObject *m_parent_object;
    QThread *m_record_thead;

    QString m_gif_path;
    QRect m_gif_rect;
    int m_fps;
    int m_frame_count;
    bool m_stop_flag;
    ThreadState m_thread_state;

    Gif m_gif;
    Gif::GifWriter *m_gif_writer;

    QWaitCondition m_stop_conditiom;
};

#endif // GIFRECORDTHREAD_H
