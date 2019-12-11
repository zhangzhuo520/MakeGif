#include "gifrecordthread.h"
#include "apphelper.h"
#include <QStandardPaths>
#include <QDateTime>
#include <QTimer>
#include <QImage>
#include <QPixmap>
#include <QScreen>
#include <QApplication>
#include <QDebug>
GifRecordThread::GifRecordThread(QObject *obj):
    m_parent_object(obj),
    m_gif_path(""),
    m_gif_rect(0, 0, 0, 0),
    m_fps(25),
    m_frame_count(0),
    m_thread_state(STOP)
{
    m_gif_writer = new Gif::GifWriter;
    m_record_thead = new QThread();
    moveToThread(m_record_thead);
    connect(m_record_thead, SIGNAL(started()), this, SLOT(slotRunThread()));
    connect(m_record_thead, SIGNAL(finished()), this, SLOT(slotStopThread()));
}

GifRecordThread::~GifRecordThread()
{
    if(m_gif_writer)
    {
        delete m_gif_writer;
        m_gif_writer = nullptr;
    }

    if(m_record_thead)
    {
        delete m_record_thead;
        m_record_thead = 0;
    }
}

void GifRecordThread::saveImage()
{
    if (!m_gif_writer) {
        return;
    }

 #if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
    //由于qt4没有RGBA8888,采用最接近RGBA8888的是ARGB32,颜色会有点偏差
    QPixmap pix = QPixmap::grabWindow(0, x() + rectGif.x(), y() + rectGif.y(), rectGif.width(), rectGif.height());
    QImage image = pix.toImage().convertToFormat(QImage::Format_ARGB32);
#else
    QScreen *screen = QApplication::primaryScreen();
    QPixmap pix = screen->grabWindow(0, m_gif_rect.x(), m_gif_rect.y(), m_gif_rect.width(), m_gif_rect.width());
    QImage image = pix.toImage().convertToFormat(QImage::Format_RGBA8888);
#endif

    m_gif.GifWriteFrame(m_gif_writer, image.bits(), m_gif_rect.width(), m_gif_rect.height(), m_fps);
    m_frame_count++;
    emit signalFrameCount(m_frame_count);
}

void GifRecordThread::slotRunThread()
{
    QMutex mutex;
    while (1) {
        tools::Helper::sleep(1000 / m_fps);
        mutex.lock();
        if(m_thread_state != RUN)
            m_stop_conditiom.wait(&mutex);
        mutex.unlock();
        saveImage();
    }
}

void GifRecordThread::slotStopThread()
{
}

void GifRecordThread::setRecordRect(const QRect & rect)
{
    m_gif_rect = rect;
}

void GifRecordThread::setFps(const int &fps)
{
    m_fps = fps;
}

int GifRecordThread::frameCount() const
{
    return m_frame_count;
}

void GifRecordThread::slotStartRecord()
{

    if(m_gif_rect.height() == 0 || m_gif_rect.height() == 0 || m_fps == 0)
    {
        return;
    }

    if(m_thread_state == STOP)
    {
        m_thread_state = RUN;
        m_stop_conditiom.wakeOne();
        QString fileName =  QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) + "/" + QDateTime::currentDateTime() .toString("yyyy-MM-dd-hh-mm-ss") + ".gif";
        bool flag = m_gif.GifBegin(m_gif_writer, fileName.toLocal8Bit().data(), m_gif_rect.width(), m_gif_rect.height(), m_fps);
        if(!flag)
        {
            return;
        }
        m_frame_count = 0;
        if(!m_record_thead->isRunning())
        {
            m_record_thead->start();
        }
    }
    else
    {
        if(m_thread_state == RUN)
        {
            m_thread_state = PAUSE;
        }
        else
        {
            m_stop_conditiom.wakeOne();
            m_thread_state = RUN;
        }
    }
}

void GifRecordThread::slotStopRecord()
{
    m_thread_state = STOP;
    m_gif.GifEnd(m_gif_writer);
}


