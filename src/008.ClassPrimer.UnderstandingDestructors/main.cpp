/*
classes when allocated invoke a constructor
classes when deallocated invode the destructor for the object that is getting deleted.
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
        std::cout << ">>>> Constructor:: CPerson" << std::endl;
    }
    CPerson(std::string firstName, std::string lastName)
    {
        std::cout
            << ">>>> Constructor:: CPerson(" << firstName << "," << lastName << ")"
            << std::endl;
        /* a constructor that takes 2 arguments */
        FirstName = firstName;
        LastName = lastName;
    }
    ~CPerson()
    {
        std::cout << "<<<< Destructor:: CPerson  -- data is still good, until this function leaves" << std::endl;
        std::cout
            << "        GetFullName:" << GetFullName()
            << std::endl;
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

    if (true)
    {
        CPerson *somePerson = new CPerson("Donald", "Duck");
        delete somePerson; // we have now reclaimed all memory allocation to the Donald Duck object
        somePerson = nullptr;
    }

    if (true)
    {
        CPerson *somePerson = new CPerson("Ham", "Burglar");
        // oops, didn't delete and you will not see any destructor getting called for Ham Burglar
    }
    // the if scope ended, the somePerson pointer has been reclaimed, but
    // we never called delete so the memory that somePerson pointed to is now leaked.

    // NOTE: you are not going to see the CPerson zep; destructor, because
    // this gets auto deallocated when the program exists, so there is nothing to
    // print to.  Just going to have to trust this one.

    system("pause");
}
