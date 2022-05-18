#ifndef TEST_OPERATION_GETOPERATION_H
#define TEST_OPERATION_GETOPERATION_H
#include <QTest>
#include <QObject>

class Test_Operation_getOperation : public QObject
{
    Q_OBJECT
public:
    Test_Operation_getOperation();
    ~Test_Operation_getOperation();

private slots:
    void operationInversion();
    void operationConjuction();
    void operationDisjunction();
    void operationXOR();
    void operationImplication();
    void operationEquivalent();
    void operationNand();
    void operationNor();
    void incorrectOperationName();
};

#endif // TEST_OPERATION_GETOPERATION_H
