#include "test_nor_getvalue.h"
#include "../TruthTableProject/node.h"
#include "../TruthTableProject/operation.h"
#include "../TruthTableProject/variable.h"
#include "../TruthTableProject/operations/nor.h"

Test_Nor_getValue::Test_Nor_getValue() { }

Test_Nor_getValue::~Test_Nor_getValue() { }

void Test_Nor_getValue::NORZeroAndZero()
{
    Variable variableZero;
    variableZero.setValue(0);

    Nor operationNor;
    operationNor.leftOperand = &variableZero;
    operationNor.rightOperand = &variableZero;

    int expectedValue = 1;
    int value = operationNor.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Nor_getValue::NORZeroAndOne()
{
    Variable variableZero;
    variableZero.setValue(0);

    Variable variableOne;
    variableOne.setValue(1);

    Nor operationNor;
    operationNor.leftOperand = &variableZero;
    operationNor.rightOperand = &variableOne;

    int expectedValue = 0;
    int value = operationNor.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Nor_getValue::NOROneAndZero()
{
    Variable variableZero;
    variableZero.setValue(0);

    Variable variableOne;
    variableOne.setValue(1);

    Nor operationNor;
    operationNor.leftOperand = &variableOne;
    operationNor.rightOperand = &variableZero;

    int expectedValue = 0;
    int value = operationNor.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Nor_getValue::NOROneAndOne()
{
    Variable variableOne;
    variableOne.setValue(1);

    Nor operationNor;
    operationNor.leftOperand = &variableOne;
    operationNor.rightOperand = &variableOne;

    int expectedValue = 0;
    int value = operationNor.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Nor_getValue::OperationInLeftOperand()
{
    Variable variableZero;
    variableZero.setValue(0);

    Variable variableOne;
    variableOne.setValue(1);

    Nor leftOperation;
    leftOperation.leftOperand = &variableOne;
    leftOperation.rightOperand = &variableZero;

    Nor rootOperation;
    rootOperation.leftOperand = &leftOperation;
    rootOperation.rightOperand = &variableZero;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Nor_getValue::OperationInRightOperand()
{
    Variable variableZero;
    variableZero.setValue(0);

    Variable variableOne;
    variableOne.setValue(1);

    Nor rightOperation;
    rightOperation.leftOperand = &variableZero;
    rightOperation.rightOperand = &variableOne;

    Nor rootOperation;
    rootOperation.leftOperand = &variableZero;
    rootOperation.rightOperand = &rightOperation;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Nor_getValue::OperationInBothOperands()
{
    Variable variableOne;
    variableOne.setValue(1);

    Nor operationNor;
    operationNor.leftOperand = &variableOne;
    operationNor.rightOperand = &variableOne;

    Nor rootOperation;
    rootOperation.leftOperand = &operationNor;
    rootOperation.rightOperand = &operationNor;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Nor_getValue::OperationInLeftOperandOfLeftOperand()
{
    Variable variableZero;
    variableZero.setValue(0);

    Variable variableOne;
    variableOne.setValue(1);

    Nor secondLvlOperation;
    secondLvlOperation.leftOperand = &variableOne;
    secondLvlOperation.rightOperand = &variableOne;

    Nor firstLvlOperation;
    firstLvlOperation.leftOperand = &secondLvlOperation;
    firstLvlOperation.rightOperand = &variableOne;

    Nor rootOperation;
    rootOperation.leftOperand = &firstLvlOperation;
    rootOperation.rightOperand = &variableZero;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Nor_getValue::OperationInRightOperandOfLeftOperand()
{
    Variable variableZero;
    variableZero.setValue(0);

    Variable variableOne;
    variableOne.setValue(1);

    Nor secondLvlOperation;
    secondLvlOperation.leftOperand = &variableOne;
    secondLvlOperation.rightOperand = &variableOne;

    Nor firstLvlOperation;
    firstLvlOperation.leftOperand = &variableOne;
    firstLvlOperation.rightOperand = &secondLvlOperation;

    Nor rootOperation;
    rootOperation.leftOperand = &firstLvlOperation;
    rootOperation.rightOperand = &variableZero;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Nor_getValue::OperationInLeftOperandOfRightOperand()
{
    Variable variableZero;
    variableZero.setValue(0);

    Variable variableOne;
    variableOne.setValue(1);

    Nor secondLvlOperation;
    secondLvlOperation.leftOperand = &variableOne;
    secondLvlOperation.rightOperand = &variableOne;

    Nor firstLvlOperation;
    firstLvlOperation.leftOperand = &secondLvlOperation;
    firstLvlOperation.rightOperand = &variableOne;

    Nor rootOperation;
    rootOperation.leftOperand = &variableZero;
    rootOperation.rightOperand = &firstLvlOperation;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Nor_getValue::OperationInRightOperandOfRightOperand()
{
    Variable variableZero;
    variableZero.setValue(0);

    Variable variableOne;
    variableOne.setValue(1);

    Nor secondLvlOperation;
    secondLvlOperation.leftOperand = &variableOne;
    secondLvlOperation.rightOperand = &variableOne;

    Nor firstLvlOperation;
    firstLvlOperation.leftOperand = &variableOne;
    firstLvlOperation.rightOperand = &secondLvlOperation;

    Nor rootOperation;
    rootOperation.leftOperand = &variableZero;
    rootOperation.rightOperand = &firstLvlOperation;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}
