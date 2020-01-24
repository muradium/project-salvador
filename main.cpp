#include <iostream>
#include <cstdlib>
#include "include/Collection.h"

int main()
{
    Collection myCollection("Users");
    std::cout<<"\""<<myCollection.getName()<<"\" collection added\n\n";
    
    Field name("Name", "Murad", "String");
    Field surname("Surname", "Talibov", "String");
    Field age("Age", "21", "Int32");

    Object me(std::vector<Field>{ name, surname, age });
    myCollection.addObject(me);

    std::cout<<myCollection.toString()<<"\n\n";

    Field name2("Name", "Jane", "String");
    Field gender("Gender", "Female", "String");

    Object girl(std::vector<Field>{ name2, gender });
    myCollection.addObject(girl);

    std::cout<<myCollection.toString()<<std::endl;

    system("PAUSE");
    return 0;
}