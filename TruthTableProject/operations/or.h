#ifndef OR_H
#define OR_H
#include "../operation.h"

/*!
 * \file
 * \brief Файл, содержащий описание Or
 */

/*!
 * \brief Класс, описывающий узел операции
 *                   дизъюнкция дерева разбора выражения
 */
class Or : public Operation
{
public:
    Or();
    ~Or() override;

    /*!
     * \brief Вернуть результат операции дизъюнкция
     * \return Результат операции
     */
    int getValue() override;

#ifdef QT_DEBUG
    friend class Test_Or_getValue;
#endif // friend test classes
};

#endif // OR_H
