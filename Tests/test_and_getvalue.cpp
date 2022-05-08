#include "test_and_getvalue.h"
#include "../TruthTableProject/node.h"
#include "../TruthTableProject/operation.h"
#include "../TruthTableProject/variable.h"
#include "../TruthTableProject/operations/and.h"

Test_And_getValue::Test_And_getValue() { }

Test_And_getValue::~Test_And_getValue() { }

void Test_And_getValue::ConjunctionZeroAndZero()
{
    Variable variableZero;
    variableZero.setValue(0);

    And operationAnd;
    operationAnd.leftOperand = &variableZero;
    operationAnd.rightOperand = &variableZero;

    int expectedValue = 0;
    int value = operationAnd.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_And_getValue::ConjunctionZeroAndOne()
{
    Variable variableZero;
    variableZero.setValue(0);

    Variable variableOne;
    variableOne.setValue(1);

    And operationAnd;
    operationAnd.leftOperand = &variableZero;
    operationAnd.rightOperand = &variableOne;

    int expectedValue = 0;
    int value = operationAnd.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_And_getValue::ConjunctionOneAndZero()
{
    Variable variableZero;
    variableZero.setValue(0);

    Variable variableOne;
    variableOne.setValue(1);

    And operationAnd;
    operationAnd.leftOperand = &variableOne;
    operationAnd.rightOperand = &variableZero;

    int expectedValue = 0;
    int value = operationAnd.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_And_getValue::ConjunctionOneAndOne()
{
    Variable variableOne;
    variableOne.setValue(1);

    And operationAnd;
    operationAnd.leftOperand = &variableOne;
    operationAnd.rightOperand = &variableOne;

    int expectedValue = 1;
    int value = operationAnd.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_And_getValue::OperationInLeftOperand()
{
    Variable variableOne;
    variableOne.setValue(1);

    And leftOperation;
    leftOperation.leftOperand = &variableOne;
    leftOperation.rightOperand = &variableOne;

    And rootOperation;
    rootOperation.leftOperand = &leftOperation;
    rootOperation.rightOperand = &variableOne;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_And_getValue::OperationInRightOperand()
{
    Variable variableOne;
    variableOne.setValue(1);

    And rightOperation;
    rightOperation.leftOperand = &variableOne;
    rightOperation.rightOperand = &variableOne;

    And rootOperation;
    rootOperation.leftOperand = &variableOne;
    rootOperation.rightOperand = &rightOperation;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_And_getValue::OperationInBothOperands()
{
    Variable variableOne;
    variableOne.setValue(1);

    And operationAnd;
    operationAnd.leftOperand = &variableOne;
    operationAnd.rightOperand = &variableOne;

    And rootOperation;
    rootOperation.leftOperand = &operationAnd;
    rootOperation.rightOperand = &operationAnd;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_And_getValue::OperationInLeftOperandOfLeftOperand()
{
    Variable variableOne;
    variableOne.setValue(1);

    And secondLvlOperation;
    secondLvlOperation.leftOperand = &variableOne;
    secondLvlOperation.rightOperand = &variableOne;

    And firstLvlOperation;
    firstLvlOperation.leftOperand = &secondLvlOperation;
    firstLvlOperation.rightOperand = &variableOne;

    And rootOperation;
    rootOperation.leftOperand = &firstLvlOperation;
    rootOperation.rightOperand = &variableOne;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_And_getValue::OperationInRightOperandOfLeftOperand()
{
    Variable variableOne;
    variableOne.setValue(1);

    And secondLvlOperation;
    secondLvlOperation.leftOperand = &variableOne;
    secondLvlOperation.rightOperand = &variableOne;

    And firstLvlOperation;
    firstLvlOperation.leftOperand = &variableOne;
    firstLvlOperation.rightOperand = &secondLvlOperation;

    And rootOperation;
    rootOperation.leftOperand = &firstLvlOperation;
    rootOperation.rightOperand = &variableOne;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_And_getValue::OperationInLeftOperandOfRightOperand()
{
    Variable variableOne;
    variableOne.setValue(1);

    And secondLvlOperation;
    secondLvlOperation.leftOperand = &variableOne;
    secondLvlOperation.rightOperand = &variableOne;

    And firstLvlOperation;
    firstLvlOperation.leftOperand = &secondLvlOperation;
    firstLvlOperation.rightOperand = &variableOne;

    And rootOperation;
    rootOperation.leftOperand = &variableOne;
    rootOperation.rightOperand = &firstLvlOperation;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_And_getValue::OperationInRightOperandOfRightOperand()
{
    Variable variableOne;
    variableOne.setValue(1);

    And secondLvlOperation;
    secondLvlOperation.leftOperand = &variableOne;
    secondLvlOperation.rightOperand = &variableOne;

    And firstLvlOperation;
    firstLvlOperation.leftOperand = &variableOne;
    firstLvlOperation.rightOperand = &secondLvlOperation;

    And rootOperation;
    rootOperation.leftOperand = &variableOne;
    rootOperation.rightOperand = &firstLvlOperation;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}
