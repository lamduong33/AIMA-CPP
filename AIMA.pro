TEMPLATE = app
TARGET = AIMA_CPP

QT = core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += ./gui/AIMA.cpp
SOURCES += ./gui/Window.cpp
HEADERS += ./include/AIMAGUI.hpp


SOURCES += ./src/*.cpp
HEADERS += ./include/*.hpp
