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
    editplan.cpp

HEADERS  += calendar_main.h \
    editplan.h

FORMS    += calendar_main.ui \
    editplan.ui
#//이거 경로 꼭!!!!!!! 업데이트 해주세요!! 자기 경로로
#//Please update below PATH to your own!!! otherwise it causes error
INCLUDEPATH += "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\Include" \
    "C:\Program Files (x86)\Windows Kits\8.1\Include\shared" \
#INCLUDEPATH += C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\Include;C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\atlmfc\Include;

win32:LIBS += "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\lib" \
    "C:\Program Files (x86)\Windows Kits\8.1\Lib\winv6.3\um\x86" \
#win32:LIBS +=C:\Program Files (x86)\Microsoft Visual 12.0\VC\lib;C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\atlmfc\lib;C:\Program Files (x86)\Windows Kits\8.1\lib\winv6.3\um\x86
#win32:LIBS += C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\Include;C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\atlmfc\Include;
