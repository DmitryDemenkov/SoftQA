#ifndef TEST_XOR_GETVALUE_H
#define TEST_XOR_GETVALUE_H
#include <QTest>
#include <QObject>

class Test_Xor_getValue : public QObject
{
    Q_OBJECT
public:
    Test_Xor_getValue();
    ~Test_Xor_getValue();

private slots:
    void XORZeroAndZero();
    void XORZeroAndOne();
    void XOROneAndZero();
    void XOROneAndOne();
    void OperationInLeftOperand();
    void OperationInRightOperand();
    void OperationInBothOperands();
    void OperationInLeftOperandOfLeftOperand();
    void OperationInRightOperandOfLeftOperand();
    void OperationInLeftOperandOfRightOperand();
    void OperationInRightOperandOfRightOperand();

};

#endif // TEST_XOR_GETVALUE_H
