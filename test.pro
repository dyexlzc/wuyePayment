#-------------------------------------------------
#
# Project created by QtCreator 2017-08-05T18:42:35
#
#-------------------------------------------------

QT       += core gui sql widgets axcontainer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app

#win32 {
#QMAKE_LFLAGS_WINDOWS = /SUBSYSTEM:WINDOWS,5.01
#QMAKE_LFLAGS_CONSOLE = /SUBSYSTEM:CONSOLE,5.01

#DEFINES += _ATL_XP_TARGETING
#QMAKE_CFLAGS += /D_USING_V140_SDK71_
#QMAKE_CXXFLAGS += /D_USING_V140_SDK71_
#LIBS += -L$$quote(C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1A\Lib)
#INCLUDEPATH += $$quote(C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1A\Include)
#}

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
#DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    hall.cpp \
    viewdata.cpp \
    carmoney.cpp \
    wy_jiaofei.cpp

HEADERS += \
        mainwindow.h \
    hall.h \
    viewdata.h \
    viewdata.h \
    carmoney.h \
    wy_jiaofei.h \
    style.h

FORMS += \
        mainwindow.ui \
    hall.ui \
    viewdata.ui \
    viewdata.ui \
    carmoney.ui \
    wy_jiaofei.ui
