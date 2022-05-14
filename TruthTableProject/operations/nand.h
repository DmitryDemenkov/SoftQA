#ifndef NAND_H
#define NAND_H
#include "../operation.h"

/*!
 * \brief Класс, описывающий узел операции
 *                   штрих Шеффера дерева разбора выражения
 */
class Nand : public Operation
{
public:
    Nand();
    ~Nand() override;

    /*!
     * \brief Вернуть результат операции штрих Шеффера
     * \return результат операции
     */
    int getValue() override;
};

#endif // NAND_H
