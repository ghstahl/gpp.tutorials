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

    CPerson zep;
    zep.SetFirstName("Zep");
    zep.SetLastName("Stahl");

    // The zep object is created on the stack, and all memory is reclaimed with
    // the scope of the call is left.  The scope here is this main function.

    if (true)
    {
        // this is also a scope
        CPerson heidi("Heidi", "Stahl");
        // when we leave the if statement, heidi is reclaimed as it was created
        // on the stack
    }

    // CPerson heidi is gone and reclaimed
    // CPerson zep; is still around until its scope is over.  i.e. end of main(){}

    // lets take controll of how this objects are created
    CPerson *somePerson = new CPerson("Donald", "Duck");
    std::cout
        << "somePerson->GetFullName():" << somePerson->GetFullName() << std::endl
        << std::endl;

    // to reclaim the memory that was allocated for what somePerson is pointing to
    // is our responsiblity.
    std::cout
        << "pre-delete somePerson:" << somePerson << std::endl
        << std::endl;
    delete somePerson; // we have now reclaimed all memory allocation to the Donald Duck object
    std::cout
        << "post-delete somePerson:" << somePerson << std::endl
        << std::endl;

    // this next statement will crash, because somePerson is 
    // now pointing to NOT a CPerson object..  
    // Uncomment the following to see the crash;

    //std::string fullName = somePerson->GetFullName(); // this will crash

    // NOTE: somePerson is still a legit address, it just points to "who the hell knows?"
    // to do our job properly, we need to either assign somePerson to nullPtr or another
    // person.

    somePerson = nullptr;

    // dynamically creating object is powerfull, but with power comes
    // responsiblity and sloppiness produced bugs and in this case this could
    // lead to horibble memory leaks.

    // lets leak some memory.

    somePerson = new CPerson("Donald", "Duck");
    std::cout
        << "somePerson:" << somePerson << " " << somePerson->GetFullName()
        << std::endl;
    somePerson = nullptr;

    // we created the Donald Duck person object, and then we lost its address by
    // assigning what was pointing to Donald Duck person objec to nullptr

    // we know have no way to reclaim that object, hence it is sitting forever in
    // computer memory until our application exists.

    // this is also a leak
    std::cout
        << "================================="
        << std::endl;

    somePerson = new CPerson("Donald", "Duck"); // leaked
    std::cout
        << "somePerson:" << somePerson << " " << somePerson->GetFullName()
        << std::endl;

    somePerson = new CPerson("Donald", "Duck"); // leaked
    std::cout
        << "somePerson:" << somePerson << " " << somePerson->GetFullName()
        << std::endl;

    somePerson = new CPerson("Donald", "Duck"); // leaked
    std::cout
        << "somePerson:" << somePerson << " " << somePerson->GetFullName()
        << std::endl;

    somePerson = new CPerson("Donald", "Duck"); // leaked
    std::cout
        << "somePerson:" << somePerson << " " << somePerson->GetFullName()
        << std::endl;

    somePerson = new CPerson("Donald", "Duck"); // not leaked as we delete it below
    std::cout
        << "somePerson:" << somePerson << " " << somePerson->GetFullName()
        << std::endl;

    delete somePerson;
    somePerson = nullptr;

    // we created 5 Donald Duck object, and lost the address to the first 4.
    // by assigning the somePerson pointer to something else.

    system("pause");
}
