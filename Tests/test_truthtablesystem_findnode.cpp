#include "test_truthtablesystem_findnode.h"
#include "../TruthTableProject/truthtablesystem.h"
#include "../TruthTableProject/operations/and.h"
#include "../TruthTableProject/operations/or.h"

Test_TruthTableSystem_findNode::Test_TruthTableSystem_findNode() { }

Test_TruthTableSystem_findNode::~Test_TruthTableSystem_findNode() { }

void Test_TruthTableSystem_findNode::noNodeInVector()
{
    TruthTableSystem tts;

    Variable* varA = new Variable();
    varA->setStringId("A");

    Variable* varB = new Variable();
    varB->setStringId("B");

    Or* operationOr = new Or();
    operationOr->setOperands(varA, varB);

    tts.nodes.append(varA);
    tts.nodes.append(varB);
    tts.nodes.append(operationOr);

    And* desiredNode = new And();
    desiredNode->setOperands(varA, varB);

    Node* findedNode = tts.findNode(desiredNode);
    Node* expectedNode = NULL;

    QCOMPARE(findedNode, expectedNode);
}

void Test_TruthTableSystem_findNode::nodeAtBeginOfVector()
{
    TruthTableSystem tts;

    Variable* varA = new Variable();
    varA->setStringId("A");

    Variable* varB = new Variable();
    varB->setStringId("B");

    Or* operationOr = new Or();
    operationOr->setOperands(varA, varB);

    tts.nodes.append(varA);
    tts.nodes.append(varB);
    tts.nodes.append(operationOr);

    Variable* desiredNode = new Variable();
    desiredNode->setStringId("A");

    Node* findedNode = tts.findNode(desiredNode);
    Node* expectedNode = varA;

    QCOMPARE(findedNode, expectedNode);
}

void Test_TruthTableSystem_findNode::nodeInMiddleOfVector()
{
    TruthTableSystem tts;

    Variable* varA = new Variable();
    varA->setStringId("A");

    Variable* varB = new Variable();
    varB->setStringId("B");

    And* operationAnd = new And();
    operationAnd->setOperands(varA, varB);

    Or* operationOr = new Or();
    operationOr->setOperands(varA, varB);

    tts.nodes.append(varA);
    tts.nodes.append(varB);
    tts.nodes.append(operationAnd);
    tts.nodes.append(operationOr);

    And* desiredNode = new And();
    desiredNode->setOperands(varA, varB);

    Node* findedNode = tts.findNode(desiredNode);
    Node* expectedNode = operationAnd;

    QCOMPARE(findedNode, expectedNode);
}

void Test_TruthTableSystem_findNode::nodeInEndOfVector()
{
    TruthTableSystem tts;

    Variable* varA = new Variable();
    varA->setStringId("A");

    Variable* varB = new Variable();
    varB->setStringId("B");

    And* operationAnd = new And();
    operationAnd->setOperands(varA, varB);

    Or* operationOr = new Or();
    operationOr->setOperands(varA, varB);

    tts.nodes.append(varA);
    tts.nodes.append(varB);
    tts.nodes.append(operationAnd);
    tts.nodes.append(operationOr);

    Or* desiredNode = new Or();
    desiredNode->setOperands(varA, varB);

    Node* findedNode = tts.findNode(desiredNode);
    Node* expectedNode = operationOr;

    QCOMPARE(findedNode, expectedNode);
}
