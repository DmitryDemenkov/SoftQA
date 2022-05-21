#include "test_truthtablesystem_parseexpression.h"

Test_TruthTableSystem_parseExpression::Test_TruthTableSystem_parseExpression() { }

Test_TruthTableSystem_parseExpression::~Test_TruthTableSystem_parseExpression() { }

QDomNode Test_TruthTableSystem_parseExpression::getNodeFromFile(QString fileName)
{
    QDomDocument doc(fileName);
    QFile inputFile(fileName);

    inputFile.open(QIODevice::ReadOnly);
    doc.setContent(&inputFile);
    inputFile.close();
    QDomElement docElem = doc.documentElement();

    return docElem.firstChild();
}

void Test_TruthTableSystem_parseExpression::compareNodeVectors(QVector<Node *> &actualVector, QStringList &expectedVector)
{
    QCOMPARE(actualVector.length(), expectedVector.length());

    for (int i = 0; i < expectedVector.length(); i++)
        QCOMPARE(actualVector[i]->getStringId(), expectedVector[i]);
}

void Test_TruthTableSystem_parseExpression::variableNode()
{
    QString inputFileName = "../TestsParseExpression/variableNode.xml";
    QDomNode xNode = getNodeFromFile(inputFileName);

    TruthTableSystem* tts = new TruthTableSystem();

    Node* actualNode = tts->parseExpression(xNode);

    QString expectedNodeName = "X";
    QStringList expectedNodeList = {"X"};

    bool isNULL = actualNode == NULL;

    QVERIFY(!isNULL);
    if (!isNULL)
    {
        QCOMPARE(actualNode->getStringId(), expectedNodeName);
        compareNodeVectors(tts->nodes, expectedNodeList);
    }
}

void Test_TruthTableSystem_parseExpression::unaryOperationNode()
{
    QString inputFileName = "../TestsParseExpression/unaryOperationNode.xml";
    QDomNode xNode = getNodeFromFile(inputFileName);

    TruthTableSystem* tts = new TruthTableSystem();

    Node* actualNode = tts->parseExpression(xNode);

    QString expectedNodeName = "!X";
    QStringList expectedNodeList = {"X", "!X"};

    bool isNULL = actualNode == NULL;

    QVERIFY(!isNULL);
    if (!isNULL)
    {
        QCOMPARE(actualNode->getStringId(), expectedNodeName);
        compareNodeVectors(tts->nodes, expectedNodeList);
    }
}

void Test_TruthTableSystem_parseExpression::nestedUnaryOperation()
{
    QString inputFileName = "../TestsParseExpression/nestedUnaryOperation.xml";
    QDomNode xNode = getNodeFromFile(inputFileName);

    TruthTableSystem* tts = new TruthTableSystem();

    Node* actualNode = tts->parseExpression(xNode);

    QString expectedNodeName = "!!X";
    QStringList expectedNodeList = {"X", "!X", "!!X"};

    bool isNULL = actualNode == NULL;

    QVERIFY(!isNULL);
    if (!isNULL)
    {
        QCOMPARE(actualNode->getStringId(), expectedNodeName);
        compareNodeVectors(tts->nodes, expectedNodeList);
    }
}

void Test_TruthTableSystem_parseExpression::bynaryOperationWithIdenticalVariables()
{
    QString inputFileName = "../TestsParseExpression/bynaryOperationWithIdenticalVariables.xml";
    QDomNode xNode = getNodeFromFile(inputFileName);

    TruthTableSystem* tts = new TruthTableSystem();

    Node* actualNode = tts->parseExpression(xNode);

    QString expectedNodeName = "X&X";
    QStringList expectedNodeList = {"X", "X&X"};

    bool isNULL = actualNode == NULL;

    QVERIFY(!isNULL);
    if (!isNULL)
    {
        QCOMPARE(actualNode->getStringId(), expectedNodeName);
        compareNodeVectors(tts->nodes, expectedNodeList);
    }
}

