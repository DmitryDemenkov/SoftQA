#include "test_eq_getvalue.h"
#include "../TruthTableProject/node.h"
#include "../TruthTableProject/operation.h"
#include "../TruthTableProject/variable.h"
#include "../TruthTableProject/operations/eq.h"

Test_Eq_getValue::Test_Eq_getValue() { }

Test_Eq_getValue::~Test_Eq_getValue() { }

void Test_Eq_getValue::EquivalentZeroAndZero()
{
    Variable variableZero;
    variableZero.setValue(0);

    Eq operationEq;
    operationEq.leftOperand = &variableZero;
    operationEq.rightOperand = &variableZero;

    int expectedValue = 1;
    int value = operationEq.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Eq_getValue::EquivalentZeroAndOne()
{
    Variable variableZero;
    variableZero.setValue(0);

    Variable variableOne;
    variableOne.setValue(1);

    Eq operationEq;
    operationEq.leftOperand = &variableZero;
    operationEq.rightOperand = &variableOne;

    int expectedValue = 0;
    int value = operationEq.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Eq_getValue::EquivalentOneAndZero()
{
    Variable variableZero;
    variableZero.setValue(0);

    Variable variableOne;
    variableOne.setValue(1);

    Eq operationEq;
    operationEq.leftOperand = &variableOne;
    operationEq.rightOperand = &variableZero;

    int expectedValue = 0;
    int value = operationEq.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Eq_getValue::EquivalentOneAndOne()
{
    Variable variableOne;
    variableOne.setValue(1);

    Eq operationEq;
    operationEq.leftOperand = &variableOne;
    operationEq.rightOperand = &variableOne;

    int expectedValue = 1;
    int value = operationEq.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Eq_getValue::OperationInLeftOperand()
{
    Variable variableOne;
    variableOne.setValue(1);

    Eq leftOperation;
    leftOperation.leftOperand = &variableOne;
    leftOperation.rightOperand = &variableOne;

    Eq rootOperation;
    rootOperation.leftOperand = &leftOperation;
    rootOperation.rightOperand = &variableOne;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Eq_getValue::OperationInRightOperand()
{
    Variable variableOne;
    variableOne.setValue(1);

    Eq rightOperation;
    rightOperation.leftOperand = &variableOne;
    rightOperation.rightOperand = &variableOne;

    Eq rootOperation;
    rootOperation.leftOperand = &variableOne;
    rootOperation.rightOperand = &rightOperation;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Eq_getValue::OperationInBothOperands()
{
    Variable variableOne;
    variableOne.setValue(1);

    Eq operationEq;
    operationEq.leftOperand = &variableOne;
    operationEq.rightOperand = &variableOne;

    Eq rootOperation;
    rootOperation.leftOperand = &operationEq;
    rootOperation.rightOperand = &operationEq;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Eq_getValue::OperationInLeftOperandOfLeftOperand()
{
    Variable variableOne;
    variableOne.setValue(1);

    Eq secondLvlOperation;
    secondLvlOperation.leftOperand = &variableOne;
    secondLvlOperation.rightOperand = &variableOne;

    Eq firstLvlOperation;
    firstLvlOperation.leftOperand = &secondLvlOperation;
    firstLvlOperation.rightOperand = &variableOne;

    Eq rootOperation;
    rootOperation.leftOperand = &firstLvlOperation;
    rootOperation.rightOperand = &variableOne;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Eq_getValue::OperationInRightOperandOfLeftOperand()
{
    Variable variableOne;
    variableOne.setValue(1);

    Eq secondLvlOperation;
    secondLvlOperation.leftOperand = &variableOne;
    secondLvlOperation.rightOperand = &variableOne;

    Eq firstLvlOperation;
    firstLvlOperation.leftOperand = &variableOne;
    firstLvlOperation.rightOperand = &secondLvlOperation;

    Eq rootOperation;
    rootOperation.leftOperand = &firstLvlOperation;
    rootOperation.rightOperand = &variableOne;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Eq_getValue::OperationInLeftOperandOfRightOperand()
{
    Variable variableOne;
    variableOne.setValue(1);

    Eq secondLvlOperation;
    secondLvlOperation.leftOperand = &variableOne;
    secondLvlOperation.rightOperand = &variableOne;

    Eq firstLvlOperation;
    firstLvlOperation.leftOperand = &secondLvlOperation;
    firstLvlOperation.rightOperand = &variableOne;

    Eq rootOperation;
    rootOperation.leftOperand = &variableOne;
    rootOperation.rightOperand = &firstLvlOperation;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Eq_getValue::OperationInRightOperandOfRightOperand()
{
    Variable variableOne;
    variableOne.setValue(1);

    Eq secondLvlOperation;
    secondLvlOperation.leftOperand = &variableOne;
    secondLvlOperation.rightOperand = &variableOne;

    Eq firstLvlOperation;
    firstLvlOperation.leftOperand = &variableOne;
    firstLvlOperation.rightOperand = &secondLvlOperation;

    Eq rootOperation;
    rootOperation.leftOperand = &variableOne;
    rootOperation.rightOperand = &firstLvlOperation;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}
