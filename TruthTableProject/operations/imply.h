#ifndef IMPLY_H
#define IMPLY_H
#include "../operation.h"

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
     * \return результат операции
     */
    int getValue() override;
};

#endif // IMPLY_H
