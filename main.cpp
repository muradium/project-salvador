#include <iostream>
#include <cstdlib>
#include "include/Collection.h"
#include "include/rapidjson/document.h"
#include "include/rapidjson/prettywriter.h"

using namespace rapidjson;

int main()
{
    const char* json = {R"([
    {
        "Name": "Murad",
        "Surname": "Talibov",
        "Age": "21",
        "Gender": ""
    },
    {
        "Name": "Jane",
        "Surname": "",
        "Age": "",
        "Gender": "Female"
    }
])"};

    Collection myCollection("users", json);

    myCollection.printMembers();

    const char* newJSON = {R"(
    {
        "Name": "Behlul",
        "Surname": "Hesenli"
    }
)"};

    myCollection.addObject(newJSON);

    puts(myCollection.getObjects());

    system("PAUSE");
    return 0;
}