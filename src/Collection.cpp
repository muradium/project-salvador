#include "../include/Collection.h"
#include "../include/rapidjson/prettywriter.h"

Collection::Collection(const char* _name)
{
    name = _name;
}
Collection::Collection(const char* _name, const char* _objectsJSON)
{
    name = _name;

    objects.Parse(_objectsJSON);

    if (!objects.IsArray())
    {
        printf("JSON is not of an array type");
        objects.Clear();
    }
}

std::string Collection::getName()
{
    return name;
}

const char* Collection::getObjects()
{
    rapidjson::StringBuffer sb;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(sb);
    objects.Accept(writer);
    return sb.GetString();
}

bool Collection::addObject(const char* _objectJSON)
{
    rapidjson::Document doc;
    doc.Parse(_objectJSON);
    if (!doc.IsObject())
        return false;

    objects.GetArray().PushBack(doc.GetObject(), objects.GetAllocator());
    return true;
}

void Collection::printMembers()
{
    for(rapidjson::Value::ConstMemberIterator iter = objects.Begin()->MemberBegin(); iter != objects.Begin()->MemberEnd(); iter++)
    {
        printf("%s\n", iter->name.GetString());
    }
}
