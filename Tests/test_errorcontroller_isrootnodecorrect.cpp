#include <QFile>
#include <QCoreApplication>
#include "test_errorcontroller_isrootnodecorrect.h"
#include "../TruthTableProject/errorcontroller.h"


Test_ErrorController_isRootNodeCorrect::Test_ErrorController_isRootNodeCorrect() { }

Test_ErrorController_isRootNodeCorrect::~Test_ErrorController_isRootNodeCorrect() { }

QDomElement Test_ErrorController_isRootNodeCorrect::getRootNodeFromFile(QString fileName)
{
    QDomDocument doc(fileName);
    QFile inputFile(fileName);

    inputFile.open(QIODevice::ReadOnly);
    doc.setContent(&inputFile);
    inputFile.close();

    return doc.documentElement();
}

void Test_ErrorController_isRootNodeCorrect::tooManyChilds()
{
    QString inputFileName = "../TestsIsRootNodeCorrect/tooManyChilds.xml";
    QDomElement docElem = getRootNodeFromFile(inputFileName);

    bool isCorrect = false;
    ErrorController controller;

    ErrorController::ErrorType expectedErrorType = ErrorController::TOO_MANY_CHILD_NODES_IN_ROOT;
    QString expectedMessege = "В корневом узле входного файла слишком много дочерних узлов.\nДерево разбора выражения может иметь только один корень";

    try
    {
        isCorrect = controller.isRootNodeCorrect(docElem);
        QVERIFY(!isCorrect);
    }
    catch (ErrorController::Error error)
    {
        QCOMPARE(error.errorType, expectedErrorType);
        QCOMPARE(error.errorMessege, expectedMessege);
    }
}

void Test_ErrorController_isRootNodeCorrect::noChilds()
{
    QString inputFileName = "../TestsIsRootNodeCorrect/noChilds.xml";
    QDomElement docElem = getRootNodeFromFile(inputFileName);

    bool isCorrect = false;
    ErrorController controller;

    ErrorController::ErrorType expectedErrorType = ErrorController::NO_CHILD_NODES_IN_ROOT;
    QString expectedMessege = "В корневом узле входного файла отсутствуют дочерние узлы.\nДерево разбора выражения не может быть пустым";

    try
    {
        isCorrect = controller.isRootNodeCorrect(docElem);
        QVERIFY(!isCorrect);
    }
    catch (ErrorController::Error error)
    {
        QCOMPARE(error.errorType, expectedErrorType);
        QCOMPARE(error.errorMessege, expectedMessege);
    }
    //QVERIFY(isCorrect);
}

void Test_ErrorController_isRootNodeCorrect::variableInRootNode()
{
    QString inputFileName = "../TestsIsRootNodeCorrect/variableInRootNode.xml";
    QDomElement docElem = getRootNodeFromFile(inputFileName);

    bool isCorrect = false;
    ErrorController controller;

    ErrorController::ErrorType expectedErrorType = ErrorController::VARIABLE_IN_ROOT;
    QString expectedMessege = "В корневом узле входного файла содержится переменная.\nПеременная не может быть корнем дерева разбора выражения";

    try
    {
        isCorrect = controller.isRootNodeCorrect(docElem);
        QVERIFY(!isCorrect);
    }
    catch (ErrorController::Error error)
    {
        QCOMPARE(error.errorType, expectedErrorType);
        QCOMPARE(error.errorMessege, expectedMessege);
    }
    //QVERIFY(isCorrect);
}

void Test_ErrorController_isRootNodeCorrect::correctNode()
{
    QString inputFileName = "../TestsIsRootNodeCorrect/correctNode.xml";
    QDomElement docElem = getRootNodeFromFile(inputFileName);

    bool isCorrect = false;
    ErrorController controller;

    try
    {
        isCorrect = controller.isRootNodeCorrect(docElem);
        QVERIFY(isCorrect);
    }
    catch (ErrorController::Error error)
    {
        bool noException = false;
        QVERIFY(noException);
    }
}
