#include "test_not_getvalue.h"
#include "../TruthTableProject/node.h"
#include "../TruthTableProject/operation.h"
#include "../TruthTableProject/variable.h"
#include "../TruthTableProject/not.h"

Test_Not_getValue::Test_Not_getValue() { }

Test_Not_getValue::~Test_Not_getValue() { }

void Test_Not_getValue::InversionZero()
{
    Variable variable;
    variable.setValue(0);

    Not operationNot;
    operationNot.leftOperand = &variable;

    int expectedValue = 1;
    int value = operationNot.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Not_getValue::InversionOne()
{
    Variable variable;
    variable.setValue(1);

    Not operationNot;
    operationNot.leftOperand = &variable;

    int expectedValue = 0;
    int value = operationNot.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Not_getValue::DoubleInversion()
{
    Variable variable;
    variable.setValue(1);

    Not firstOperationNot;
    firstOperationNot.leftOperand = &variable;

    Not secondOperationNot;
    secondOperationNot.leftOperand = &firstOperationNot;

    int expectedValue = 1;
    int value = secondOperationNot.getValue();

    QCOMPARE(value, expectedValue);
}

QTEST_APPLESS_MAIN(Test_Not_getValue);
