QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../app
SOURCES += ../app/stack.cpp \
    ../app/stackemptyexception.cpp \
	../app/stackfullexception.cpp\
	tst_stacktest.cpp
