#ifndef VARIABLE_H
#define VARIABLE_H
#include "node.h"

/*!
 * \file
 * \brief Файл, содержащий описание Variable
 */

/*!
 * \brief Класс, описывающий узел переменной
 *                       дерева разбора выражения
 */
class Variable : public Node
{
public:
    Variable();
    ~Variable() override;

    /*!
     * \brief Задать новое строковое представление переменной
     * \param[in] name - новое строковое представление переменной
     */
    void setStringId(QString name);

    /*!
     * \brief Задать значение переменной
     * \param[in] value - новое значение переменной
     */
    void setValue(int value);

    /*!
     * \brief Получить текущее значение переменной
     * \return Значение переменной
     */
    int getValue() override;

private:
    int value; ///< Числовое значение переменной
};

#endif // VARIABLE_H
