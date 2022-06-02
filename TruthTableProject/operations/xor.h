#ifndef XOR_H
#define XOR_H
#include "../operation.h"

/*!
 * \file
 * \brief Файл, содержащий описание Xor
 */

/*!
 * \brief Класс, описывающий узел операции
 *                   исключающее или дерева разбора выражения
 */
class Xor : public Operation
{
public:
    Xor();
    ~Xor() override;

    /*!
     * \brief Вернуть результат операции исключающее или
     * \return Результат операции
     */
    int getValue() override;

#ifdef QT_DEBUG
    friend class Test_Xor_getValue;
#endif // friend test classes
};

#endif // XOR_H
