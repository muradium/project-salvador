#include <iostream>
#include <vector>
#include "../include/Object.h"

class Collection
{
  private:
    std::string name;
    std::vector<Object> objects;
    Object schema;

  public:
    Collection(std::string _name);
    Collection(std::string _name, std::vector<Object> _objects);

    std::string getName();
    std::vector<Object> getObjects();
    bool addObject(Object _object);
    bool addObjects(std::vector<Object> _objects);
    // bool addObjects(std::string objectsJSON);
    std::string toString();
};