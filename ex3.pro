QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = main
TEMPLATE = app

SOURCES += main.cpp

HEADERS += TreeViewWidget.hpp \
           Tree.hpp \
           Node.hpp \
           Complex.hpp