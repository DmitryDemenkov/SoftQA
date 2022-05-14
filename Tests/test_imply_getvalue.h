#ifndef TEST_IMPLY_GETVALUE_H
#define TEST_IMPLY_GETVALUE_H
#include <QTest>
#include <QObject>

class Test_Imply_getValue : public QObject
{
    Q_OBJECT
public:
    Test_Imply_getValue();
    ~Test_Imply_getValue();

private slots:
    void ImplicationZeroAndZero();
    void ImplicationZeroAndOne();
    void ImplicationOneAndZero();
    void ImplicationOneAndOne();
    void OperationInLeftOperand();
    void OperationInRightOperand();
    void OperationInBothOperands();
    void OperationInLeftOperandOfLeftOperand();
    void OperationInRightOperandOfLeftOperand();
    void OperationInLeftOperandOfRightOperand();
    void OperationInRightOperandOfRightOperand();

signals:

};

#endif // TEST_IMPLY_GETVALUE_H
