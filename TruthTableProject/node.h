#ifndef NODE_H
#define NODE_H
#include <QCoreApplication>

class Node
{
public:
    Node();
    virtual ~Node() = 0;

    /*!
     * \brief getValue получить текущее значение узла
     * \return числовое значение узла
     */
    virtual int getValue() = 0;

     /*!
      * \brief getStringId получить текущее строковое представление узла
      * \return строковое представление узла
      */
     QString getStringId() const;

protected:
    QString strind_id; ///< строковое представление узла
};

#endif // NODE_H
