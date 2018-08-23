/*

*/

#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <bitset>
#include "person.h"

int main(int argc, char *argv[])
{
    { // scope
        CPerson zep;
        zep.SetFirstName("Zep");
        zep.SetLastName("Stahl");
    }

    system("pause");
}
