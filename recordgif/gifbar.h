#ifndef GIFBAR_H
#define GIFBAR_H
#include <QtWidgets/QWidget>
#include <QSize>
#include "recordgif_global.h"

class QPushButton;
class QPaintEvent;
class QLabel;
class QLineEdit;
class RECORDGIF_EXPORT GifBar : public QWidget
{
    Q_OBJECT
public:
    explicit GifBar(QWidget *parent = nullptr);
    ~GifBar();

    void setRecordWidth(const QString&);
    QString recordWidth();

    void setRecordHeight(const QString&);
    QString recordHeight();

    QString fps();

    void setRecordInfo(const QString&);

signals:
    void startRecord();
    void pauseRecord();
    void stopRecord();

    void signalXChange(QString);
    void signalYChange(QString);
    void signalFpsChange(QString);

public slots:
    void slotStartClick();
    void slotStopClick();

protected:
    virtual void paintEvent(QPaintEvent *);

private:
    QLabel *m_fps_label;
    QLineEdit *m_fps_edit;
    QLabel *m_xlabel;
    QLabel *m_ylabel;
    QLabel *m_record_info;
    QLineEdit *m_xedit;
    QLineEdit *m_yedit;
    QPushButton *m_start_button;
    QPushButton *m_stop_button;
    bool m_record_flag;
};

#endif // GIFBAR_H
