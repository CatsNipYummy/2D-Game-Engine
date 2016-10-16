TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Base_Classes/entity.cpp \
    Base_Classes/component.cpp \
    Base_Classes/entitymanager.cpp \
    Components/sprite.cpp

    LIBS += -L/usr/local/lib -lSDL2 -ldl -lpthread
    INCLUDEPATH += /usr/local/include

INCLUDEPATH += Base_Classes
INCLUDEPATH += Components

HEADERS += \
    Base_Classes/entity.h \
    Base_Classes/component.h \
    Base_Classes/entitymanager.h \
    Components/sprite.h