void Test_TruthTableSystem_parseExpression::conjunctionNode()
{
    QString inputFileName = "../TestsParseExpression/conjunctionNode.xml";
    QDomNode xNode = getNodeFromFile(inputFileName);

    TruthTableSystem* tts = new TruthTableSystem();

    Node* actualNode = tts->parseExpression(xNode);

    QString expectedNodeName = "X&Y";
    QStringList expectedNodeList = {"X", "Y", "X&Y"};

    bool isNULL = actualNode == NULL;

    QVERIFY(!isNULL);
    if (!isNULL)
    {
        QCOMPARE(actualNode->getStringId(), expectedNodeName);
        compareNodeVectors(tts->nodes, expectedNodeList);
    }
}

void Test_TruthTableSystem_parseExpression::disjunctionNode()
{
    QString inputFileName = "../TestsParseExpression/disjunctionNode.xml";
    QDomNode xNode = getNodeFromFile(inputFileName);

    TruthTableSystem* tts = new TruthTableSystem();

    Node* actualNode = tts->parseExpression(xNode);

    QString expectedNodeName = "X||Y";
    QStringList expectedNodeList = {"X", "Y", "X||Y"};

    bool isNULL = actualNode == NULL;

    QVERIFY(!isNULL);
    if (!isNULL)
    {
        QCOMPARE(actualNode->getStringId(), expectedNodeName);
        compareNodeVectors(tts->nodes, expectedNodeList);
    }
}

void Test_TruthTableSystem_parseExpression::XORNode()
{
    QString inputFileName = "../TestsParseExpression/XORNode.xml";
    QDomNode xNode = getNodeFromFile(inputFileName);

    TruthTableSystem* tts = new TruthTableSystem();

    Node* actualNode = tts->parseExpression(xNode);

    QString expectedNodeName = "X⊕Y";
    QStringList expectedNodeList = {"X", "Y", "X⊕Y"};

    bool isNULL = actualNode == NULL;

    QVERIFY(!isNULL);
    if (!isNULL)
    {
        QCOMPARE(actualNode->getStringId(), expectedNodeName);
        compareNodeVectors(tts->nodes, expectedNodeList);
    }
}

void Test_TruthTableSystem_parseExpression::implicationaNode()
{
    QString inputFileName = "../TestsParseExpression/implicationaNode.xml";
    QDomNode xNode = getNodeFromFile(inputFileName);

    TruthTableSystem* tts = new TruthTableSystem();

    Node* actualNode = tts->parseExpression(xNode);

    QString expectedNodeName = "X=>Y";
    QStringList expectedNodeList = {"X", "Y", "X=>Y"};

    bool isNULL = actualNode == NULL;

    QVERIFY(!isNULL);
    if (!isNULL)
    {
        QCOMPARE(actualNode->getStringId(), expectedNodeName);
        compareNodeVectors(tts->nodes, expectedNodeList);
    }
}

void Test_TruthTableSystem_parseExpression::equivalentNode()
{
    QString inputFileName = "../TestsParseExpression/equivalentNode.xml";
    QDomNode xNode = getNodeFromFile(inputFileName);

    TruthTableSystem* tts = new TruthTableSystem();

    Node* actualNode = tts->parseExpression(xNode);

    QString expectedNodeName = "X<=>Y";
    QStringList expectedNodeList = {"X", "Y", "X<=>Y"};

    bool isNULL = actualNode == NULL;

    QVERIFY(!isNULL);
    if (!isNULL)
    {
        QCOMPARE(actualNode->getStringId(), expectedNodeName);
        compareNodeVectors(tts->nodes, expectedNodeList);
    }
}

void Test_TruthTableSystem_parseExpression::NANDNode()
{
    QString inputFileName = "../TestsParseExpression/NANDNode.xml";
    QDomNode xNode = getNodeFromFile(inputFileName);

    TruthTableSystem* tts = new TruthTableSystem();

    Node* actualNode = tts->parseExpression(xNode);

    QString expectedNodeName = "X|Y";
    QStringList expectedNodeList = {"X", "Y", "X|Y"};

    bool isNULL = actualNode == NULL;

    QVERIFY(!isNULL);
    if (!isNULL)
    {
        QCOMPARE(actualNode->getStringId(), expectedNodeName);
        compareNodeVectors(tts->nodes, expectedNodeList);
    }
}

