#include <iostream>
#include <vector>
// #include "../include/Object.h"
#include "../include/rapidjson/document.h"

class Collection
{
  private:
    std::string name;
    rapidjson::Document objects;

  public:
    Collection(const char* _name);
    Collection(const char* _name, const char* _objectsJSON);

    std::string getName();
    const char* getObjects();
    void printMembers();
    bool addObject(const char* _objectJSON);
};