#ifndef OR_H
#define OR_H
#include "../operation.h"

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
     * \return результат операции
     */
    int getValue() override;
};

#endif // OR_H