void Test_TruthTableSystem_parseExpression::NORNode()
{
    QString inputFileName = "../TestsParseExpression/NORNode.xml";
    QDomNode xNode = getNodeFromFile(inputFileName);

    TruthTableSystem* tts = new TruthTableSystem();

    Node* actualNode = tts->parseExpression(xNode);

    QString expectedNodeName = "X↓Y";
    QStringList expectedNodeList = {"X", "Y", "X↓Y"};

    bool isNULL = actualNode == NULL;

    QVERIFY(!isNULL);
    if (!isNULL)
    {
        QCOMPARE(actualNode->getStringId(), expectedNodeName);
        compareNodeVectors(tts->nodes, expectedNodeList);
    }
}

void Test_TruthTableSystem_parseExpression::operationIsLeftOperand()
{
    QString inputFileName = "../TestsParseExpression/operationIsLeftOperand.xml";
    QDomNode xNode = getNodeFromFile(inputFileName);

    TruthTableSystem* tts = new TruthTableSystem();

    Node* actualNode = tts->parseExpression(xNode);

    QString expectedNodeName = "X&Y&X";
    QStringList expectedNodeList = {"X", "Y", "X&Y", "X&Y&X"};

    bool isNULL = actualNode == NULL;

    QVERIFY(!isNULL);
    if (!isNULL)
    {
        QCOMPARE(actualNode->getStringId(), expectedNodeName);
        compareNodeVectors(tts->nodes, expectedNodeList);
    }
}

void Test_TruthTableSystem_parseExpression::operationIsRightOperand()
{
    QString inputFileName = "../TestsParseExpression/operationIsRightOperand.xml";
    QDomNode xNode = getNodeFromFile(inputFileName);

    TruthTableSystem* tts = new TruthTableSystem();

    Node* actualNode = tts->parseExpression(xNode);

    QString expectedNodeName = "X&(X&Y)";
    QStringList expectedNodeList = {"X", "Y", "X&Y", "X&(X&Y)"};

    bool isNULL = actualNode == NULL;

    QVERIFY(!isNULL);
    if (!isNULL)
    {
        QCOMPARE(actualNode->getStringId(), expectedNodeName);
        compareNodeVectors(tts->nodes, expectedNodeList);
    }
}

void Test_TruthTableSystem_parseExpression::operationIsLeftOperandOfLeftOperand()
{
    QString inputFileName = "../TestsParseExpression/operationIsLeftOperandOfLeftOperand.xml";
    QDomNode xNode = getNodeFromFile(inputFileName);

    TruthTableSystem* tts = new TruthTableSystem();

    Node* actualNode = tts->parseExpression(xNode);

    QString expectedNodeName = "X&Z&Y&X";
    QStringList expectedNodeList = {"X", "Z", "Y", "X&Z", "X&Z&Y", "X&Z&Y&X"};

    bool isNULL = actualNode == NULL;

    QVERIFY(!isNULL);
    if (!isNULL)
    {
        QCOMPARE(actualNode->getStringId(), expectedNodeName);
        compareNodeVectors(tts->nodes, expectedNodeList);
    }
}

void Test_TruthTableSystem_parseExpression::operationIsRightOperandOfLeftOperand()
{
    QString inputFileName = "../TestsParseExpression/operationIsRightOperandOfLeftOperand.xml";
    QDomNode xNode = getNodeFromFile(inputFileName);

    TruthTableSystem* tts = new TruthTableSystem();

    Node* actualNode = tts->parseExpression(xNode);

    QString expectedNodeName = "Y&(X&Z)&X";
    QStringList expectedNodeList = {"Y", "X", "Z", "X&Z", "Y&(X&Z)", "Y&(X&Z)&X"};

    bool isNULL = actualNode == NULL;

    QVERIFY(!isNULL);
    if (!isNULL)
    {
        QCOMPARE(actualNode->getStringId(), expectedNodeName);
        compareNodeVectors(tts->nodes, expectedNodeList);
    }
}

