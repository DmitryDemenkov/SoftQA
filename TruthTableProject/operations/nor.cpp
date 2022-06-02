#include "nor.h"

/*!
 * \file
 * \brief Файл, содержащий реализацию Nor
 */

/*!
 * \brief Установить характеристики операции стредка Пирса
 */
Nor::Nor()
{
    operationPriority = 0;          /// Nor.operationPriority = 0
    operationSign = QChar(0x2193);  /// Nor.operationSign = "↓"
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
