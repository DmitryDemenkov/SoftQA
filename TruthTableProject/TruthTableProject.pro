QT -= gui
QT += xml
QT += core5compat

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        errorcontroller.cpp \
        filemanager.cpp \
        operations/and.cpp \
        main.cpp \
        node.cpp \
        operations/eq.cpp \
        operations/imply.cpp \
        operations/nand.cpp \
        operations/nor.cpp \
        operations/not.cpp \
        operation.cpp \
        operations/or.cpp \
        operations/xor.cpp \
        truthtablesystem.cpp \
        variable.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    errorcontroller.h \
    filemanager.h \
    operations/and.h \
    node.h \
    operations/eq.h \
    operations/imply.h \
    operations/nand.h \
    operations/nor.h \
    operations/not.h \
    operation.h \
    operations/or.h \
    operations/xor.h \
    truthtablesystem.h \
    variable.h
