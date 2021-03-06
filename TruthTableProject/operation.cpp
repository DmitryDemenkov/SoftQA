#include "operation.h"
#include "operations/not.h"
#include "operations/and.h"
#include "operations/or.h"
#include "operations/xor.h"
#include "operations/imply.h"
#include "operations/eq.h"
#include "operations/nand.h"
#include "operations/nor.h"

/*!
 * \file
 * \brief Файл, содержащий реализацию Operation
 */

Operation::Operation()
{
    leftOperand = NULL;
    rightOperand = NULL;
}

Operation::~Operation() { }

Node* Operation::getLeftOperand() const
{
    //Вернуть левый операнд
    return leftOperand;
}

Node* Operation::getRightOperand() const
{
    //Вернуть правый операнд
    return rightOperand;
}

int Operation::getOperationPriority() const
{
    // Вернуть приоритет операции
    return operationPriority;
}

void Operation::setOperands(Node* leftOperand, Node* rightOperand)
{
    // Установить переданные операнды операции
    this->leftOperand = leftOperand;
    this->rightOperand = rightOperand;

    // Составить строковое представление узла операции
    Node* operands[2] = { leftOperand, rightOperand };
    QString operandStrings[2] = { "", "" };
    for (int i = 0; i < 2; i++)
        if (operands[i] != NULL)
        {
            operandStrings[i] = operands[i]->getStringId();
            Operation* operand = dynamic_cast<Operation*>(operands[i]);

            if (operand != NULL &&                                                        // если операнд является операцией и
                ((i == 0 && operand->getOperationPriority() < this->operationPriority) || // (приоритет левого операнда меньше или
                (i == 1 && operand->getOperationPriority() <= this->operationPriority)))  // приоритет правой операции меньше либо равен)
            {
                operandStrings[i].insert(0, '(').append(')');  // добавить скобки к строковому представоению операнда
            }
        }

    // Установить строковое представление узла операции
    if (dynamic_cast<Not*>(this))
        string_id = operationSign + operandStrings[0];
    else
        string_id = operandStrings[0] + operationSign + operandStrings[1];
}

Operation* Operation::getOperation(QString name)
{
    if (name == "not")
        return new Not();

    else if (name == "and")
        return new And();

    else if (name == "or")
        return new Or();

    else if (name == "xor")
        return new Xor();

    else if (name == "imply")
        return new Imply();

    else if (name == "eq")
        return new Eq();

    else if (name == "nand")
        return new Nand();

    else if (name == "nor")
        return new Nor();

    else
        return NULL;
}
