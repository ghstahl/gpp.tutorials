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
        CPerson zep;
        zep.SetFirstName("Zep");
        zep.SetLastName("Stahl");
    }
    {
        std::shared_ptr<CPerson> person =
            std::make_shared<CPerson>("Zep", "Stahl");

        std::shared_ptr<Node<CPerson>> rootNode =
            std::make_shared<Node<CPerson>>(person);
 
        person.reset(); 
        // release ownership from main, but the root node has a shared reference so it is still living.

        rootNode->InsertAfter(std::make_shared<CPerson>("Heidi", "Stahl"));
        rootNode->NextNodePtr->InsertBefore(std::make_shared<CPerson>("Herb", "Stahl"));

        std::shared_ptr<Node<CPerson>> iterNode = rootNode;
        while(  iterNode.get() != nullptr){
            std::cout << iterNode->DataPtr->GetFullName() << std::endl;
            iterNode = iterNode->NextNodePtr;
        }

        rootNode->NextNodePtr->Remove();  // this will remove the NextNodePtr from the list.
        iterNode = rootNode;
        while(  iterNode.get() != nullptr){
            std::cout << iterNode->DataPtr->GetFullName() << std::endl;
            iterNode = iterNode->NextNodePtr;
        }

    }

    system("pause");
}
