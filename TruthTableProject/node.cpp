#include "node.h"

/*!
 * \file
 * \brief Файл, содержащий реализацию Node
 */

Node::Node()
{
    string_id = "";
}

Node::~Node() { }

QString Node::getStringId() const
{
    // Вернуть строковое представление узла
    return string_id;
}
