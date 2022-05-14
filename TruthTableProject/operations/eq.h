#ifndef EQ_H
#define EQ_H
#include "../operation.h"

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
     * \return результат операции
     */
    int getValue() override;
};

#endif // EQ_H