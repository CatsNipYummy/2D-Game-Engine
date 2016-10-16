TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Base_Classes/entity.cpp \
    Base_Classes/component.cpp \
    Base_Classes/entitymanager.cpp \
<<<<<<< HEAD
    Base_Classes/coreengine.cpp \
    Base_Classes/timer.cpp \
    Base_Classes/renderer.cpp
=======
    Components/sprite.cpp
>>>>>>> a7f4d9f2cc8d50c0f40de16e3d19fd700aaf736b

    LIBS += -L/usr/local/lib -lSDL2 -ldl -lpthread
    INCLUDEPATH += /usr/local/include

INCLUDEPATH += Base_Classes
INCLUDEPATH += Components

HEADERS += \
    Base_Classes/entity.h \
    Base_Classes/component.h \
    Base_Classes/entitymanager.h \
<<<<<<< HEAD
    Base_Classes/coreengine.h \
    Base_Classes/timer.h \
    Base_Classes/renderer.h
=======
    Components/sprite.h
>>>>>>> a7f4d9f2cc8d50c0f40de16e3d19fd700aaf736b
