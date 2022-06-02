#include "nand.h"

/*!
 * \file
 * \brief Файл, содержащий реализацию Nand
 */

/*!
 * \brief Установить характеристики операции щтрих Шеффера
 */
Nand::Nand()
{
    operationPriority = 0; /// Nand.operationPriority = 0
    operationSign = "|";   /// Nand.operationSign = "|"
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
