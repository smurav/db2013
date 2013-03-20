#-------------------------------------------------
#
# Project created by QtCreator 2013-03-12T21:58:37
#
#-------------------------------------------------

QT       += core gui
TEMPLATE = app

TARGET = xmltree

# Дополнительные пути поиска заголовчных фалов
INCLUDEPATH = ../include

# Относительный путь рабочего каталога репозитория
OUTPUT = ../..

# Относительный путь каталога для хранения временных файлов
TEMP = $${OUTPUT}/temp/db2013

debug {
  DEFINES += _DEBUG
  DESTDIR = $${OUTPUT}/debug
  OBJECTS_DIR = $${TEMP}/debug
} else {
  DESTDIR = $${OUTPUT}/release
  OBJECTS_DIR = $${TEMP}/release
}

win32 {
} else {
INCLUDEPATH += /usr/include/libxml2
  #                 /usr/include
LIBS += -lxml2
}

# Путь для сохранения временных файлов Qt
MOC_DIR = $${OBJECTS_DIR}

SOURCES += main.cpp \
    xmlstructuretreeview.cpp \
    xml_libxml.cpp

HEADERS  += \
    xmlstructuretreeview.h \
    xml_libxml.h

FORMS    += \
    xmlstructuretreeview.ui

RESOURCES += \
    res/res.qrc
