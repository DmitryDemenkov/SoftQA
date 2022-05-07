#include "operation.h"

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
