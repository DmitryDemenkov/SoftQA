#ifndef TEST_NAND_GETVALUE_H
#define TEST_NAND_GETVALUE_H
#include <QTest>
#include <QObject>

class Test_Nand_getValue : public QObject
{
    Q_OBJECT
public:
    Test_Nand_getValue();
    ~Test_Nand_getValue();

private slots:
    void NANDZeroAndZero();
    void NANDZeroAndOne();
    void NANDOneAndZero();
    void NANDOneAndOne();
    void OperationInLeftOperand();
    void OperationInRightOperand();
    void OperationInBothOperands();
    void OperationInLeftOperandOfLeftOperand();
    void OperationInRightOperandOfLeftOperand();
    void OperationInLeftOperandOfRightOperand();
    void OperationInRightOperandOfRightOperand();

};

#endif // TEST_NAND_GETVALUE_H
