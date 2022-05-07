#ifndef NODE_H
#define NODE_H
#include <QCoreApplication>

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
     * \return числовое значение узла
     */
    virtual int getValue() = 0;

     /*!
      * \brief Получить текущее строковое представление узла
      * \return строковое представление узла
      */
     QString getStringId() const;

protected:
    QString string_id; ///< Строковое представление узла
};

#endif // NODE_H
