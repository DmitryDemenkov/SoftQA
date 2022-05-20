#include "truthtablesystem.h"

TruthTableSystem::TruthTableSystem()
{
    variablesAmount = 0;
}

TruthTableSystem::~TruthTableSystem()
{
    for (int i = 0; i < nodes.length(); i++)
        delete nodes[i];
}

void TruthTableSystem::setXRootNode(QDomNode xNode)
{
    this->xRootNode = xNode;
}

QStringList TruthTableSystem::getTruthTable(QVector<QVector<int>> &values)
{
    return QStringList();
}

Node* TruthTableSystem::parseExpression(QDomNode &xNode)
{
    return NULL;
}

Node* TruthTableSystem::findNode(Node *node)
{
    return NULL;
}

int TruthTableSystem::insertNode(Node *node)
{
    return 0;
}

void TruthTableSystem::makeTruthTable()
{
    return ;
}
