#include "../include/Object.h"

Object::Object() {}

Object::Object(std::vector<Field> _fields)
{
    fields = _fields;
};

std::vector<Field> Object::getFields()
{
    return fields;
}

void Object::addField(Field _field)
{
    fields.push_back(_field);
}
