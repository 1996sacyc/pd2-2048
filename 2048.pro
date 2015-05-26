#-------------------------------------------------
#
# Project created by QtCreator 2015-05-23T20:46:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 2048
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    game.cpp

HEADERS  += mainwindow.h \
    game.h \
    setup.h

FORMS    += mainwindow.ui \
    game.ui

RESOURCES += \
    pics.qrc
