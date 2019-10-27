#-------------------------------------------------
#
# Project created by QtCreator 2019-10-15T12:13:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MakeGif
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(deftools/deftools.pri)

SOURCES += \
        main.cpp \
        mainwidget.cpp \
        imagelabel.cpp \
        property.cpp \
    pushbutton.cpp \
    screenshotwidget.cpp \
    recordgifwidget.cpp \
    screenshotbar.cpp \
    gifwidget.cpp \
    gifbar.cpp \
    gifrecordthread.cpp

HEADERS += \
        mainwidget.h \
        imagelabel.h \
    mainwidget_p.h \
    property.h \
    pushbutton.h \
    screenshotwidget.h\
    screenshotwidget_p.h \
    recordgifwidget.h \
    recordgifwidget_p.h \
    screenshotbar.h \
    gif.h \
    gifwidget.h \
    gifbar.h \
    gifrecordthread.h

RESOURCES += \
    images.qrc
