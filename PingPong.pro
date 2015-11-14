#-------------------------------------------------
#
# Project created by QtCreator 2015-11-12T00:53:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PingPong
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    paddleobj.cpp \
    ballobj.cpp \
    model.cpp \
    gameview.cpp \
    gameengine.cpp

HEADERS  += mainwindow.h \
    paddleobj.h \
    ballobj.h \
    model.h \
    gameview.h \
    gameengine.h
