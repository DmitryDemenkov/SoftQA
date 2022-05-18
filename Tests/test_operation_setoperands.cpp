#include "test_operation_setoperands.h"
#include "../TruthTableProject/node.h"
#include "../TruthTableProject/operation.h"
#include "../TruthTableProject/variable.h"
#include "../TruthTableProject/operations/and.h"
#include "../TruthTableProject/operations/not.h"
#include "../TruthTableProject/operations/or.h"

Test_Operation_setOperands::Test_Operation_setOperands() { }

Test_Operation_setOperands::~Test_Operation_setOperands() { }

void Test_Operation_setOperands::variablesOfBinaryOperation()
{
    Variable varA;
    varA.setStringId("A");

    Variable varB;
    varB.setStringId("B");

    And operationAnd;
    operationAnd.setOperands(&varA, &varB);

    QString expectedStringId = "A&B";
    QString stringId = operationAnd.getStringId();

    QCOMPARE(stringId, expectedStringId);
}

void Test_Operation_setOperands::variableOfUnaryOperation()
{
    Variable varA;
    varA.setStringId("A");

    Not operationNot;
    operationNot.setOperands(&varA);

    QString expectedStringId = "!A";
    QString stringId = operationNot.getStringId();

    QCOMPARE(stringId, expectedStringId);
}

void Test_Operation_setOperands::lowerPriorityOperationOfBinaryOperation()
{
    Variable varB;
    varB.setStringId("B");

    Or operationOr;
    operationOr.string_id = "A||B";

    And operationAnd;
    operationAnd.setOperands(&operationOr, &varB);

    QString expectedStringId = "(A||B)&B";
    QString stringId = operationAnd.getStringId();

    QCOMPARE(stringId, expectedStringId);
}

void Test_Operation_setOperands::highPriorityOperationOfBinaryOperation()
{
    Variable varB;
    varB.setStringId("B");

    And operationAnd;
    operationAnd.string_id = "A&B";

    Or operationOr;
    operationOr.setOperands(&varB, &operationAnd);

    QString expectedStringId = "B||A&B";
    QString stringId = operationOr.getStringId();

    QCOMPARE(stringId, expectedStringId);
}

void Test_Operation_setOperands::samePriorityOperationIsLeftOperand()
{
    Variable varB;
    varB.setStringId("B");

    And operationAnd;
    operationAnd.string_id = "A&B";

    And rootOperation;
    rootOperation.setOperands(&varB, &operationAnd);

    QString expectedStringId = "B&(A&B)";
    QString stringId = rootOperation.getStringId();

    QCOMPARE(stringId, expectedStringId);
}

void Test_Operation_setOperands::samePriorityOperationIsRightOperand()
{
    Variable varB;
    varB.setStringId("B");

    And operationAnd;
    operationAnd.string_id = "A&B";

    And rootOperation;
    rootOperation.setOperands(&operationAnd, &varB);

    QString expectedStringId = "A&B&B";
    QString stringId = rootOperation.getStringId();

    QCOMPARE(stringId, expectedStringId);
}

void Test_Operation_setOperands::operationOfUnaryOperation()
{
    And operationAnd;
    operationAnd.string_id = "A&B";

    Not rootOperation;
    rootOperation.setOperands(&operationAnd);

    QString expectedStringId = "!(A&B)";
    QString stringId = rootOperation.getStringId();

    QCOMPARE(stringId, expectedStringId);
}
