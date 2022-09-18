QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../app

SOURCES += ../app/queue.cpp \
    ../app/queueemptyexception.cpp \
	../app/queuefullexception.cpp \
	tst_queuetests.cpp
