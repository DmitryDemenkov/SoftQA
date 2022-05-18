#ifndef TEST_OPERATION_SETOPERANDS_H
#define TEST_OPERATION_SETOPERANDS_H
#include <QTest>
#include <QObject>

class Test_Operation_setOperands : public QObject
{
    Q_OBJECT
public:
    Test_Operation_setOperands();
    ~Test_Operation_setOperands();

private slots:
    void variablesOfBinaryOperation();
    void variableOfUnaryOperation();
    void lowerPriorityOperationOfBinaryOperation();
    void highPriorityOperationOfBinaryOperation();
    void samePriorityOperationIsLeftOperand();
    void samePriorityOperationIsRightOperand();
    void operationOfUnaryOperation();
};

#endif // TEST_OPERATION_SETOPERANDS_H
