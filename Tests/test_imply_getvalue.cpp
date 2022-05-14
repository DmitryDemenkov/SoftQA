#include "test_imply_getvalue.h"
#include "../TruthTableProject/node.h"
#include "../TruthTableProject/operation.h"
#include "../TruthTableProject/variable.h"
#include "../TruthTableProject/operations/imply.h"

Test_Imply_getValue::Test_Imply_getValue() { }

Test_Imply_getValue::~Test_Imply_getValue() { }

void Test_Imply_getValue::ImplicationZeroAndZero()
{
    Variable variableZero;
    variableZero.setValue(0);

    Imply operationImply;
    operationImply.leftOperand = &variableZero;
    operationImply.rightOperand = &variableZero;

    int expectedValue = 1;
    int value = operationImply.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Imply_getValue::ImplicationZeroAndOne()
{
    Variable variableZero;
    variableZero.setValue(0);

    Variable variableOne;
    variableOne.setValue(1);

    Imply operationImply;
    operationImply.leftOperand = &variableZero;
    operationImply.rightOperand = &variableOne;

    int expectedValue = 1;
    int value = operationImply.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Imply_getValue::ImplicationOneAndZero()
{
    Variable variableZero;
    variableZero.setValue(0);

    Variable variableOne;
    variableOne.setValue(1);

    Imply operationImply;
    operationImply.leftOperand = &variableOne;
    operationImply.rightOperand = &variableZero;

    int expectedValue = 0;
    int value = operationImply.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Imply_getValue::ImplicationOneAndOne()
{
    Variable variableOne;
    variableOne.setValue(1);

    Imply operationImply;
    operationImply.leftOperand = &variableOne;
    operationImply.rightOperand = &variableOne;

    int expectedValue = 1;
    int value = operationImply.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Imply_getValue::OperationInLeftOperand()
{
    Variable variableOne;
    variableOne.setValue(1);

    Imply leftOperation;
    leftOperation.leftOperand = &variableOne;
    leftOperation.rightOperand = &variableOne;

    Imply rootOperation;
    rootOperation.leftOperand = &leftOperation;
    rootOperation.rightOperand = &variableOne;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Imply_getValue::OperationInRightOperand()
{
    Variable variableOne;
    variableOne.setValue(1);

    Imply rightOperation;
    rightOperation.leftOperand = &variableOne;
    rightOperation.rightOperand = &variableOne;

    Imply rootOperation;
    rootOperation.leftOperand = &variableOne;
    rootOperation.rightOperand = &rightOperation;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Imply_getValue::OperationInBothOperands()
{
    Variable variableOne;
    variableOne.setValue(1);

    Imply operationImply;
    operationImply.leftOperand = &variableOne;
    operationImply.rightOperand = &variableOne;

    Imply rootOperation;
    rootOperation.leftOperand = &operationImply;
    rootOperation.rightOperand = &operationImply;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Imply_getValue::OperationInLeftOperandOfLeftOperand()
{
    Variable variableOne;
    variableOne.setValue(1);

    Imply secondLvlOperation;
    secondLvlOperation.leftOperand = &variableOne;
    secondLvlOperation.rightOperand = &variableOne;

    Imply firstLvlOperation;
    firstLvlOperation.leftOperand = &secondLvlOperation;
    firstLvlOperation.rightOperand = &variableOne;

    Imply rootOperation;
    rootOperation.leftOperand = &firstLvlOperation;
    rootOperation.rightOperand = &variableOne;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Imply_getValue::OperationInRightOperandOfLeftOperand()
{
    Variable variableOne;
    variableOne.setValue(1);

    Imply secondLvlOperation;
    secondLvlOperation.leftOperand = &variableOne;
    secondLvlOperation.rightOperand = &variableOne;

    Imply firstLvlOperation;
    firstLvlOperation.leftOperand = &variableOne;
    firstLvlOperation.rightOperand = &secondLvlOperation;

    Imply rootOperation;
    rootOperation.leftOperand = &firstLvlOperation;
    rootOperation.rightOperand = &variableOne;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Imply_getValue::OperationInLeftOperandOfRightOperand()
{
    Variable variableOne;
    variableOne.setValue(1);

    Imply secondLvlOperation;
    secondLvlOperation.leftOperand = &variableOne;
    secondLvlOperation.rightOperand = &variableOne;

    Imply firstLvlOperation;
    firstLvlOperation.leftOperand = &secondLvlOperation;
    firstLvlOperation.rightOperand = &variableOne;

    Imply rootOperation;
    rootOperation.leftOperand = &variableOne;
    rootOperation.rightOperand = &firstLvlOperation;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Imply_getValue::OperationInRightOperandOfRightOperand()
{
    Variable variableOne;
    variableOne.setValue(1);

    Imply secondLvlOperation;
    secondLvlOperation.leftOperand = &variableOne;
    secondLvlOperation.rightOperand = &variableOne;

    Imply firstLvlOperation;
    firstLvlOperation.leftOperand = &variableOne;
    firstLvlOperation.rightOperand = &secondLvlOperation;

    Imply rootOperation;
    rootOperation.leftOperand = &variableOne;
    rootOperation.rightOperand = &firstLvlOperation;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}
