QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-MyDLL_Example-Desktop_Qt_5_12_0_MinGW_64_bit-Release/release/ -lMyDLL_Example
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-MyDLL_Example-Desktop_Qt_5_12_0_MinGW_64_bit-Release/debug/ -lMyDLL_Example
else:unix: LIBS += -L$$PWD/../build-MyDLL_Example-Desktop_Qt_5_12_0_MinGW_64_bit-Release/ -lMyDLL_Example

INCLUDEPATH += $$PWD/../MyDLL_Example
DEPENDPATH += $$PWD/../MyDLL_Example

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-MyStaticLib_Example-Desktop_Qt_5_12_0_MinGW_64_bit-Release/release/ -lMyStaticLib_Example
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-MyStaticLib_Example-Desktop_Qt_5_12_0_MinGW_64_bit-Release/debug/ -lMyStaticLib_Example
else:unix: LIBS += -L$$PWD/../build-MyStaticLib_Example-Desktop_Qt_5_12_0_MinGW_64_bit-Release/ -lMyStaticLib_Example

INCLUDEPATH += $$PWD/../MyStaticLib_Example
DEPENDPATH += $$PWD/../MyStaticLib_Example

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-MyStaticLib_Example-Desktop_Qt_5_12_0_MinGW_64_bit-Release/release/libMyStaticLib_Example.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-MyStaticLib_Example-Desktop_Qt_5_12_0_MinGW_64_bit-Release/debug/libMyStaticLib_Example.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-MyStaticLib_Example-Desktop_Qt_5_12_0_MinGW_64_bit-Release/release/MyStaticLib_Example.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-MyStaticLib_Example-Desktop_Qt_5_12_0_MinGW_64_bit-Release/debug/MyStaticLib_Example.lib
else:unix: PRE_TARGETDEPS += $$PWD/../build-MyStaticLib_Example-Desktop_Qt_5_12_0_MinGW_64_bit-Release/libMyStaticLib_Example.a
