QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app

SOURCES += ../TreeViewWidget.cpp \
            Test.cpp

HEADERS += ../TreeViewWidget.hpp \
           ../Tree.hpp \
           ../Node.hpp \
           ../Complex.hpp