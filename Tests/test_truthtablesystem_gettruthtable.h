#ifndef TEST_TRUTHTABLESYSTEM_GETTRUTHTABLE_H
#define TEST_TRUTHTABLESYSTEM_GETTRUTHTABLE_H
#include <QTest>
#include <QObject>
#include <QDomDocument>
#include "../TruthTableProject/truthtablesystem.h"

class Test_TruthTableSystem_getTruthTable : public QObject
{
    Q_OBJECT
public:
    Test_TruthTableSystem_getTruthTable();
    ~Test_TruthTableSystem_getTruthTable();

private:
    QDomNode getNodeFromFile(QString fileName);
    void compareNodeNameList(QStringList & actualNames, QStringList & expectedNames);

private slots:
    void oneUnaryOperation();
    void someOperationsWithIdenticalVariables();
    void oneBynaryOperationWithIdenticalVariables();
    void someOperationsWithDifferentVariables();
    void oneRepeatingOperation();
    void someRepeatingOperations();
};

#endif // TEST_TRUTHTABLESYSTEM_GETTRUTHTABLE_H
