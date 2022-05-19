QT += testlib
QT += xml

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        ../TruthTableProject/node.cpp \
        ../TruthTableProject/variable.cpp \
        ../TruthTableProject/operation.cpp \
        ../TruthTableProject/operations/not.cpp \
        ../TruthTableProject/operations/and.cpp \
        ../TruthTableProject/operations/or.cpp \
        ../TruthTableProject/operations/xor.cpp \
        ../TruthTableProject/operations/imply.cpp \
        ../TruthTableProject/operations/eq.cpp \
        ../TruthTableProject/operations/nand.cpp \
        ../TruthTableProject/operations/nor.cpp \
        ../TruthTableProject/errorcontroller.cpp \
        main.cpp \
        test_and_getvalue.cpp \
        test_eq_getvalue.cpp \
        test_errorcontroller_isrootnodecorrect.cpp \
        test_imply_getvalue.cpp \
        test_nand_getvalue.cpp \
        test_nor_getvalue.cpp \
        test_not_getvalue.cpp \
        test_operation_getoperation.cpp \
        test_operation_setoperands.cpp \
        test_or_getvalue.cpp \
        test_xor_getvalue.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    test_and_getvalue.h \
    test_eq_getvalue.h \
    test_errorcontroller_isrootnodecorrect.h \
    test_imply_getvalue.h \
    test_nand_getvalue.h \
    test_nor_getvalue.h \
    test_not_getvalue.h \
    test_operation_getoperation.h \
    test_operation_setoperands.h \
    test_or_getvalue.h \
    test_xor_getvalue.h
