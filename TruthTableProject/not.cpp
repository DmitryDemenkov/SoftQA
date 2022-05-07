#include "not.h"

Not::Not()
{
    operationPriority = 5;
    operationSign = "!";
}

Not::~Not() { }

int Not::getValue()
{
    return 0;
}
