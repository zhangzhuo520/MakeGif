TARGET = MakeGif
TEMPLATE = app
DESTDIR= bin

QT     += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
include(deftools/deftools.pri)
include(recordgif/recordgif.pri)
include(screenshot/screenshot.pri)
include(widgets/widgets.pri)

HEADERS += \
    app/imagelabel.h \
    app/mainwidget.h \
    app/mainwidget_p.h \
    app/pushbutton.h \
    app/app_global.h

SOURCES += \
    app/imagelabel.cpp \
    app/main.cpp \
    app/mainwidget.cpp \
    app/pushbutton.cpp

RESOURCES += \
    images.qrc



