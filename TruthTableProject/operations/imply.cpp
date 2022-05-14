#include "imply.h"

Imply::Imply()
{
    operationPriority = 2;
    operationSign = "=>";
}

Imply::~Imply() { }

int Imply::getValue()
{
    Node* leftOperand = this->getLeftOperand();   // левый операнд выражения
    Node* rightOperand = this->getRightOperand(); // правый операед выражения

    if (leftOperand != NULL && rightOperand != NULL) // Если операнды определены
        return !leftOperand->getValue() || rightOperand->getValue(); // вернуть результат импликации значений операндов
    else
        return 0;
}
