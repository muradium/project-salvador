#include <iostream>
#include <vector>
#include "Field.h"

class Object
{ 
  private:
    std::vector<Field> fields;
  public:
    Object();
    Object(std::vector<Field> _fields);

    std::vector<Field> getFields();
    void addField(Field _field);
};