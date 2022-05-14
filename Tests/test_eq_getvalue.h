#ifndef TEST_EQ_GETVALUE_H
#define TEST_EQ_GETVALUE_H
#include <QTest>
#include <QObject>

class Test_Eq_getValue : public QObject
{
    Q_OBJECT
public:
    Test_Eq_getValue();
    ~Test_Eq_getValue();

private slots:
    void EquivalentZeroAndZero();
    void EquivalentZeroAndOne();
    void EquivalentOneAndZero();
    void EquivalentOneAndOne();
    void OperationInLeftOperand();
    void OperationInRightOperand();
    void OperationInBothOperands();
    void OperationInLeftOperandOfLeftOperand();
    void OperationInRightOperandOfLeftOperand();
    void OperationInLeftOperandOfRightOperand();
    void OperationInRightOperandOfRightOperand();
};

#endif // TEST_EQ_GETVALUE_H
