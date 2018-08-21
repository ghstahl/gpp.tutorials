/*
before there was C++ there was C.  So far we have only been doing C, so here
is the first time we are going to do the ++ part.

classes.

classes let you make your own types.  An int (integer) is a primitive type, and 
you get that for free.  

You have been using a class without really knowing it.
std::string is a class that handles the complexity of a string.
http://www.cplusplus.com/reference/string/string/

i.e. to get length of an int you need to call sizeof(someInt).
for a string, there is a member method on the std::string class called 
length()

a lot of time was spent writing that very usefull class so that the rest of us
don't have to mess around with the dirtieness of string managment.

*/

#include <iostream>
#include <string>

class CPerson
{
  private:
    std::string FirstName;
    std::string LastName;

  public:
    CPerson()
    {
        /* an empty constructor */
    }
    CPerson(std::string firstName, std::string lastName)
    {
        /* a constructor that takes 2 arguments */
        FirstName = firstName;
        LastName = lastName;
    }
    std::string GetFirstName()
    {
        return FirstName;
    }
    void SetFirstName(std::string firstName)
    {
        FirstName = firstName;
    }
    std::string GetLastName()
    {
        return LastName;
    }
    void SetLastName(std::string lastName)
    {
        LastName = lastName;
    }
    std::string GetFullName()
    {
        return FirstName + " " + LastName;
    }
    int GetInstanceSize()
    {
        // I don't know how much memory std::string uses to store each character
        // so guessing here, but good enough to show memory usage.
        return sizeof(CPerson) // overhead
               + FirstName.length() + LastName.length();
    }
};

int main(int argc, char *argv[])
{

    std::cout
        << "SIZE MATTERS." << std::endl
        << "========================================" << std::endl
        << "sizeof(std::string):" << sizeof(std::string) << std::endl
        << "sizeof(CPerson):" << sizeof(CPerson) << std::endl
        << std::endl;

    // notice that a std::string's size is 24
    // note that CPerson constains 2 std::string's so CPerson's size if 24

    // This is the size of the type, not what will eventually be stored in there.
    // That is the minimum size that this object takes up just to exist.
    // think of a baby and then 18 years of feeding its still the same person object
    // just bigger.

    // lets create 2 intances of our CPerson class

    CPerson zep;
    zep.SetFirstName("Zep");
    zep.SetLastName("Stahl");

    CPerson heidi("Heidi", "Dog");
    heidi.SetLastName("Stahl");

    std::cout
        << "CPerson zep;" << std::endl
        << "sizeof(zep):" << sizeof(zep) << std::endl
        << "sizeof(CPerson):" << sizeof(CPerson) << std::endl
        << std::endl;

    std::cout
        << "zep.GetFullName():" << zep.GetFullName() << std::endl
        << "heidi.GetFullName():" << heidi.GetFullName() << std::endl
        << std::endl;
    // how much memory is really being taken up.
    // i.e. there is overhead, then there is what is stored.
    // lets add a method to our person class to calculate the true size of
    // an instance.

    std::cout
        << "CPerson zep;" << std::endl
        << "sizeof(zep):" << sizeof(zep) << std::endl
        << "sizeof(CPerson):" << sizeof(CPerson) << std::endl
        << "zep.GetInstanceSize():" << zep.GetInstanceSize() << std::endl
        << "heidi.GetInstanceSize():" << heidi.GetInstanceSize() << std::endl
        << std::endl;

    // Pointers
    CPerson *somePerson = nullptr;
    somePerson = &zep; // somePerson now points to the address of zep

    std::cout
        << "somePerson = &zep;" << std::endl
        << "somePerson->GetFullName():" << somePerson->GetFullName() << std::endl
        << std::endl;

    somePerson = &heidi; // somePerson now points to the address of i

    std::cout
        << "somePerson = &zep;" << std::endl
        << "somePerson->GetFullName():" << somePerson->GetFullName() << std::endl
        << std::endl;

    system("pause");
}
