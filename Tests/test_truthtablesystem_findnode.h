#ifndef TEST_TRUTHTABLESYSTEM_FINDNODE_H
#define TEST_TRUTHTABLESYSTEM_FINDNODE_H
#include <QTest>
#include <QObject>

class Test_TruthTableSystem_findNode : public QObject
{
    Q_OBJECT
public:
    Test_TruthTableSystem_findNode();
    ~Test_TruthTableSystem_findNode();

private slots:
    void noNodeInVector();
    void nodeAtBeginOfVector();
    void nodeInMiddleOfVector();
    void nodeInEndOfVector();
};

#endif // TEST_TRUTHTABLESYSTEM_FINDNODE_H
