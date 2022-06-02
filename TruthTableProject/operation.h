#ifndef OPERATION_H
#define OPERATION_H
#include "node.h"

/*!
 * \file
 * \brief Файл, содержащий описание Operation
 */

/*!
 * \brief Класс, описывающий абстрактный узел
 *                 операции логического выражения
 */
class Operation : public Node
{
public:
    Operation();
    virtual ~Operation()=0;

    /*!
     * \brief Получить левый операнд операции
     * \return Левый операнд
     */
    Node* getLeftOperand() const;

    /*!
     * \brief Получить правый операнд операции
     * \return Правый операнд
     */
    Node* getRightOperand() const;

    /*!
     * \brief Получить приоритет операции
     * \return Приоритет операции
     */
    int getOperationPriority() const;

    /*!
     * \brief Задать операнды операции
     * \param[in] leftOperand - левый операнд
     * \param[in] rightOperand - правый операнд
     */
    void setOperands(Node* leftOperand, Node* rightOperand = NULL);

    /*!
     * \brief Создать операцию заданного типа
     * \param[in] name - название типа операции
     * \return Операция заданного типа
     */
    static Operation* getOperation(QString name);

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
