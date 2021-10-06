TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        game.cpp \
        main.cpp \
        snake.cpp \
        window.cpp

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += glfw3

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += glew

HEADERS += \
    common.h \
    game.h \
    snake.h \
    window.h
