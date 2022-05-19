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
    return false;
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
