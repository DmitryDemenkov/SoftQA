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

#ifdef QT_DEBUG
    friend class Test_Nor_getValue;
#endif // friend test classes
};

#endif // NOR_H
