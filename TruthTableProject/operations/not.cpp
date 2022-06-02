#include "not.h"

/*!
 * \file
 * \brief Файл, содержащий реализацию Not
 */

/*!
 * \brief Установить характеристики операции инверсия
 */
Not::Not()
{
    operationPriority = 5; /// Not.operationPriority = 5
    operationSign = "!";   /// Not.operationSign = "!"
}

Not::~Not() { }

int Not::getValue()
{
    Node* operand = this->getLeftOperand(); // операнд выражения

    if (operand != NULL) // Если операнд определен
        return !operand->getValue(); // вернуть результат инверсии значения операнда
    else
        return 0;
}
