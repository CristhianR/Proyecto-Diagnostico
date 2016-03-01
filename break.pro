#-------------------------------------------------
#
# Project created by QtCreator 2016-02-27T14:49:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = break
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    breakout.cpp \
    barra.cpp \
    ladrillo.cpp \
    bola.cpp \
    ladrillo2.cpp \
    puntuacion.cpp \
    barra2.cpp \
    ladrillo3.cpp \
    ladrilloI.cpp \
    ladrilloP.cpp

HEADERS  += mainwindow.h \
    breakout.h \
    barra.h \
    ladrillo.h \
    bola.h \
    Ladrillo2.h \
    puntuacion.h \
    barra2.h \
    ladrillo3.h \
    ladrilloI.h \
    ladrilloP.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
