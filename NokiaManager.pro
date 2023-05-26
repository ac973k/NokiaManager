QT       += core gui network core5compat

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    advanced.cpp \
    loader.cpp \
    main.cpp \
    nokiamanager.cpp \
    root.cpp \
    stock.cpp \
    stockgsi.cpp

HEADERS += \
    advanced.h \
    loader.h \
    nokiamanager.h \
    root.h \
    stock.h \
    stockgsi.h

FORMS += \
    advanced.ui \
    loader.ui \
    nokiamanager.ui \
    root.ui \
    stock.ui \
    stockgsi.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
