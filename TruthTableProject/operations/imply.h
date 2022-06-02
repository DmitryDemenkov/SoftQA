#ifndef IMPLY_H
#define IMPLY_H
#include "../operation.h"

/*!
 * \file
 * \brief Файл, содержащий описание Imply
 */

/*!
 * \brief Класс, описывающий узел операции
 *                   импликация дерева разбора выражения
 */
class Imply : public Operation
{
public:
    Imply();
    ~Imply() override;

    /*!
     * \brief Вернуть результат операции импликация
     * \return Результат операции
     */
    int getValue() override;

#ifdef QT_DEBUG
    friend class Test_Imply_getValue;
#endif // friend test class
};

#endif // IMPLY_H
