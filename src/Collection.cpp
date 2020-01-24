#include "../include/Collection.h"

Collection::Collection(std::string _name) { name = _name; }
Collection::Collection(std::string _name, std::vector<Object> _objects) { name = _name; objects = _objects; }

std::string Collection::getName()
{
    return name; 
}

std::vector<Object> Collection::getObjects()
{
    return objects;
}

bool Collection::addObject(Object _object)
{
    // Add missing fields to the schema; check for type mismatches
    // !!! Missing case: duplicate fields of the same type !!!
    for (int k = 0; k < _object.getFields().size(); k++)
    {
        bool fieldFound = false;

        for (int j = 0; j < schema.getFields().size(); j++)
        {
            // Field found on the schema
            if (_object.getFields()[k].name == schema.getFields()[j].name)
            {
                // Type mismatch
                if (_object.getFields()[k].type != schema.getFields()[j].type)
                    return false;

                fieldFound = true;
            }
        }

        if (!fieldFound)
        {
            Field newField = _object.getFields()[k];
            newField.value = "";
            schema.addField(newField);
        }
    }

    objects.push_back(_object);
    return true;
}

bool Collection::addObjects(std::vector<Object> _objects)
{
    bool isSuccess = true;

    for (int i = 0; i < _objects.size(); i++)
    {
        isSuccess &= addObject(_objects[i]);
    }

    return isSuccess;
}

std::string Collection::toString()
{
    std::string collectionJSON = "{\n";

    for (int i = 0; i < objects.size(); i++)
    {
        collectionJSON += "{\n\t";
        for (int j = 0; j < schema.getFields().size(); j++)
        {
            Field currentField = schema.getFields()[j];
            for (int k = 0; k < objects[i].getFields().size(); k++)
            {
                if (objects[i].getFields()[k].name == currentField.name)
                {
                    currentField.value = objects[i].getFields()[k].value;
                    break;
                }
            }

            collectionJSON += currentField.toString();

            if (j != schema.getFields().size() - 1)
                collectionJSON += ",\n\t";
        }
        collectionJSON += "\n}";

        if (i != objects.size() - 1)
        {
            collectionJSON += ",\n";
        }
    }
    
    collectionJSON += "\n}";

    return collectionJSON;
}