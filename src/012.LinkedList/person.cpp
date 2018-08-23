/*
person.cpp just doesn't get compiled because its here, you have to tell
g++ to do it.

Visual Studio Code.....
in tasks.json

"args": [
                "-g","main.cpp","person.cpp"
            ],

annoying, but other ide's would most likely do this for you.
*/

#include <iostream>
#include <string>
#include <memory>
#include "person.h"

CPerson::CPerson()
{
    /* an empty constructor */
    std::cout << ">>>> Constructor:: CPerson" << std::endl;
}

CPerson::CPerson(std::string firstName, std::string lastName)
{
    std::cout
        << ">>>> Constructor:: CPerson(" << firstName << "," << lastName << ")"
        << std::endl;
    /* a constructor that takes 2 arguments */
    FirstName = firstName;
    LastName = lastName;
}
CPerson::~CPerson()
{
    std::cout << "<<<< Destructor:: CPerson  -- data is still good, until this function leaves" << std::endl;
    std::cout
        << "        GetFullName:" << GetFullName()
        << std::endl;
}
std::string CPerson::GetFirstName()
{
    return FirstName;
}
void CPerson::SetFirstName(std::string firstName)
{
    FirstName = firstName;
}
std::string CPerson::GetLastName()
{
    return LastName;
}
void CPerson::SetLastName(std::string lastName)
{
    LastName = lastName;
}
std::string CPerson::GetFullName()
{
    return FirstName + " " + LastName;
}
int CPerson::GetInstanceSize()
{
    // I don't know how much memory std::string uses to store each character
    // so guessing here, but good enough to show memory usage.
    return sizeof(CPerson) // overhead
           + FirstName.length() + LastName.length();
}