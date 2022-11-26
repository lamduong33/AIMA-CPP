TEMPLATE = app
TARGET = AIMA_CPP

QT = core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += ./src/gui/AIMA.cpp
SOURCES += ./src/gui/AIMAGUI.cpp
HEADERS += ./include/AIMAGUI.hpp

SOURCES += ./src/aima/*.cpp
HEADERS += ./include/*.hpp
