#ifndef NAND_H
#define NAND_H
#include "../operation.h"

/*!
 * \file
 * \brief Файл, содержащий описание Nand
 */

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
     * \return Результат операции
     */
    int getValue() override;

#ifdef QT_DEBUG
    friend class Test_Nand_getValue;
#endif // friend test classes
};

#endif // NAND_H
