#ifndef TEST_TRUTHTABLESYSTEM_INSERTNODE_H
#define TEST_TRUTHTABLESYSTEM_INSERTNODE_H
#include <QTest>
#include <QObject>
#include "../TruthTableProject/truthtablesystem.h"

class Test_TruthTableSystem_insertNode : public QObject
{
    Q_OBJECT
public:
    Test_TruthTableSystem_insertNode();
    ~Test_TruthTableSystem_insertNode();

private:
    void compareNodeVectors(QVector<Node*> & actualVector, QVector<Node*> & expectedVector);

private slots:
    void insertVariableIntoMiddle();
    void insertVariableIntoBegin();
    void insertVariableIntoEnd();
    void insertOperationIntoVectorWithVariables();
    void insertOperationIntoVectorWithOperation();
    void insertOperationIntoVectorWithVariableAndOperation();
    void insertVariableIntoEmptyVector();
    void insertOperationIntoEmptyVector();
};

#endif // TEST_TRUTHTABLESYSTEM_INSERTNODE_H
