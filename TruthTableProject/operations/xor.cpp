#include "xor.h"

Xor::Xor()
{
    operationPriority = 3;
    operationSign = QChar(0x2295);
}

Xor::~Xor() { }

int Xor::getValue()
{
    Node* leftOperand = this->getLeftOperand();   // левый операнд выражения
    Node* rightOperand = this->getRightOperand(); // правый операед выражения

    if (leftOperand != NULL && rightOperand != NULL) // Если операнды определены
        return (!getLeftOperand()->getValue() && getRightOperand()->getValue()) ||
                (getLeftOperand()->getValue() && !getRightOperand()->getValue()); // вернуть результат исключающего или значений операндов
    else
        return 0;
}
