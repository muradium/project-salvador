#include "../include/Field.h"

Field::Field(std::string _name, std::string _value, std::string _type)
{
    name = _name;
    value = _value;
    type = _type;
};

std::string Field::toString()
{
    return "\"" + name + "\": \"" + value + "\"";
}