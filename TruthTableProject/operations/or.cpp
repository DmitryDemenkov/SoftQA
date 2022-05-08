#include "or.h"

Or::Or()
{
    operationPriority = 3;
    operationSign = "||";
}

Or::~Or() { }

int Or::getValue()
{
    return 0;
}
