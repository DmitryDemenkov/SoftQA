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

#ifdef QT_DEBUG
    friend class Test_Not_getValue;
    friend class Test_And_getValue;
    friend class Test_Or_getValue;
    friend class Test_Xor_getValue;
    friend class Test_Imply_getValue;
    friend class Test_Eq_getValue;
    friend class Test_Nand_getValue;
    friend class Test_Nor_getValue;
#endif // friend test classes
};

#endif // OPERATION_H
