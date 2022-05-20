#include <QFile>
#include "test_errorcontroller_isoperationcorrect.h"
#include "../TruthTableProject/errorcontroller.h"

Test_ErrorController_isOperationCorrect::Test_ErrorController_isOperationCorrect() { }

Test_ErrorController_isOperationCorrect::~Test_ErrorController_isOperationCorrect() { }

QDomNode Test_ErrorController_isOperationCorrect::getNodeFromFile(QString fileName)
{
    QDomDocument doc(fileName);
    QFile inputFile(fileName);

    inputFile.open(QIODevice::ReadOnly);
    doc.setContent(&inputFile);
    inputFile.close();
    QDomElement docElem = doc.documentElement();

    return docElem.firstChild();
}

void Test_ErrorController_isOperationCorrect::incorrectNodeName()
{
    QString inputFileName = "../TestsIsOperationCorrect/incorrectNodeName.xml";
    QDomNode docNode = getNodeFromFile(inputFileName);

    bool isCorrect = false;
    ErrorController controller;

    ErrorController::ErrorType expectedErrorType = ErrorController::INCORRECT_NODE_NAME;
    QString expectedMessege = "Неподходящее имя узла «inversion».\nИспользуйте «operation» для обозначения узла операции и «variable» для обозначения узла переменной";

    try
    {
        isCorrect = controller.isOperationCorrect(docNode);
        QVERIFY(!isCorrect);
    }
    catch (ErrorController::Error error)
    {
        QCOMPARE(error.errorType, expectedErrorType);
        QCOMPARE(error.errorMessege, expectedMessege);
    }
}

void Test_ErrorController_isOperationCorrect::noNecessaryAttributes()
{
    QString inputFileName = "../TestsIsOperationCorrect/noNecessaryAttributes.xml";
    QDomNode docNode = getNodeFromFile(inputFileName);

    bool isCorrect = false;
    ErrorController controller;

    ErrorController::ErrorType expectedErrorType = ErrorController::NO_ATTRIBUTES_IN_OPERATION;
    QString expectedMessege = "Узел операции не содержит следующего атрибута: «type»";

    try
    {
        isCorrect = controller.isOperationCorrect(docNode);
        QVERIFY(!isCorrect);
    }
    catch (ErrorController::Error error)
    {
        QCOMPARE(error.errorType, expectedErrorType);
        QCOMPARE(error.errorMessege, expectedMessege);
    }
}

void Test_ErrorController_isOperationCorrect::incorrectAttributeTag()
{
    QString inputFileName = "../TestsIsOperationCorrect/incorrectAttributeTag.xml";
    QDomNode docNode = getNodeFromFile(inputFileName);

    bool isCorrect = false;
    ErrorController controller;

    ErrorController::ErrorType expectedErrorType = ErrorController::INCORRECT_ATTRIBUTE_IN_OPERATION;
    QString expectedMessege = "Неверное название атрибута «name» узла «operation»\nУзел операции должен иметь следующий атрибут: «type»";

    try
    {
        isCorrect = controller.isOperationCorrect(docNode);
        QVERIFY(!isCorrect);
    }
    catch (ErrorController::Error error)
    {
        QCOMPARE(error.errorType, expectedErrorType);
        QCOMPARE(error.errorMessege, expectedMessege);
    }
}

void Test_ErrorController_isOperationCorrect::tooManyAttributes()
{
    QString inputFileName = "../TestsIsOperationCorrect/tooManyAttributes.xml";
    QDomNode docNode = getNodeFromFile(inputFileName);

    bool isCorrect = false;
    ErrorController controller;

    ErrorController::ErrorType expectedErrorType = ErrorController::TOO_MANY_ATTRIBUTES_IN_OPERATION;
    QString expectedMessege = "Узел операции содержит слишком много атрибутов";

    try
    {
        isCorrect = controller.isOperationCorrect(docNode);
        QVERIFY(!isCorrect);
    }
    catch (ErrorController::Error error)
    {
        QCOMPARE(error.errorType, expectedErrorType);
        QCOMPARE(error.errorMessege, expectedMessege);
    }
}

void Test_ErrorController_isOperationCorrect::noChildNodes()
{
    QString inputFileName = "../TestsIsOperationCorrect/noChildNodes.xml";
    QDomNode docNode = getNodeFromFile(inputFileName);

    bool isCorrect = false;
    ErrorController controller;

    ErrorController::ErrorType expectedErrorType = ErrorController::NO_CHILDREN_IN_OPERATION;
    QString expectedMessege = "Узел операции «not» не содержит дочерних узлов.\nУзел операции должен содержать дочерние узлы переменных или других операций";

    try
    {
        isCorrect = controller.isOperationCorrect(docNode);
        QVERIFY(!isCorrect);
    }
    catch (ErrorController::Error error)
    {
        QCOMPARE(error.errorType, expectedErrorType);
        QCOMPARE(error.errorMessege, expectedMessege);
    }
}

void Test_ErrorController_isOperationCorrect::tooManyChildNodes()
{
    QString inputFileName = "../TestsIsOperationCorrect/tooManyChildNodes.xml";
    QDomNode docNode = getNodeFromFile(inputFileName);

    bool isCorrect = false;
    ErrorController controller;

    ErrorController::ErrorType expectedErrorType = ErrorController::TOO_MANY_CHILDREN_IN_OPERATION;
    QString expectedMessege = "Узел операции «not» содержит слишком много дочерних узлов.\nУзел операции должен содержать один дочерний узел, если она унарная, или два, если бинарная";

    try
    {
        isCorrect = controller.isOperationCorrect(docNode);
        QVERIFY(!isCorrect);
    }
    catch (ErrorController::Error error)
    {
        QCOMPARE(error.errorType, expectedErrorType);
        QCOMPARE(error.errorMessege, expectedMessege);
    }
}

void Test_ErrorController_isOperationCorrect::incorrectAttributeValue()
{
    QString inputFileName = "../TestsIsOperationCorrect/incorrectAttributeValue.xml";
    QDomNode docNode = getNodeFromFile(inputFileName);

    bool isCorrect = false;
    ErrorController controller;

    ErrorController::ErrorType expectedErrorType = ErrorController::INCORRECT_TYPE_OF_OPERATION;
    QString expectedMessege = "Неправильно задан тип операции «!»\nДля обозначения типа операции следуетиспользовать следующие обозначения: «not», «and», «or», «xor», «imply», «eq», «nand», «nor»";

    try
    {
        isCorrect = controller.isOperationCorrect(docNode);
        QVERIFY(!isCorrect);
    }
    catch (ErrorController::Error error)
    {
        QCOMPARE(error.errorType, expectedErrorType);
        QCOMPARE(error.errorMessege, expectedMessege);
    }
}

void Test_ErrorController_isOperationCorrect::correctNode()
{
    QString inputFileName = "../TestsIsVariableCorrect/correctNode.xml";
    QDomNode docNode = getNodeFromFile(inputFileName);

    bool isCorrect = false;
    ErrorController controller;

    try
    {
        isCorrect = controller.isOperationCorrect(docNode);
        QVERIFY(isCorrect);
    }
    catch (ErrorController::Error error)
    {
        bool noException = false;
        QVERIFY(noException);
    }
}
