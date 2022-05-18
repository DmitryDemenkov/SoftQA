#include "operation.h"
#include "operations/not.h"

Operation::Operation()
{
    leftOperand = NULL;
    rightOperand = NULL;
}

Operation::~Operation() { }

Node* Operation::getLeftOperand() const
{
    //Вернуть левый операнд
    return leftOperand;
}

Node* Operation::getRightOperand() const
{
    //Вернуть правый операнд
    return rightOperand;
}

int Operation::getOperationPriority() const
{
    return 0;
}

void Operation::setOperands(Node* leftOperand, Node* rightOperand)
{
    return;
}
