#include <iostream>

class Field
{
  public:
    enum FieldType
    {
        String, Int32, Boolean, NIL
    };

    std::string name;
    std::string value;
    std::string type;

    Field();
    Field(std::string _name, std::string _value, std::string _type);

    std::string toString();
};

