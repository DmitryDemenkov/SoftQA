#ifndef TEST_TRUTHTABLESYSTEM_PARSEEXPRESSION_H
#define TEST_TRUTHTABLESYSTEM_PARSEEXPRESSION_H
#include <QTest>
#include <QObject>
#include <QDomDocument>
#include "../TruthTableProject/truthtablesystem.h"

class Test_TruthTableSystem_parseExpression : public QObject
{
    Q_OBJECT
public:
    Test_TruthTableSystem_parseExpression();
    ~Test_TruthTableSystem_parseExpression();

private:
    QDomNode getNodeFromFile(QString fileName);
    void compareNodeVectors(QVector<Node*> & actualVector, QStringList & expectedVector);

private slots:
    void variableNode();
    void unaryOperationNode();
    void nestedUnaryOperation();
    void bynaryOperationWithIdenticalVariables();
    void conjunctionNode();
    void disjunctionNode();
    void XORNode();
    void implicationaNode();
    void equivalentNode();
    void NANDNode();
    void NORNode();
    void operationIsLeftOperand();
    void operationIsRightOperand();
    void operationIsLeftOperandOfLeftOperand();
    void operationIsRightOperandOfLeftOperand();
    void operationIsLeftOperandOfRightOperand();
    void operationIsRightOperandOfRightOperand();
    void bynaryOperationIsOperandOfUnaryOne();
    void unaryOperationIsLeftOperandOfBynaryOne();
    void unaryOperationIsRightOperandOfBynaryOne();

};

#endif // TEST_TRUTHTABLESYSTEM_PARSEEXPRESSION_H
