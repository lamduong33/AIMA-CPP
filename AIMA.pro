TEMPLATE = app
TARGET = AIMA_CPP

QT = core gui

greaterThan(QT_MAJOR_VERESION, 5): QT += widgets

SOURCES += gui/AIMA.cpp

HEADERS += ./include/*.hpp
