#include "or.h"

Or::Or()
{
    operationPriority = 3;
    operationSign = "||";
}

Or::~Or() { }

int Or::getValue()
{
    Node* leftOperand = this->getLeftOperand();   // левый операнд выражения
    Node* rightOperand = this->getRightOperand(); // правый операед выражения

    if (leftOperand != NULL && rightOperand != NULL) // Если операнды определены
        return leftOperand->getValue() || rightOperand->getValue(); // вернуть результат дизъюнкции значений операндов
    else
        return 0;
}
