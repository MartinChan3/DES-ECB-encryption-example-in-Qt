win32: LIBS += -L$$PWD/openssllib/ -llibeay32

win32: LIBS += -L$$PWD/openssllib/ -lssleay32

INCLUDEPATH += $$PWD/openssllib
DEPENDPATH += $$PWD/openssllib
INCLUDEPATH += $$PWD/openssllib/openssl
DEPENDPATH += $$PWD/openssllib/openssl

HEADERS += \
    $$PWD/ecryptclass.h

SOURCES += \
    $$PWD/ecryptclass.cpp
