#include "test_truthtablesystem_insertnode.h"
#include "../TruthTableProject/operations/and.h"
#include "../TruthTableProject/operations/not.h"

Test_TruthTableSystem_insertNode::Test_TruthTableSystem_insertNode() { }

Test_TruthTableSystem_insertNode::~Test_TruthTableSystem_insertNode() { }

void Test_TruthTableSystem_insertNode::compareNodeVectors(QVector<Node *> &actualVector, QVector<Node *> &expectedVector)
{
    QCOMPARE(actualVector.length(), expectedVector.length());

    for (int i = 0; i < expectedVector.length(); i++)
        QCOMPARE(actualVector[i]->getStringId(), expectedVector[i]->getStringId());
}

void Test_TruthTableSystem_insertNode::insertVariableIntoMiddle()
{
    TruthTableSystem tts;

    Variable* varA = new Variable();
    varA->setStringId("A");

    Variable* varB = new Variable();
    varB->setStringId("B");

    Not* operationNot = new Not();
    operationNot->setOperands(varA);

    tts.nodes.append(varA);
    tts.nodes.append(operationNot);

    QVector<Node*> expectedVector;
    expectedVector.append(varA);
    expectedVector.append(varB);
    expectedVector.append(operationNot);

    int expectedValue = 1;

    Variable* addingNode = new Variable();
    addingNode->setStringId("B");

    int value = tts.insertNode(addingNode);

    compareNodeVectors(tts.nodes, expectedVector);
    QCOMPARE(value, expectedValue);
}

void Test_TruthTableSystem_insertNode::insertVariableIntoBegin()
{
    TruthTableSystem tts;

    Variable* varA = new Variable();
    varA->setStringId("A");

    Not* operationNot = new Not();
    operationNot->setOperands(varA);

    tts.nodes.append(operationNot);

    QVector<Node*> expectedVector;
    expectedVector.append(varA);
    expectedVector.append(operationNot);

    int expectedValue = 1;

    Variable* addingNode = new Variable();
    addingNode->setStringId("A");

    int value = tts.insertNode(addingNode);

    compareNodeVectors(tts.nodes, expectedVector);
    QCOMPARE(value, expectedValue);
}

void Test_TruthTableSystem_insertNode::insertVariableIntoEnd()
{
    TruthTableSystem tts;

    Variable* varA = new Variable();
    varA->setStringId("A");

    Variable* varB = new Variable();
    varB->setStringId("B");

    Variable* varC = new Variable();
    varC->setStringId("C");

    tts.nodes.append(varA);
    tts.nodes.append(varB);

    QVector<Node*> expectedVector;
    expectedVector.append(varA);
    expectedVector.append(varB);
    expectedVector.append(varC);

    int expectedValue = 1;

    Variable* addingNode = new Variable();
    addingNode->setStringId("C");

    int value = tts.insertNode(addingNode);

    compareNodeVectors(tts.nodes, expectedVector);
    QCOMPARE(value, expectedValue);
}

void Test_TruthTableSystem_insertNode::insertOperationIntoVectorWithVariables()
{
    TruthTableSystem tts;

    Variable* varA = new Variable();
    varA->setStringId("A");

    Variable* varB = new Variable();
    varB->setStringId("B");

    And* operationAnd = new And();
    operationAnd->setOperands(varA, varB);

    tts.nodes.append(varA);
    tts.nodes.append(varB);

    QVector<Node*> expectedVector;
    expectedVector.append(varA);
    expectedVector.append(varB);
    expectedVector.append(operationAnd);

    int expectedValue = 0;

    And* addingNode = new And();
    addingNode->setOperands(varA, varB);

    int value = tts.insertNode(addingNode);

    compareNodeVectors(tts.nodes, expectedVector);
    QCOMPARE(value, expectedValue);
}

void Test_TruthTableSystem_insertNode::insertOperationIntoVectorWithOperation()
{
    TruthTableSystem tts;

    Variable* varA = new Variable();
    varA->setStringId("A");

    Variable* varB = new Variable();
    varB->setStringId("B");

    Not* operationNot = new Not();
    operationNot->setOperands(varA);

    And* operationAnd = new And();
    operationAnd->setOperands(varA, varB);

    tts.nodes.append(operationNot);

    QVector<Node*> expectedVector;
    expectedVector.append(operationNot);
    expectedVector.append(operationAnd);

    int expectedValue = 0;

    And* addingNode = new And();
    addingNode->setOperands(varA, varB);

    int value = tts.insertNode(addingNode);

    compareNodeVectors(tts.nodes, expectedVector);
    QCOMPARE(value, expectedValue);
}

void Test_TruthTableSystem_insertNode::insertOperationIntoVectorWithVariableAndOperation()
{
    TruthTableSystem tts;

    Variable* varA = new Variable();
    varA->setStringId("A");

    Variable* varB = new Variable();
    varB->setStringId("B");

    Not* operationNot = new Not();
    operationNot->setOperands(varA);

    And* operationAnd = new And();
    operationAnd->setOperands(varA, varB);

    tts.nodes.append(varA);
    tts.nodes.append(operationNot);

    QVector<Node*> expectedVector;
    expectedVector.append(varA);
    expectedVector.append(operationNot);
    expectedVector.append(operationAnd);

    int expectedValue = 0;

    And* addingNode = new And();
    addingNode->setOperands(varA, varB);

    int value = tts.insertNode(addingNode);

    compareNodeVectors(tts.nodes, expectedVector);
    QCOMPARE(value, expectedValue);
}

void Test_TruthTableSystem_insertNode::insertVariableIntoEmptyVector()
{
    TruthTableSystem tts;

    Variable* varA = new Variable();
    varA->setStringId("A");

    QVector<Node*> expectedVector;
    expectedVector.append(varA);

    int expectedValue = 1;

    Variable* addingNode = new Variable();
    addingNode->setStringId("A");

    int value = tts.insertNode(addingNode);

    compareNodeVectors(tts.nodes, expectedVector);
    QCOMPARE(value, expectedValue);
}

void Test_TruthTableSystem_insertNode::insertOperationIntoEmptyVector()
{
    TruthTableSystem tts;

    Variable* varA = new Variable();
    varA->setStringId("A");

    Variable* varB = new Variable();
    varB->setStringId("B");

    And* operationAnd = new And();
    operationAnd->setOperands(varA, varB);

    QVector<Node*> expectedVector;
    expectedVector.append(operationAnd);

    int expectedValue = 0;

    And* addingNode = new And();
    addingNode->setOperands(varA, varB);

    int value = tts.insertNode(addingNode);

    compareNodeVectors(tts.nodes, expectedVector);
    QCOMPARE(value, expectedValue);
}
