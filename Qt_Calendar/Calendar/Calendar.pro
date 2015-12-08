#-------------------------------------------------
#
# Project created by QtCreator 2015-11-26T18:03:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Calendar
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        calendar_main.cpp \
    editplan.cpp \
    JBsSchedule.cpp \
    TimeManager.cpp \
    ScheduleManager.cpp \
    FileController.cpp \
    showplan.cpp

HEADERS  += calendar_main.h \
    editplan.h \
    JBsSchedule.h \
    TimeManager.h \
    ScheduleManager.h \
    FileController.h \
    showplan.h

FORMS    += calendar_main.ui \
    editplan.ui \
    showplan.ui
