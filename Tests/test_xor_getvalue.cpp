#include "test_xor_getvalue.h"
#include "../TruthTableProject/node.h"
#include "../TruthTableProject/operation.h"
#include "../TruthTableProject/variable.h"
#include "../TruthTableProject/operations/xor.h"

Test_Xor_getValue::Test_Xor_getValue() { }

Test_Xor_getValue::~Test_Xor_getValue() { }

void Test_Xor_getValue::XORZeroAndZero()
{
    Variable variableZero;
    variableZero.setValue(0);

    Xor operationXor;
    operationXor.leftOperand = &variableZero;
    operationXor.rightOperand = &variableZero;

    int expectedValue = 0;
    int value = operationXor.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Xor_getValue::XORZeroAndOne()
{
    Variable variableZero;
    variableZero.setValue(0);

    Variable variableOne;
    variableOne.setValue(1);

    Xor operationXor;
    operationXor.leftOperand = &variableZero;
    operationXor.rightOperand = &variableOne;

    int expectedValue = 1;
    int value = operationXor.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Xor_getValue::XOROneAndZero()
{
    Variable variableZero;
    variableZero.setValue(0);

    Variable variableOne;
    variableOne.setValue(1);

    Xor operationXor;
    operationXor.leftOperand = &variableOne;
    operationXor.rightOperand = &variableZero;

    int expectedValue = 1;
    int value = operationXor.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Xor_getValue::XOROneAndOne()
{
    Variable variableOne;
    variableOne.setValue(1);

    Xor operationXor;
    operationXor.leftOperand = &variableOne;
    operationXor.rightOperand = &variableOne;

    int expectedValue = 0;
    int value = operationXor.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Xor_getValue::OperationInLeftOperand()
{
    Variable variableZero;
    variableZero.setValue(0);

    Variable variableOne;
    variableOne.setValue(1);

    Xor leftOperation;
    leftOperation.leftOperand = &variableZero;
    leftOperation.rightOperand = &variableOne;

    Xor rootOperation;
    rootOperation.leftOperand = &leftOperation;
    rootOperation.rightOperand = &variableZero;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Xor_getValue::OperationInRightOperand()
{
    Variable variableZero;
    variableZero.setValue(0);

    Variable variableOne;
    variableOne.setValue(1);

    Xor rightOperation;
    rightOperation.leftOperand = &variableZero;
    rightOperation.rightOperand = &variableOne;

    Xor rootOperation;
    rootOperation.leftOperand = &variableZero;
    rootOperation.rightOperand = &rightOperation;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Xor_getValue::OperationInBothOperands()
{
    Variable variableZero;
    variableZero.setValue(0);

    Variable variableOne;
    variableOne.setValue(1);

    Xor leftOperation;
    leftOperation.leftOperand = &variableZero;
    leftOperation.rightOperand = &variableOne;

    Xor rightOperand;
    rightOperand.leftOperand = &variableZero;
    rightOperand.leftOperand = &variableZero;

    Xor rootOperation;
    rootOperation.leftOperand = &leftOperation;
    rootOperation.rightOperand = &rightOperand;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Xor_getValue::OperationInLeftOperandOfLeftOperand()
{
    Variable variableZero;
    variableZero.setValue(0);

    Variable variableOne;
    variableOne.setValue(1);

    Xor secondLvlOperation;
    secondLvlOperation.leftOperand = &variableZero;
    secondLvlOperation.rightOperand = &variableOne;

    Xor firstLvlOperation;
    firstLvlOperation.leftOperand = &secondLvlOperation;
    firstLvlOperation.rightOperand = &variableZero;

    Xor rootOperation;
    rootOperation.leftOperand = &firstLvlOperation;
    rootOperation.rightOperand = &variableZero;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Xor_getValue::OperationInRightOperandOfLeftOperand()
{
    Variable variableZero;
    variableZero.setValue(0);

    Variable variableOne;
    variableOne.setValue(1);

    Xor secondLvlOperation;
    secondLvlOperation.leftOperand = &variableZero;
    secondLvlOperation.rightOperand = &variableOne;

    Xor firstLvlOperation;
    firstLvlOperation.leftOperand = &variableZero;
    firstLvlOperation.rightOperand = &secondLvlOperation;

    Xor rootOperation;
    rootOperation.leftOperand = &firstLvlOperation;
    rootOperation.rightOperand = &variableZero;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Xor_getValue::OperationInLeftOperandOfRightOperand()
{
    Variable variableZero;
    variableZero.setValue(0);

    Variable variableOne;
    variableOne.setValue(1);

    Xor secondLvlOperation;
    secondLvlOperation.leftOperand = &variableZero;
    secondLvlOperation.rightOperand = &variableOne;

    Xor firstLvlOperation;
    firstLvlOperation.leftOperand = &secondLvlOperation;
    firstLvlOperation.rightOperand = &variableZero;

    Xor rootOperation;
    rootOperation.leftOperand = &variableZero;
    rootOperation.rightOperand = &firstLvlOperation;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}

void Test_Xor_getValue::OperationInRightOperandOfRightOperand()
{
    Variable variableZero;
    variableZero.setValue(0);

    Variable variableOne;
    variableOne.setValue(1);

    Xor secondLvlOperation;
    secondLvlOperation.leftOperand = &variableZero;
    secondLvlOperation.rightOperand = &variableOne;

    Xor firstLvlOperation;
    firstLvlOperation.leftOperand = &variableZero;
    firstLvlOperation.rightOperand = &secondLvlOperation;

    Xor rootOperation;
    rootOperation.leftOperand = &variableZero;
    rootOperation.rightOperand = &firstLvlOperation;

    int expectedValue = 1;
    int value = rootOperation.getValue();

    QCOMPARE(value, expectedValue);
}
