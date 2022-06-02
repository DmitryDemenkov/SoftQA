#include "eq.h"

/*!
 * \file
 * \brief Файл, содержащий реализацию Eq
 */

/*!
 * \brief Установить характеристики операции эквиваленция
 */
Eq::Eq()
{
    operationPriority = 1; /// Eq.operationPriority = 1
    operationSign = "<=>"; /// Eq.operationSign = "<=>"
}

Eq::~Eq() { }

int Eq::getValue()
{
    Node* leftOperand = this->getLeftOperand();   // левый операнд выражения
    Node* rightOperand = this->getRightOperand(); // правый операед выражения

    if (leftOperand != NULL && rightOperand != NULL) // Если операнды определены
        return (leftOperand->getValue() && rightOperand->getValue()) ||
                (!leftOperand->getValue() && !rightOperand->getValue()); // вернуть результат эквиваленции значений операндов
    else
        return 0;
}
