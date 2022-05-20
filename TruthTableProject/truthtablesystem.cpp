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
    Node* desiredNode = NULL; // считать узел ненайденным

    for (int i = 0; i < nodes.length() && desiredNode == NULL; i++) // для каждого элемента вектора
        if (nodes[i]->getStringId() == node->getStringId()) // если строковое представление текущего элемента равен искомому
            desiredNode = nodes[i]; // считать текущий элемент искомым

    return desiredNode;
}

int TruthTableSystem::insertNode(Node *node)
{
    int isVariable = 0; // считать заданный узел операцией
    if (dynamic_cast<Variable*>(node)) // если заданный узел - переменная
    {
        int index = 0;

        // Найти позицию первого узла не являющегося переменной
        while (index < nodes.length() && dynamic_cast<Variable*>(nodes[index]))
            index++;

        // Вставить узел на найденную позицию
        nodes.insert(index, node);
        isVariable = 1; // считать заданный узел переменной
    }
    else
    {
        // Добавить узел в конец вектора
        nodes.append(node);
    }
    return isVariable;
}

void TruthTableSystem::makeTruthTable()
{
    return ;
}
