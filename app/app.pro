TARGET = MakeGif
TEMPLATE = app
DESTDIR=../bin

QT     += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


INCLUDEPATH += \
    $$PWD/../deftools \
    $$PWD/../recordgif \
    $$PWD/../screenshot \

HEADERS += \
    imagelabel.h \
    mainwidget.h \
    mainwidget_p.h \
    pushbutton.h \
    app_global.h

SOURCES += \
    imagelabel.cpp \
    main.cpp \
    mainwidget.cpp \
    pushbutton.cpp

#LIBS += -l$$qtLibraryName(Deftools) -l$$qtLibraryName(RecordGif) -l$$qtLibraryName(ScreenShot)
