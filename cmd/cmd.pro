#-------------------------------------------------
#
# Project created by QtCreator 2014-11-24T15:02:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cmd
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    formgpio.cpp \
    dialogselectpin.cpp

HEADERS  += mainwindow.h \
    formgpio.h \
    dialogselectpin.h

FORMS    += mainwindow.ui \
    formgpio.ui \
    dialogselectpin.ui
