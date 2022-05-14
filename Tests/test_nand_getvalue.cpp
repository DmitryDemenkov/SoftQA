#include "test_nand_getvalue.h"
#include "../TruthTableProject/node.h"
#include "../TruthTableProject/operation.h"
#include "../TruthTableProject/variable.h"
#include "../TruthTableProject/operations/nand.h"

Test_Nand_getValue::Test_Nand_getValue() { }

Test_Nand_getValue::~Test_Nand_getValue() { }

void Test_Nand_getValue::NANDZeroAndZero()
{
    Variable variableZero;
    variableZero.setValue(0);

    Nand operationNand;
    operationNand.leftOperand = &variableZero;
    operationNand.rightOperand = &variableZero;

    int expectedValue = 1;
    int value = operationNand.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Nand_getValue::NANDZeroAndOne()
{
    Variable variableZero;
    variableZero.setValue(0);

    Variable variableOne;
    variableOne.setValue(1);

    Nand operationNand;
    operationNand.leftOperand = &variableZero;
    operationNand.rightOperand = &variableOne;

    int expectedValue = 1;
    int value = operationNand.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Nand_getValue::NANDOneAndZero()
{
    Variable variableZero;
    variableZero.setValue(0);

    Variable variableOne;
    variableOne.setValue(1);

    Nand operationNand;
    operationNand.leftOperand = &variableOne;
    operationNand.rightOperand = &variableZero;

    int expectedValue = 1;
    int value = operationNand.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Nand_getValue::NANDOneAndOne()
{
    Variable variableOne;
    variableOne.setValue(1);

    Nand operationNand;
    operationNand.leftOperand = &variableOne;
    operationNand.rightOperand = &variableOne;

    int expectedValue = 0;
    int value = operationNand.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Nand_getValue::OperationInLeftOperand()
{
    Variable variableZero;
    variableZero.setValue(0);

    Nand leftOperation;
    leftOperation.leftOperand = &variableZero;
    leftOperation.rightOperand = &variableZero;

    Nand rootOperation;
    rootOperation.leftOperand = &leftOperation;
    rootOperation.rightOperand = &variableZero;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Nand_getValue::OperationInRightOperand()
{
    Variable variableZero;
    variableZero.setValue(0);

    Nand rightOperation;
    rightOperation.leftOperand = &variableZero;
    rightOperation.rightOperand = &variableZero;

    Nand rootOperation;
    rootOperation.leftOperand = &variableZero;
    rootOperation.rightOperand = &rightOperation;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Nand_getValue::OperationInBothOperands()
{
    Variable variableZero;
    variableZero.setValue(0);

    Variable variableOne;
    variableZero.setValue(1);

    Nand leftOperation;
    leftOperation.leftOperand = &variableZero;
    leftOperation.rightOperand = &variableZero;

    Nand rightOperation;
    rightOperation.leftOperand = &variableOne;
    rightOperation.rightOperand = &variableOne;

    Nand rootOperation;
    rootOperation.leftOperand = &leftOperation;
    rootOperation.rightOperand = &rightOperation;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Nand_getValue::OperationInLeftOperandOfLeftOperand()
{
    Variable variableZero;
    variableZero.setValue(0);

    Variable variableOne;
    variableOne.setValue(1);

    Nand secondLvlOperation;
    secondLvlOperation.leftOperand = &variableZero;
    secondLvlOperation.rightOperand = &variableZero;

    Nand firstLvlOperation;
    firstLvlOperation.leftOperand = &secondLvlOperation;
    firstLvlOperation.rightOperand = &variableOne;

    Nand rootOperation;
    rootOperation.leftOperand = &firstLvlOperation;
    rootOperation.rightOperand = &variableZero;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Nand_getValue::OperationInRightOperandOfLeftOperand()
{
    Variable variableZero;
    variableZero.setValue(0);

    Variable variableOne;
    variableOne.setValue(1);

    Nand secondLvlOperation;
    secondLvlOperation.leftOperand = &variableZero;
    secondLvlOperation.rightOperand = &variableZero;

    Nand firstLvlOperation;
    firstLvlOperation.leftOperand = &variableOne;
    firstLvlOperation.rightOperand = &secondLvlOperation;

    Nand rootOperation;
    rootOperation.leftOperand = &firstLvlOperation;
    rootOperation.rightOperand = &variableZero;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Nand_getValue::OperationInLeftOperandOfRightOperand()
{
    Variable variableZero;
    variableZero.setValue(0);

    Variable variableOne;
    variableOne.setValue(1);

    Nand secondLvlOperation;
    secondLvlOperation.leftOperand = &variableZero;
    secondLvlOperation.rightOperand = &variableZero;

    Nand firstLvlOperation;
    firstLvlOperation.leftOperand = &secondLvlOperation;
    firstLvlOperation.rightOperand = &variableOne;

    Nand rootOperation;
    rootOperation.leftOperand = &variableZero;
    rootOperation.rightOperand = &firstLvlOperation;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Nand_getValue::OperationInRightOperandOfRightOperand()
{
    Variable variableZero;
    variableZero.setValue(0);

    Variable variableOne;
    variableOne.setValue(1);

    Nand secondLvlOperation;
    secondLvlOperation.leftOperand = &variableZero;
    secondLvlOperation.rightOperand = &variableZero;

    Nand firstLvlOperation;
    firstLvlOperation.leftOperand = &variableOne;
    firstLvlOperation.rightOperand = &secondLvlOperation;

    Nand rootOperation;
    rootOperation.leftOperand = &variableZero;
    rootOperation.rightOperand = &firstLvlOperation;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}
