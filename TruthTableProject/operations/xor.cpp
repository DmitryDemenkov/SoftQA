#include "xor.h"

/*!
 * \file
 * \brief Файл, содержащий реализацию Xor
 */

/*!
 * \brief Установить характеристики операции исключающее или
 */
Xor::Xor()
{
    operationPriority = 3;         /// Xor.operationPriority = 3
    operationSign = QChar(0x2295); /// Xor.operationSign = "⊕"
}

Xor::~Xor() { }

int Xor::getValue()
{
    Node* leftOperand = this->getLeftOperand();   // левый операнд выражения
    Node* rightOperand = this->getRightOperand(); // правый операед выражения

    if (leftOperand != NULL && rightOperand != NULL) // Если операнды определены
        return (!leftOperand->getValue() && rightOperand->getValue()) ||
                (leftOperand->getValue() && !rightOperand->getValue()); // вернуть результат исключающего или значений операндов
    else
        return 0;
}
