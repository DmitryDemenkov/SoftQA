#ifndef AND_H
#define AND_H
#include "../operation.h"

/*!
 * \file
 * \brief Файл, содержащий описание And
 */

/*!
 * \brief Класс, описывающий узел операции
 *                   конъюнкция дерева разбора выражения
 */
class And : public Operation
{
public:
    And();
    ~And() override;

    /*!
     * \brief Вернуть результат операции конъюнкция
     * \return Результат операции
     */
    int getValue() override;

#ifdef QT_DEBUG
    friend class Test_And_getValue;
#endif // friend test classes
};

#endif // AND_H
