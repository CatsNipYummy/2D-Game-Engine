TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Base_Classes/entity.cpp \
    Base_Classes/component.cpp \
    Base_Classes/entitymanager.cpp \
    Base_Classes/timer.cpp \
    Base_Classes/renderer.cpp \
    Components/sprite.cpp \
    Base_Classes/window.cpp \
    Components/transform.cpp

    LIBS += -L/usr/local/lib -lSDL2 -ldl -lpthread
    INCLUDEPATH += /usr/local/include

INCLUDEPATH += Base_Classes
INCLUDEPATH += Components
INCLUDEPATH += Assets

HEADERS += \
    Base_Classes/entity.h \
    Base_Classes/component.h \
    Base_Classes/entitymanager.h \
    Base_Classes/timer.h \
    Base_Classes/renderer.h \
    Components/sprite.h \
    Base_Classes/window.h \
    Components/transform.h
