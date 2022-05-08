#include "test_or_getvalue.h"
#include "../TruthTableProject/node.h"
#include "../TruthTableProject/operation.h"
#include "../TruthTableProject/variable.h"
#include "../TruthTableProject/operations/or.h"

Test_Or_getValue::Test_Or_getValue() { }

Test_Or_getValue::~Test_Or_getValue() { }

void Test_Or_getValue::DisjunctionZeroAndZero()
{
    Variable variableZero;
    variableZero.setValue(0);

    Or operationOr;
    operationOr.leftOperand = &variableZero;
    operationOr.rightOperand = &variableZero;

    int expectedValue = 0;
    int value = operationOr.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Or_getValue::DisjunctionZeroAndOne()
{
    Variable variableZero;
    variableZero.setValue(0);

    Variable variableOne;
    variableOne.setValue(1);

    Or operationOr;
    operationOr.leftOperand = &variableZero;
    operationOr.rightOperand = &variableOne;

    int expectedValue = 1;
    int value = operationOr.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Or_getValue::DisjunctionOneAndZero()
{
    Variable variableZero;
    variableZero.setValue(0);

    Variable variableOne;
    variableOne.setValue(1);

    Or operationOr;
    operationOr.leftOperand = &variableOne;
    operationOr.rightOperand = &variableZero;

    int expectedValue = 1;
    int value = operationOr.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Or_getValue::DisjunctionOneAndOne()
{
    Variable variableOne;
    variableOne.setValue(1);

    Or operationOr;
    operationOr.leftOperand = &variableOne;
    operationOr.rightOperand = &variableOne;

    int expectedValue = 1;
    int value = operationOr.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Or_getValue::OperationInLeftOperand()
{
    Variable variableZero;
    variableZero.setValue(0);

    Variable variableOne;
    variableOne.setValue(1);

    Or leftOperation;
    leftOperation.leftOperand = &variableOne;
    leftOperation.rightOperand = &variableOne;

    Or rootOperation;
    rootOperation.leftOperand = &leftOperation;
    rootOperation.rightOperand = &variableZero;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Or_getValue::OperationInRightOperand()
{
    Variable variableZero;
    variableZero.setValue(0);

    Variable variableOne;
    variableOne.setValue(1);

    Or rightOperation;
    rightOperation.leftOperand = &variableOne;
    rightOperation.rightOperand = &variableOne;

    Or rootOperation;
    rootOperation.leftOperand = &variableZero;
    rootOperation.rightOperand = &rightOperation;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Or_getValue::OperationInBothOperands()
{
    Variable variableOne;
    variableOne.setValue(1);

    Or operationOr;
    operationOr.leftOperand = &variableOne;
    operationOr.rightOperand = &variableOne;

    Or rootOperation;
    rootOperation.leftOperand = &operationOr;
    rootOperation.rightOperand = &operationOr;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Or_getValue::OperationInLeftOperandOfLeftOperand()
{
    Variable variableZero;
    variableZero.setValue(0);

    Variable variableOne;
    variableOne.setValue(1);

    Or secondLvlOperation;
    secondLvlOperation.leftOperand = &variableOne;
    secondLvlOperation.rightOperand = &variableOne;

    Or firstLvlOperation;
    firstLvlOperation.leftOperand = &secondLvlOperation;
    firstLvlOperation.rightOperand = &variableZero;

    Or rootOperation;
    rootOperation.leftOperand = &firstLvlOperation;
    rootOperation.rightOperand = &variableZero;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Or_getValue::OperationInRightOperandOfLeftOperand()
{
    Variable variableZero;
    variableZero.setValue(0);

    Variable variableOne;
    variableOne.setValue(1);

    Or secondLvlOperation;
    secondLvlOperation.leftOperand = &variableOne;
    secondLvlOperation.rightOperand = &variableOne;

    Or firstLvlOperation;
    firstLvlOperation.leftOperand = &variableZero;
    firstLvlOperation.rightOperand = &secondLvlOperation;

    Or rootOperation;
    rootOperation.leftOperand = &firstLvlOperation;
    rootOperation.rightOperand = &variableZero;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Or_getValue::OperationInLeftOperandOfRightOperand()
{
    Variable variableZero;
    variableZero.setValue(0);

    Variable variableOne;
    variableOne.setValue(1);

    Or secondLvlOperation;
    secondLvlOperation.leftOperand = &variableOne;
    secondLvlOperation.rightOperand = &variableOne;

    Or firstLvlOperation;
    firstLvlOperation.leftOperand = &secondLvlOperation;
    firstLvlOperation.rightOperand = &variableZero;

    Or rootOperation;
    rootOperation.leftOperand = &variableZero;
    rootOperation.rightOperand = &firstLvlOperation;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Or_getValue::OperationInRightOperandOfRightOperand()
{
    Variable variableZero;
    variableZero.setValue(0);

    Variable variableOne;
    variableOne.setValue(1);

    Or secondLvlOperation;
    secondLvlOperation.leftOperand = &variableOne;
    secondLvlOperation.rightOperand = &variableOne;

    Or firstLvlOperation;
    firstLvlOperation.leftOperand = &variableZero;
    firstLvlOperation.rightOperand = &secondLvlOperation;

    Or rootOperation;
    rootOperation.leftOperand = &variableZero;
    rootOperation.rightOperand = &firstLvlOperation;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}
