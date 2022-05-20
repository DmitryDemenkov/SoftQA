#ifndef TEST_ERRORCONTROLLER_ISOPERATIONCORRECT_H
#define TEST_ERRORCONTROLLER_ISOPERATIONCORRECT_H
#include <QTest>
#include <QObject>
#include <QDomDocument>

class Test_ErrorController_isOperationCorrect : public QObject
{
    Q_OBJECT
public:
    Test_ErrorController_isOperationCorrect();
    ~Test_ErrorController_isOperationCorrect();

private:
    QDomNode getNodeFromFile(QString fileName);

private slots:
    void incorrectNodeName();
    void noNecessaryAttributes();
    void incorrectAttributeTag();
    void tooManyAttributes();
    void noChildNodes();
    void tooManyChildNodes();
    void incorrectAttributeValue();
    void correctNode();

};

#endif // TEST_ERRORCONTROLLER_ISOPERATIONCORRECT_H
