#include "test_truthtablesystem_gettruthtable.h"

Test_TruthTableSystem_getTruthTable::Test_TruthTableSystem_getTruthTable() { }

Test_TruthTableSystem_getTruthTable::~Test_TruthTableSystem_getTruthTable() { }

QDomNode Test_TruthTableSystem_getTruthTable::getNodeFromFile(QString fileName)
{
    QDomDocument doc(fileName);
    QFile inputFile(fileName);

    inputFile.open(QIODevice::ReadOnly);
    doc.setContent(&inputFile);
    inputFile.close();
    QDomElement docElem = doc.documentElement();

    return docElem.firstChild();
}

void Test_TruthTableSystem_getTruthTable::compareNodeNameList(QStringList &actualNames, QStringList &expectedNames)
{
    QCOMPARE(actualNames.length(), expectedNames.length());

    for (int i = 0; i < expectedNames.length(); i++)
        QCOMPARE(actualNames[i], expectedNames[i]);
}

void Test_TruthTableSystem_getTruthTable::oneUnaryOperation()
{
    QDomNode xNode = getNodeFromFile("../TestsGetTruthTable/oneUnaryOperation.xml");

    TruthTableSystem* tts = new TruthTableSystem();
    QVector<QVector<int>> values;
    tts->setXRootNode(xNode);

    QStringList actualName = tts->getTruthTable(values);

    QStringList expectedNames = {"X", "!X"};

    compareNodeNameList(actualName, expectedNames);
}

void Test_TruthTableSystem_getTruthTable::someOperationsWithIdenticalVariables()
{
    QDomNode xNode = getNodeFromFile("../TestsGetTruthTable/someOperationsWithIdenticalVariables.xml");

    TruthTableSystem* tts = new TruthTableSystem();
    QVector<QVector<int>> values;
    tts->setXRootNode(xNode);

    QStringList actualName = tts->getTruthTable(values);

    QStringList expectedNames = {"X", "!X", "!X&X"};

    compareNodeNameList(actualName, expectedNames);
}

void Test_TruthTableSystem_getTruthTable::oneBynaryOperationWithIdenticalVariables()
{
    QDomNode xNode = getNodeFromFile("../TestsGetTruthTable/oneBynaryOperationWithIdenticalVariables.xml");

    TruthTableSystem* tts = new TruthTableSystem();
    QVector<QVector<int>> values;
    tts->setXRootNode(xNode);

    QStringList actualName = tts->getTruthTable(values);

    QStringList expectedNames = {"X", "X&X"};

    compareNodeNameList(actualName, expectedNames);
}

void Test_TruthTableSystem_getTruthTable::someOperationsWithDifferentVariables()
{
    QDomNode xNode = getNodeFromFile("../TestsGetTruthTable/someOperationsWithDifferentVariables.xml");

    TruthTableSystem* tts = new TruthTableSystem();
    QVector<QVector<int>> values;
    tts->setXRootNode(xNode);

    QStringList actualName = tts->getTruthTable(values);

    QStringList expectedNames = {"X", "Y", "!X", "!X&Y"};

    compareNodeNameList(actualName, expectedNames);
}

void Test_TruthTableSystem_getTruthTable::oneRepeatingOperation()
{
    QDomNode xNode = getNodeFromFile("../TestsGetTruthTable/oneRepeatingOperation.xml");

    TruthTableSystem* tts = new TruthTableSystem();
    QVector<QVector<int>> values;
    tts->setXRootNode(xNode);

    QStringList actualName = tts->getTruthTable(values);

    QStringList expectedNames = {"X", "!X", "!X&!X"};

    compareNodeNameList(actualName, expectedNames);
}

void Test_TruthTableSystem_getTruthTable::someRepeatingOperations()
{
    QDomNode xNode = getNodeFromFile("../TestsGetTruthTable/someRepeatingOperations.xml");

    TruthTableSystem* tts = new TruthTableSystem();
    QVector<QVector<int>> values;
    tts->setXRootNode(xNode);

    QStringList actualName = tts->getTruthTable(values);

    QStringList expectedNames = {"X", "Y", "!X", "!X&Y", "!X&Y||!X&Y"};

    compareNodeNameList(actualName, expectedNames);
}
