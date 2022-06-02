#include "and.h"

/*!
 * \file
 * \brief Файл, содержащий реализацию And
 */

/*!
 * \brief Установить характеристики операции конъюнкция
 */
And::And()
{
    operationPriority = 4; /// And.operationPriority = 4
    operationSign = "&";   /// And.operationSign = "&"
}

And::~And() { }

int And::getValue()
{
    Node* leftOperand = this->getLeftOperand();   // левый операнд выражения
    Node* rightOperand = this->getRightOperand(); // правый операнд выражения

    if (leftOperand != NULL && rightOperand != NULL) // Если операнды выражения определены
        return leftOperand->getValue() && rightOperand->getValue(); // вернуть результат конъюнкции значений операндов
    else
        return 0;
}
