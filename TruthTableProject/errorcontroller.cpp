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

    if (variableName.isEmpty())
        throwError(INCORRECT_VARIABLE_NAME, &variableName);

    else if (variableName.length() > 20)
        throwError(TOO_LONG_VARIABLE_NAME, &variableName);

    else if (!rx.exactMatch(variableName) || variableName[0].isNumber())
        throwError(INCORRECT_VARIABLE_NAME, &variableName);

    else if (children.length() > 1 || children.item(0).nodeType() != QDomNode::TextNode)
        throwError(CHILDREN_IN_VARIABLE, &variableName);

    else if (attributes.length() > 0)
        throwError(ATTRIBUTE_IN_VARIABLE, &variableName);

    return true;
}

bool ErrorController::isOperationCorrect(QDomNode &xNode)
{
    return false;
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
