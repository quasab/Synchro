TARGET = Synhro
TEMPLATE = app
VERSION = 1.0.0

QT -= gui

CONFIG += console

DESTDIR = ./bin

RCC_DIR = ./build
MOC_DIR = ./build
OBJECTS_DIR = ./build

HEADERS += src/Counter.h \
           src/IncThread.h

SOURCES += src/Counter.cpp \
           src/IncThread.cpp \
           src/main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:QMAKE_POST_LINK += windeployqt $$OUT_PWD/$$DESTDIR


