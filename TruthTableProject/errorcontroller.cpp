#include "errorcontroller.h"

ErrorController::ErrorController() { }

bool ErrorController::isRootNodeCorrect(QDomElement xRootNode)
{
    return false;
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
    return;
}
