#ifndef TEST_OR_GETVALUE_H
#define TEST_OR_GETVALUE_H
#include <QTest>
#include <QObject>

class Test_Or_getValue : public QObject
{
    Q_OBJECT
public:
    Test_Or_getValue();
    ~Test_Or_getValue();

private slots:
    void DisjunctionZeroAndZero();
    void DisjunctionZeroAndOne();
    void DisjunctionOneAndZero();
    void DisjunctionOneAndOne();
    void OperationInLeftOperand();
    void OperationInRightOperand();
    void OperationInBothOperands();
    void OperationInLeftOperandOfLeftOperand();
    void OperationInRightOperandOfLeftOperand();
    void OperationInLeftOperandOfRightOperand();
    void OperationInRightOperandOfRightOperand();

};

#endif // TEST_OR_GETVALUE_H
