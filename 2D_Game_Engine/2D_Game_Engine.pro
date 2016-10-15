TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Base_Classes/entity.cpp

macx {
    LIBS += -L/usr/local/lib -lSDL2 -ldl -lpthread
    INCLUDEPATH += /usr/local/include
}

INCLUDEPATH += Base_Classes

HEADERS += \
    Base_Classes/entity.h
