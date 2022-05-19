#include "test_errorcontroller_isvariablecorrect.h"
#include "../TruthTableProject/errorcontroller.h"

Test_ErrorController_isVariableCorrect::Test_ErrorController_isVariableCorrect() { }

Test_ErrorController_isVariableCorrect::~Test_ErrorController_isVariableCorrect() { }

QDomNode Test_ErrorController_isVariableCorrect::getNodeFromFile(QString fileName)
{
    QDomDocument doc(fileName);
    QFile inputFile(fileName);

    inputFile.open(QIODevice::ReadOnly);
    doc.setContent(&inputFile);
    inputFile.close();
    QDomElement docElem = doc.documentElement();

    return docElem.firstChild();
}

void Test_ErrorController_isVariableCorrect::attributeInVariable()
{
    QString inputFileName = "../TestsIsVariableCorrect/attributeInVariable.xml";
    QDomNode docNode = getNodeFromFile(inputFileName);

    bool isCorrect = false;
    ErrorController controller;

    ErrorController::ErrorType expectedErrorType = ErrorController::ATTRIBUTE_IN_VARIABLE;
    QString expectedMessege = "Узел переменной «A» содержит ненужные атрибуты.\nУзел переменной не должен содержать атрибутов";

    try
    {
        isCorrect = controller.isVariableCorrect(docNode);
        QVERIFY(!isCorrect);
    }
    catch (ErrorController::Error error)
    {
        QCOMPARE(error.errorType, expectedErrorType);
        QCOMPARE(error.errorMessege, expectedMessege);
    }
}

void Test_ErrorController_isVariableCorrect::childInVariable()
{
    QString inputFileName = "../TestsIsVariableCorrect/childInVariable.xml";
    QDomNode docNode = getNodeFromFile(inputFileName);

    bool isCorrect = false;
    ErrorController controller;

    ErrorController::ErrorType expectedErrorType = ErrorController::CHILDREN_IN_VARIABLE;
    QString expectedMessege = "Узел переменной «A» содержит дочерние узлы.\n Узел переменной не должен содержать дочерних узлов";

    try
    {
        isCorrect = controller.isVariableCorrect(docNode);
        QVERIFY(!isCorrect);
    }
    catch (ErrorController::Error error)
    {
        QCOMPARE(error.errorType, expectedErrorType);
        QCOMPARE(error.errorMessege, expectedMessege);
    }
}


void Test_ErrorController_isVariableCorrect::incorrectName()
{
    QString inputFileName = "../TestsIsVariableCorrect/incorrectName.xml";
    QDomNode docNode = getNodeFromFile(inputFileName);

    bool isCorrect = false;
    ErrorController controller;

    ErrorController::ErrorType expectedErrorType = ErrorController::INCORRECT_VARIABLE_NAME;
    QString expectedMessege = "Некорректное имя переменной «1A$x».\nИмя переменной может содержать только буквы латинского алфавита, цифры и символ «_» и не может начинаться с цифр";

    try
    {
        isCorrect = controller.isVariableCorrect(docNode);
        QVERIFY(!isCorrect);
    }
    catch (ErrorController::Error error)
    {
        QCOMPARE(error.errorType, expectedErrorType);
        QCOMPARE(error.errorMessege, expectedMessege);
    }
}

void Test_ErrorController_isVariableCorrect::longName()
{
    QString inputFileName = "../TestsIsVariableCorrect/longName.xml";
    QDomNode docNode = getNodeFromFile(inputFileName);

    bool isCorrect = false;
    ErrorController controller;

    ErrorController::ErrorType expectedErrorType = ErrorController::TOO_LONG_VARIABLE_NAME;
    QString expectedMessege = "Слишком длинное имя переменной «Qazxswedcvfrtgbnhyju1573».\nИмя переменной должно содержать не более 20 символов";

    try
    {
        isCorrect = controller.isVariableCorrect(docNode);
        QVERIFY(!isCorrect);
    }
    catch (ErrorController::Error error)
    {
        QCOMPARE(error.errorType, expectedErrorType);
        QCOMPARE(error.errorMessege, expectedMessege);
    }
}

void Test_ErrorController_isVariableCorrect::correctNode()
{
    QString inputFileName = "../TestsIsVariableCorrect/correctNode.xml";
    QDomNode docNode = getNodeFromFile(inputFileName);

    bool isCorrect = false;
    ErrorController controller;

    try
    {
        isCorrect = controller.isVariableCorrect(docNode);
        QVERIFY(isCorrect);
    }
    catch (ErrorController::Error error)
    {
        bool noException = false;
        QVERIFY(noException);
    }
}
