#-------------------------------------------------
#
# Project created by QtCreator 2016-09-06T09:06:05
#
#-------------------------------------------------

QT       += core gui multimedia #opengl
QT       += xml xmlpatterns svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = imp
TEMPLATE = app

VERSION = 0.7.3
QMAKE_TARGET_COMPANY = EternalDusk
QMAKE_TARGET_DESCRIPTION = Eve Online Intelligence Management Program
QMAKE_TARGET_COPYRIGHT = (c) Copyright 2016-2017 Jesse Litton
QMAKE_TARGET_PRODUCT = IMP

SOURCES += \
    main.cpp\
    mainwindow.cpp \
    logcatcher.cpp \
    chatmodel.cpp \
    asyncinfo.cpp \
    map.cpp \
    audio.cpp \
    options.cpp \
    rulemodel.cpp \
    svgmapview.cpp \
    finddialog.cpp \
    info.cpp \
    parser.cpp \
    bridgemap.cpp \
    mapshape.cpp \
    themedialog.cpp \
    theme.cpp \
    systemshape.cpp \
    chatitemdelegate.cpp \
    mapscene.cpp \
    findmessagesdialog.cpp \
    abstract_os.cpp \
    themecustomizationdialog.cpp
    
HEADERS  += \
    mainwindow.h \
    logcatcher.h \
    chatmodel.h \
    asyncinfo.h \
    map.h \
    audio.h \
    options.h \
    rulemodel.h \
    svgmapview.h \
    finddialog.h \
    meta.h \
    info.h \
    parser.h \
    bridgemap.h \
    mapshape.h \
    themedialog.h \
    theme.h \
    systemshape.h \
    chatitemdelegate.h \
    mapscene.h \
    findmessagesdialog.h \
    abstract_os.h \
    themecustomizationdialog.h
    
FORMS    += \
    mainwindow.ui \
    options.ui \
    finddialog.ui \
    info.ui \
    themedialog.ui \
    findmessagesdialog.ui \
    themecustomizationdialog.ui
    
DISTFILES += \
    ../data/dictionaries/clear \
    ../data/dictionaries/common \
    ../data/dictionaries/local \
    ../data/dictionaries/location \
    ../data/dictionaries/ships \
    ../data/dictionaries/status \
    ../docs/FAQ \
    ../docs/RELEASES \
    ../docs/RULES \
    ../docs/THEMES \
    ../docs/CREDITS
    
RESOURCES += \
    resources.qrc

RC_ICONS = impicon.ico

# Disable stripping so it doesn't try to do the audio/text files
QMAKE_STRIP = echo

imp_bin.files += imp
imp_bin.path = /usr/bin
unix:imp_bin.extra = strip $(TARGET);cp -f $(TARGET) /usr/bin/$(TARGET)

imp_docs.files = ../docs/*
imp_docs.path = /usr/share/doc/imp

imp_icon.files = graphics/impicon.png
imp_icon.path = /usr/share/imp/

imp_shortcut.files = imp.desktop
imp_shortcut.path = /usr/share/applications

imp_data.files = ../data/*
imp_data.path = /usr/share/imp/

INSTALLS += \
    imp_bin \
    imp_data \
    imp_docs \
    imp_icon \
    imp_shortcut

