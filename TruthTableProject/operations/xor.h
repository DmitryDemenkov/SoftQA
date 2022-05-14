#ifndef XOR_H
#define XOR_H
#include "../operation.h"

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
     * \return результат операции
     */
    int getValue() override;
};

#endif // XOR_H
