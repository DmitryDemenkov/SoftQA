#include "test_truthtablesystem_maketruthtable.h"
#include "../TruthTableProject/operations/and.h"
#include "../TruthTableProject/operations/or.h"
#include "../TruthTableProject/operations/not.h"
#include "../TruthTableProject/operations/imply.h"

Test_TruthTableSystem_makeTruthTable::Test_TruthTableSystem_makeTruthTable() { }

Test_TruthTableSystem_makeTruthTable::~Test_TruthTableSystem_makeTruthTable() { }

void Test_TruthTableSystem_makeTruthTable::compareMatrix(QVector<QVector<int>> &actualMatrix, QVector<QVector<int>> &expectedMatrix)
{
    QCOMPARE(actualMatrix, expectedMatrix);

    for (int i = 0; i < expectedMatrix.length(); i++)
    {
        QCOMPARE(actualMatrix[i].length(), expectedMatrix[i].length());

        for (int j = 0; j < expectedMatrix[i].length(); j++)
            QCOMPARE(actualMatrix[i][j], expectedMatrix[i][j]);
    }
}


void Test_TruthTableSystem_makeTruthTable::oneVariableOneOperation()
{
    TruthTableSystem* tts = new TruthTableSystem();

    Variable* varX = new Variable();
    varX->setStringId("X");

    Not* operationNot = new Not();
    operationNot->setOperands(varX);

    tts->nodes.append(varX);
    tts->nodes.append(operationNot);
    tts->variablesAmount = 1;

    tts->makeTruthTable();

    QVector<QVector<int>> expectedMatrix = {
        {0, 1},
        {1, 0}
    };

    compareMatrix(tts->values, expectedMatrix);
}

void Test_TruthTableSystem_makeTruthTable::oneVariableTwoOperations()
{
    TruthTableSystem* tts = new TruthTableSystem();

    Variable* varX = new Variable();
    varX->setStringId("X");

    Not* operationNot = new Not();
    operationNot->setOperands(varX);

    Or* operationOr = new Or();
    operationOr->setOperands(varX, operationNot);

    tts->nodes.append(varX);
    tts->nodes.append(operationNot);
    tts->nodes.append(operationOr);
    tts->variablesAmount = 1;

    tts->makeTruthTable();

    QVector<QVector<int>> expectedMatrix = {
        {0, 1, 1},
        {1, 0, 1}
    };

    compareMatrix(tts->values, expectedMatrix);
}

void Test_TruthTableSystem_makeTruthTable::twoVariablesOneOperation()
{
    TruthTableSystem* tts = new TruthTableSystem();

    Variable* varX = new Variable();
    varX->setStringId("X");

    Variable* varY = new Variable();
    varY->setStringId("Y");

    And* operationAnd = new And();
    operationAnd->setOperands(varX, varY);

    tts->nodes.append(varX);
    tts->nodes.append(varY);
    tts->nodes.append(operationAnd);
    tts->variablesAmount = 2;

    tts->makeTruthTable();

    QVector<QVector<int>> expectedMatrix = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 0, 0},
        {1, 1, 1}
    };

    compareMatrix(tts->values, expectedMatrix);
}

void Test_TruthTableSystem_makeTruthTable::twoVariablesTwoOperations()
{
    TruthTableSystem* tts = new TruthTableSystem();

    Variable* varX = new Variable();
    varX->setStringId("X");

    Variable* varY = new Variable();
    varY->setStringId("Y");

    And* operationAnd = new And();
    operationAnd->setOperands(varX, varY);

    Not* operationNot = new Not();
    operationNot->setOperands(operationAnd);

    tts->nodes.append(varX);
    tts->nodes.append(varY);
    tts->nodes.append(operationAnd);
    tts->nodes.append(operationNot);
    tts->variablesAmount = 2;

    tts->makeTruthTable();

    QVector<QVector<int>> expectedMatrix = {
        {0, 0, 0, 1},
        {0, 1, 0, 1},
        {1, 0, 0, 1},
        {1, 1, 1, 0}
    };

    compareMatrix(tts->values, expectedMatrix);
}

void Test_TruthTableSystem_makeTruthTable::someVariablesSomeOperations()
{
    TruthTableSystem* tts = new TruthTableSystem();

    Variable* varX = new Variable();
    varX->setStringId("X");

    Variable* varY = new Variable();
    varY->setStringId("Y");

    Variable* varZ = new Variable();
    varZ->setStringId("Z");

    And* operationAnd = new And();
    operationAnd->setOperands(varX, varY);

    Or* operationOr = new Or();
    operationOr->setOperands(varX, operationAnd);

    Not* operationNot = new Not();
    operationNot->setOperands(varZ);

    Imply* operationImply = new Imply();
    operationImply->setOperands(operationOr, operationNot);

    tts->nodes.append(varX);
    tts->nodes.append(varY);
    tts->nodes.append(varZ);
    tts->nodes.append(operationAnd);
    tts->nodes.append(operationOr);
    tts->nodes.append(operationNot);
    tts->nodes.append(operationImply);
    tts->variablesAmount = 3;

    tts->makeTruthTable();

    QVector<QVector<int>> expectedMatrix = {
        {0, 0, 0, 0, 0, 1, 1},
        {0, 0, 1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 1, 1},
        {0, 1, 1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 1, 1},
        {1, 0, 1, 0, 1, 0, 0},
        {1, 1, 0, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 0, 0}
    };

    compareMatrix(tts->values, expectedMatrix);
}
