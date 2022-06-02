#ifndef EQ_H
#define EQ_H
#include "../operation.h"

/*!
 * \file
 * \brief Файл, содержащий описание Eq
 */

/*!
 * \brief Класс, описывающий узел операции
 *                   эквиваленция дерева разбора выражения
 */
class Eq : public Operation
{
public:
    Eq();
    ~Eq() override;

    /*!
     * \brief Вернуть результат операции эквиваленция
     * \return Результат операции
     */
    int getValue() override;

#ifdef QT_DEBUG
    friend class Test_Eq_getValue;
#endif // friend test classes
};

#endif // EQ_H
