#ifndef RECORDGIFWIDGET_P_H
#define RECORDGIFWIDGET_P_H

#include <QDialog>
#include "gif.h"

class QLineEdit;
class QLabel;

class RecordGifWidget;
class RecordGifWidgetPrivate
{
    Q_DECLARE_PUBLIC(RecordGifWidget)
public:
    explicit RecordGifWidgetPrivate(RecordGifWidget *widget);
    ~RecordGifWidgetPrivate();

    RecordGifWidget *q_ptr;
    static QScopedPointer<GifWidget> self;
    QWidget *widgetTop;         //标题栏
    QWidget *widgetMain;        //中间部分
    QWidget *widgetBottom;      //底部栏
    QLineEdit *txtFps;          //帧率输入框
    QLineEdit *txtWidth;        //宽度输入框
    QLineEdit *txtHeight;       //高度输入框
    QPushButton *btnStart;      //开始按钮
    QLabel *labStatus;          //显示状态信息

    int fps;                    //帧数 100为1s
    int borderWidth;            //边框宽度
    QColor bgColor;             //背景颜色

    int count;                  //帧数计数
    QString fileName;           //保存文件名称
    QRect rectGif;              //截屏区域
    QTimer *timer;              //截屏定时器

    Gif gif;                    //gif类对象
    Gif::GifWriter *gifWriter;  //gif写入对象

public:
    int getBorderWidth()        const;
    QColor getBgColor()         const;

private slots:
    void initControl();
    void initForm();
    void saveImage();
    void record();
    void closeAll();
    void resizeForm();
};
