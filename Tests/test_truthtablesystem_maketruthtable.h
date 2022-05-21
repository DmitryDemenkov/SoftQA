#ifndef TEST_TRUTHTABLESYSTEM_MAKETRUTHTABLE_H
#define TEST_TRUTHTABLESYSTEM_MAKETRUTHTABLE_H
#include <QTest>
#include <QObject>
#include "../TruthTableProject/truthtablesystem.h"

class Test_TruthTableSystem_makeTruthTable : public QObject
{
    Q_OBJECT
public:
    Test_TruthTableSystem_makeTruthTable();
    ~Test_TruthTableSystem_makeTruthTable();

private:
    void compareMatrix(QVector<QVector<int>> &actualMatrix, QVector<QVector<int>> &expectedMatrix);

private slots:
    void oneVariableOneOperation();
    void oneVariableTwoOperations();
    void twoVariablesOneOperation();
    void twoVariablesTwoOperations();
    void someVariablesSomeOperations();
};

#endif // TEST_TRUTHTABLESYSTEM_MAKETRUTHTABLE_H
