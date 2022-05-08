#ifndef TEST_AND_GETVALUE_H
#define TEST_AND_GETVALUE_H
#include <QTest>
#include <QObject>

class Test_And_getValue : public QObject
{
    Q_OBJECT
public:
    Test_And_getValue();
    ~Test_And_getValue();

private slots:
    void ConjunctionZeroAndZero();
    void ConjunctionZeroAndOne();
    void ConjunctionOneAndZero();
    void ConjunctionOneAndOne();
    void OperationInLeftOperand();
    void OperationInRightOperand();
    void OperationInBothOperands();
    void OperationInLeftOperandOfLeftOperand();
    void OperationInRightOperandOfLeftOperand();
    void OperationInLeftOperandOfRightOperand();
    void OperationInRightOperandOfRightOperand();
};

#endif // TEST_AND_GETVALUE_H
