/*

*/

#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <bitset>
#include "person.h"
#include "node.h"

int main(int argc, char *argv[])
{

    { // scope
        std::shared_ptr<CPerson> person2;
        std::shared_ptr<CPerson> person3;
        { // scope
            std::shared_ptr<CPerson> person =
                std::make_shared<CPerson>("Zep", "Stahl");
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