void Test_TruthTableSystem_parseExpression::operationIsLeftOperandOfRightOperand()
{
    QString inputFileName = "../TestsParseExpression/operationIsLeftOperandOfRightOperand.xml";
    QDomNode xNode = getNodeFromFile(inputFileName);

    TruthTableSystem* tts = new TruthTableSystem();

    Node* actualNode = tts->parseExpression(xNode);

    QString expectedNodeName = "X&(X&Z&Y)";
    QStringList expectedNodeList = {"X", "Z", "Y", "X&Z", "X&Z&Y", "X&(X&Z&Y)"};

    bool isNULL = actualNode == NULL;

    QVERIFY(!isNULL);
    if (!isNULL)
    {
        QCOMPARE(actualNode->getStringId(), expectedNodeName);
        compareNodeVectors(tts->nodes, expectedNodeList);
    }
}

void Test_TruthTableSystem_parseExpression::operationIsRightOperandOfRightOperand()
{
    QString inputFileName = "../TestsParseExpression/operationIsRightOperandOfRightOperand.xml";
    QDomNode xNode = getNodeFromFile(inputFileName);

    TruthTableSystem* tts = new TruthTableSystem();

    Node* actualNode = tts->parseExpression(xNode);

    QString expectedNodeName = "X&(Y&(X&Z))";
    QStringList expectedNodeList = {"X", "Y", "Z", "X&Z", "Y&(X&Z)", "X&(Y&(X&Z))"};

    bool isNULL = actualNode == NULL;

    QVERIFY(!isNULL);
    if (!isNULL)
    {
        QCOMPARE(actualNode->getStringId(), expectedNodeName);
        compareNodeVectors(tts->nodes, expectedNodeList);
    }
}

void Test_TruthTableSystem_parseExpression::bynaryOperationIsOperandOfUnaryOne()
{
    QString inputFileName = "../TestsParseExpression/bynaryOperationIsOperandOfUnaryOne.xml";
    QDomNode xNode = getNodeFromFile(inputFileName);

    TruthTableSystem* tts = new TruthTableSystem();

    Node* actualNode = tts->parseExpression(xNode);

    QString expectedNodeName = "!(X&Y)";
    QStringList expectedNodeList = {"X", "Y", "X&Y", "!(X&Y)"};

    bool isNULL = actualNode == NULL;

    QVERIFY(!isNULL);
    if (!isNULL)
    {
        QCOMPARE(actualNode->getStringId(), expectedNodeName);
        compareNodeVectors(tts->nodes, expectedNodeList);
    }
}

void Test_TruthTableSystem_parseExpression::unaryOperationIsLeftOperandOfBynaryOne()
{
    QString inputFileName = "../TestsParseExpression/unaryOperationIsLeftOperandOfBynaryOne.xml";
    QDomNode xNode = getNodeFromFile(inputFileName);

    TruthTableSystem* tts = new TruthTableSystem();

    Node* actualNode = tts->parseExpression(xNode);

    QString expectedNodeName = "!X&Y";
    QStringList expectedNodeList = {"X", "Y", "!X", "!X&Y"};

    bool isNULL = actualNode == NULL;

    QVERIFY(!isNULL);
    if (!isNULL)
    {
        QCOMPARE(actualNode->getStringId(), expectedNodeName);
        compareNodeVectors(tts->nodes, expectedNodeList);
    }
}

void Test_TruthTableSystem_parseExpression::unaryOperationIsRightOperandOfBynaryOne()
{
    QString inputFileName = "../TestsParseExpression/unaryOperationIsRightOperandOfBynaryOne.xml";
    QDomNode xNode = getNodeFromFile(inputFileName);

    TruthTableSystem* tts = new TruthTableSystem();

    Node* actualNode = tts->parseExpression(xNode);

    QString expectedNodeName = "X&!Y";
    QStringList expectedNodeList = {"X", "Y", "!Y", "X&!Y"};

    bool isNULL = actualNode == NULL;

    QVERIFY(!isNULL);
    if (!isNULL)
    {
        QCOMPARE(actualNode->getStringId(), expectedNodeName);
        compareNodeVectors(tts->nodes, expectedNodeList);
    }
}
