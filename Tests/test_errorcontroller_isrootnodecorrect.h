#ifndef TEST_ERRORCONTROLLER_ISROOTNODECORRECT_H
#define TEST_ERRORCONTROLLER_ISROOTNODECORRECT_H
#include <QTest>
#include <QObject>
#include <QDomElement>

class Test_ErrorController_isRootNodeCorrect : public QObject
{
    Q_OBJECT
public:
    Test_ErrorController_isRootNodeCorrect();
    ~Test_ErrorController_isRootNodeCorrect();

private:
    QDomElement getRootNodeFromFile(QString fileName);

private slots:
    void tooManyChilds();
    void noChilds();
    void variableInRootNode();
    void correctNode();
};

#endif // TEST_ERRORCONTROLLER_ISROOTNODECORRECT_H
