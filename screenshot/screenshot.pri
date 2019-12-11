include(paintproperty/paintproperty.pri)

DISTFILES += \
    $$PWD/screenshot.pri

HEADERS += \
    $$PWD/colorlabel.h \
    $$PWD/colormanagerwidget.h \
    $$PWD/colorpicker.h \
    $$PWD/colorpicker_p.h \
    $$PWD/datastruct.h \
    $$PWD/markwidget.h \
    $$PWD/paintpropertywidget.h \
    $$PWD/screenshotbar.h \
    $$PWD/screenshotwidget.h \
    $$PWD/screenshotwidget_p.h \
    $$PWD/shape.h \
    $$PWD/shaperect.h \
    $$PWD/widthlabel.h \
    $$PWD/widthwidget.h

SOURCES += \
    $$PWD/colorlabel.cpp \
    $$PWD/colormanagerwidget.cpp \
    $$PWD/colorpicker.cpp \
    $$PWD/markwidget.cpp \
    $$PWD/paintpropertywidget.cpp \
    $$PWD/screenshotbar.cpp \
    $$PWD/screenshotwidget.cpp \
    $$PWD/shape.cc \
    $$PWD/shaperect.cpp \
    $$PWD/widthlabel.cc \
    $$PWD/widthwidget.cc

INCLUDEPATH +=  $$PWD/../app/


