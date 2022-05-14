#include "nand.h"

Nand::Nand()
{
    operationPriority = 0;
    operationSign = "|";
}

Nand::~Nand() { }

int Nand::getValue()
{
    Node* leftOperand = this->getLeftOperand();   // левый операнд выражения
    Node* rightOperand = this->getRightOperand(); // правый операед выражения

    if (leftOperand != NULL && rightOperand != NULL) // Если операнды определены
        return !(leftOperand->getValue() && rightOperand->getValue()); // вернуть результат штриха Шефферв значений операндов
    else
        return 0;
}
