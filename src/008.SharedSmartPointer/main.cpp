/*

*/

#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <bitset>
#include "person.h"
#include "node.h"

class SomeEngine
{
    std::shared_ptr<CPerson> SomePersonPtr;

  public:
    SomeEngine()
    {
        SomePersonPtr =
            std::make_shared<CPerson>("Heidi", "Stahl");

        std::cout
            << ">>>> Constructor:: SomeEngine()"
            << std::endl
            << "        SomePersonPtr->GetFullName:" << SomePersonPtr->GetFullName()
            << std::endl;
    }
    ~SomeEngine()
    {
        std::cout
            << "<<<< Destructor:: SomeEngine  -- data is still good, until this function leaves" 
            << std::endl;
        std::cout
            << "        SomePersonPtr->GetFullName:" << SomePersonPtr->GetFullName()
            << std::endl;
    }
    std::shared_ptr<CPerson> GetPerson()
    {
        return SomePersonPtr;
    }
};

int main(int argc, char *argv[])
{

    { // scope
        std::shared_ptr<SomeEngine> someEngine = std::make_shared<SomeEngine>();
        std::shared_ptr<CPerson> person2;
        std::shared_ptr<CPerson> person3;
        { // scope
            std::shared_ptr<CPerson> person = someEngine->GetPerson();
            std::cout
                << "person: use_count:" << person.use_count() << " "
                << "person2:use_count:" << person2.use_count() << " "
                << "person3:use_count:" << person3.use_count() << " "
                << std::endl;
            person2 = person;

            std::cout
                << "person: use_count:" << person.use_count() << " "
                << "person2:use_count:" << person2.use_count() << " "
                << "person3:use_count:" << person3.use_count() << " "
                << std::endl;

            person3 = person2;

            std::cout
                << "person: use_count:" << person.use_count() << " "
                << "person2:use_count:" << person2.use_count() << " "
                << "person3:use_count:" << person3.use_count() << " "
                << std::endl;
        }
        std::cout
            << "person2:use_count:" << person2.use_count() << " "
            << "person3:use_count:" << person3.use_count() << " "
            << std::endl;

        person3.reset();
        std::cout
            << "person2:use_count:" << person2.use_count() << " "
            << "person3:use_count:" << person3.use_count() << " "
            << std::endl;
        std::cout
            << "person2->GetFullName:: " << person2->GetFullName() << std::endl;
    }

    system("pause");
}
