#-------------------------------------------------
#
# Project created by QtCreator 2015-06-19T20:35:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = proj3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    blank.cpp \
    destroy.cpp \
    star.cpp \
    nineblock.cpp \
    vertical.cpp \
    horizontal.cpp

HEADERS  += mainwindow.h \
    blank.h \
    destroy.h \
    star.h \
    nineblock.h \
    vertical.h \
    horizontal.h

FORMS    += mainwindow.ui

RESOURCES += \
    picture.qrc
