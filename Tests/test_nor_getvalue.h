#ifndef TEST_NOR_GETVALUE_H
#define TEST_NOR_GETVALUE_H
#include <QTest>
#include <QObject>

class Test_Nor_getValue : public QObject
{
    Q_OBJECT
public:
    Test_Nor_getValue();
    ~Test_Nor_getValue();

private slots:
    void NORZeroAndZero();
    void NORZeroAndOne();
    void NOROneAndZero();
    void NOROneAndOne();
    void OperationInLeftOperand();
    void OperationInRightOperand();
    void OperationInBothOperands();
    void OperationInLeftOperandOfLeftOperand();
    void OperationInRightOperandOfLeftOperand();
    void OperationInLeftOperandOfRightOperand();
    void OperationInRightOperandOfRightOperand();
};

#endif // TEST_NOR_GETVALUE_H
