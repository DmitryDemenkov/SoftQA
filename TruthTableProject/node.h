#ifndef NODE_H
#define NODE_H
#include <QCoreApplication>

/*!
 * \file
 * \brief Файл, содержащий описание Node
 */

/*!
 * \brief Класс, описывающий абстрактный узел
 *                          дерева разбора выражения
 */
class Node
{
public:
    Node();
    virtual ~Node() = 0;

    /*!
     * \brief Получить текущее значение узла
     * \return Числовое значение узла
     */
    virtual int getValue() = 0;

     /*!
      * \brief Получить текущее строковое представление узла
      * \return Строковое представление узла
      */
     QString getStringId() const;

protected:
    QString string_id; ///< Строковое представление узла

#ifdef QT_DEBUG
    friend class Test_Operation_setOperands;
#endif // friend test classes
};

#endif // NODE_H
