#include "nor.h"

Nor::Nor()
{
    operationPriority = 0;
    operationSign = QChar(0x2193);
}

Nor::~Nor() { }

int Nor::getValue()
{
    Node* leftOperand = this->getLeftOperand();   // левый операнд выражения
    Node* rightOperand = this->getRightOperand(); // правый операед выражения

    if (leftOperand != NULL && rightOperand != NULL) // Если операнды определены
        return !(leftOperand->getValue() || rightOperand->getValue()); // вернуть результат стрелки Пирса значений операндов
    else
        return 0;
}
