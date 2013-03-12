#-------------------------------------------------
#
# Project created by QtCreator 2013-03-12T18:51:29
#
#-------------------------------------------------

QT       += core gui

# Дополнительные пути поиска заголовчных фалов
INCLUDEPATH += /usr/include/libxml2

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
#  INCLUDEPATH += /usr/include/postgresql\
#                 /usr/include/postgresql/libpq\
#                 /usr/include/libxml2\
#                 /usr/include
#  LIBS += -lxml2 -lpq
}

RCC_DIR = ./res


# Путь для сохранения временных файлов Qt
MOC_DIR = $${OBJECTS_DIR}


TARGET = xmlparser
TEMPLATE = app

LIBS += -lxml2


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
