#include <QRegExp>
#include "errorcontroller.h"

ErrorController::ErrorController() { }

bool ErrorController::isRootNodeCorrect(QDomElement xRootNode)
{
    QDomNodeList children = xRootNode.childNodes();

    if (children.length() < 1) // если дочерние узлы отсутствуют
        throwError(NO_CHILD_NODES_IN_ROOT);

    else if (children.length() > 1) // если дочерних узлов слишком много
        throwError(TOO_MANY_CHILD_NODES_IN_ROOT);

    else if (children.item(0).toElement().tagName() == "variable") // если дочерний узел - переменная
        throwError(VARIABLE_IN_ROOT);

    return true;
}

bool ErrorController::isVariableCorrect(QDomNode xNode)
{
    QRegExp rx("^[a-zA-Z0-9_]+$");
    QDomNodeList children = xNode.childNodes();
    QDomNamedNodeMap attributes = xNode.attributes();
    QString variableName = xNode.toElement().text().trimmed();

    if (variableName.isEmpty())  // если имя переменной отсутствует
        throwError(INCORRECT_VARIABLE_NAME, &variableName);

    else if (variableName.length() > 20) // если имя переменной слищком длинное
        throwError(TOO_LONG_VARIABLE_NAME, &variableName);

    else if (!rx.exactMatch(variableName) || variableName[0].isNumber()) // если имя переменное содержит некорректные символы
        throwError(INCORRECT_VARIABLE_NAME, &variableName);

    else if (children.length() > 1 || children.item(0).nodeType() != QDomNode::TextNode) // если узел содержит дочерние узлы
        throwError(CHILDREN_IN_VARIABLE, &variableName);

    else if (attributes.length() > 0) // если узел содержит аттрибуты
        throwError(ATTRIBUTE_IN_VARIABLE, &variableName);

    return true;
}

bool ErrorController::isOperationCorrect(QDomNode &xNode)
{
    QStringList operationTypes = {"not", "and", "or", "xor", "imply", "eq", "nand", "nor"};
    QDomNodeList children = xNode.childNodes();
    QDomNamedNodeMap attributes = xNode.attributes();
    QString tagName = xNode.toElement().tagName();

    if (tagName != "operation") // если имя узла некорректно
        throwError(INCORRECT_NODE_NAME, &tagName);

    else if (attributes.length() < 1) // если узел не содержит аттрибутов
        throwError(NO_ATTRIBUTES_IN_OPERATION);

    else if (attributes.length() > 1) // если узел содержит лишние аттрибуты
        throwError(TOO_MANY_ATTRIBUTES_IN_OPERATION);

    QString attributeTag = attributes.item(0).toAttr().name();
    QString attributeValue = attributes.item(0).toAttr().value();

    if (attributeTag != "type") // если аттрибут имеет некорректное имя
        throwError(INCORRECT_ATTRIBUTE_IN_OPERATION, &attributeTag);

    else if (!operationTypes.contains(attributeValue)) // если тип операции некорректнет
        throwError(INCORRECT_TYPE_OF_OPERATION, &attributeValue);

    if (children.length() < 1 || (attributeValue != "not" && children.length() < 2)) // если отсутствуют дочерние узлы
        throwError(NO_CHILDREN_IN_OPERATION, &attributeValue);

    else if (children.length() > 2 || (attributeValue == "not" && children.length() > 1)) // если дочерних узлов слищкои много
        throwError(TOO_MANY_CHILDREN_IN_OPERATION, &attributeValue);

    return true;
}

void ErrorController::throwError(ErrorType errorType, QString *additionMsg)
{
    Error error;
    error.errorType = errorType;
    error.errorMessege = errorMessages[(int)errorType];

    if (additionMsg != NULL)
        error.errorMessege = error.errorMessege.arg(*additionMsg);

    throw error;
}
