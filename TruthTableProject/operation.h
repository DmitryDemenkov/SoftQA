#ifndef OPERATION_H
#define OPERATION_H
#include "node.h"

/*!
 * \brief Класс, описывающий абстрактный узел
 *                 операции логического выражения
 */
class Operation : public Node
{
public:
    Operation();
    virtual ~Operation();

    /*!
     * \brief Получить левый операнд операции
     * \return левый операнд
     */
    Node* getLeftOperand() const;

    /*!
     * \brief Получить правый операнд операции
     * \return правый операнд
     */
    Node* getRightOperand() const;

protected:
    int operationPriority;  ///< Приоритет операции
    QString operationSign;  ///< Знак операции


private:
    Node* leftOperand;     ///< Левый операнд операции
    Node* rightOperand;    ///< Правый операнд операции
};

#endif // OPERATION_H
