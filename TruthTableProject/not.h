#ifndef NOT_H
#define NOT_H
#include "operation.h"

/*!
 * \brief Класс, описывающий узел операции
 *                     инверсия дерева разбора выражения
 */
class Not : public Operation
{
public:
    Not();
    ~Not() override;

    /*!
     * \brief Вернуть результат операции инверсия
     * \return результат операции
     */
    int getValue() override;
};

#endif // NOT_H
