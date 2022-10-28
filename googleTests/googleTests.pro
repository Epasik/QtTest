include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

SOURCES += \
        ../labirint/function.cpp \
        main.cpp         tst_firsttest.cpp

HEADERS += \
    ../labirint/header.h \
    test.h

INCLUDEPATH += ../labirint
