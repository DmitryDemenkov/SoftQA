#ifndef TEST_ERRORCONTROLLER_ISVARIABLEROOTCORRECT_H
#define TEST_ERRORCONTROLLER_ISVARIABLEROOTCORRECT_H
#include <QTest>
#include <QDomNode>
#include <QObject>

class Test_ErrorController_isVariableCorrect : public QObject
{
    Q_OBJECT
public:
    Test_ErrorController_isVariableCorrect();
    ~Test_ErrorController_isVariableCorrect();

private:
    QDomNode getNodeFromFile(QString fileName);

private slots:
    void attributeInVariable();
    void childInVariable();
    void incorrectName();
    void longName();
    void correctNode();
};

#endif // TEST_ERRORCONTROLLER_ISVARIABLEROOTCORRECT_H
