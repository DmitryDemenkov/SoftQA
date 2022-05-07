#ifndef AND_H
#define AND_H
#include "operation.h"

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
     * \return результат операции
     */
    int getValue() override;
};

#endif // AND_H
