TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

HEADERS += \
    chat_message.hpp

LIBS += -pthread

LIBS += -L/usr/lib/x86_64-linux-gnu/
LIBS += -lboost_system -lboost_filesystem
