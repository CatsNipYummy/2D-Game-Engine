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
    Components/transform.cpp \
    Base_Classes/camera.cpp \
    Game/game.cpp \
    Game/player.cpp \
    Components/collision.cpp \
    Components/Component_Managers/collisionmanager.cpp \
    Components/animation.cpp \
    Components/world.cpp \
    Components/ai.cpp

    LIBS += -L/usr/local/lib -lSDL2 -ldl -lpthread -lSDL2_image
    INCLUDEPATH += /usr/local/include

INCLUDEPATH += Base_Classes
INCLUDEPATH += Components
INCLUDEPATH += Assets
INCLUDEPATH += Game
INCLUDEPATH += Components/Component_Managers

HEADERS += \
    Base_Classes/entity.h \
    Base_Classes/component.h \
    Base_Classes/entitymanager.h \
    Base_Classes/timer.h \
    Base_Classes/renderer.h \
    Components/sprite.h \
    Base_Classes/window.h \
    Components/transform.h \
    Base_Classes/camera.h \
    Game/game.h \
    Game/player.h \
    Components/collision.h \
    Components/Component_Managers/collisionmanager.h \
    Components/animation.h \
    Components/world.h \
    Components/ai.h

mac: LIBS += -F$$PWD/./ -framework SDL2_image

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

mac: LIBS += -framework SDL2_image
