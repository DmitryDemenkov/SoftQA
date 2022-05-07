#include "variable.h"

Variable::Variable()
{
    value = 0;
}

Variable::~Variable() { }

void Variable::setStringId(QString name)
{
    // Установить имя переменной строковому представлению узла
    string_id = name;
}

void Variable::setValue(int value)
{
    // Если новое значение удовлетворяет интервалу [0, 1]
    if (value >= 0 && value <= 1)
        this->value = value; // установить новое значение переменной
}

int Variable::getValue()
{
    // Вернуть значение переменной
    return value;
}
