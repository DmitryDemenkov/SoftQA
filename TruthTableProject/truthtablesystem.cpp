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
    Node* result;
    if (xNode.toElement().tagName() == "variable") // если xml узел соответствует узлу переменной
    {
        // Создать новый узел переменной, со строковым представлением равным имени переменной
        errorController.isVariableCorrect(xNode);
        Variable* variable = new Variable();
        variable->setStringId(xNode.toElement().text().trimmed());
        result = variable;
    }
    else
    {
        // Создать операцию типа, содержащегося в атрибуте type xml узла
        errorController.isOperationCorrect(xNode);
        Operation* operation = Operation::getOperation(xNode.toElement().attributeNode("type").value());

        QDomNodeList children = xNode.childNodes();
        Node* childNodes[2] = {NULL, NULL};
        for (int i = 0; i < children.length(); i++) // для всех дочерних узлов xml узла
        {
            // Преобразовать дочерний узел xml узла в объект класса Node
            QDomNode child = children.item(i);
            childNodes[i] = parseExpression(child);
        }

        operation->setOperands(childNodes[0], childNodes[1]); // задать дочернии узлы операндами данной операции
        result = operation;
    }

    Node* desiredNode = findNode(result); // найти созданный узел в векторе
    if (desiredNode != NULL) // если узел найден
    {
        // Вернуть указатель на найденный узел
        delete result;
        return desiredNode;
    }
    else
    {
        // Добавить созданный узел в вектор
        variablesAmount += insertNode(result); // если была добавлена переменная, инкрементировать кол-во переменных
        return result; // вернуть указатель на созданный узел
    }
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
