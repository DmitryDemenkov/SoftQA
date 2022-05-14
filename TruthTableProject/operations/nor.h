#ifndef NOR_H
#define NOR_H
#include "../operation.h"

/*!
 * \brief Класс, описывающий узел операции
 *                   стрелка Пирса дерева разбора выражения
 */
class Nor : public Operation
{
public:
    Nor();
    ~Nor() override;

    /*!
     * \brief Вернуть результат операции стрелка Пирса
     * \return результат операции
     */
    int getValue() override;

};

#endif // NOR_H
