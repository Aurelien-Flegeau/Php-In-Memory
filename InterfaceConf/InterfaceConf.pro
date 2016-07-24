QT       += core gui
LIBS+=-static-libgcc
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    form.cpp

HEADERS += \
    form.h
