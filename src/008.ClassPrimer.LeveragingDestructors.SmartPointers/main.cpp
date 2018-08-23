/*
classes when allocated invoke a constructor
classes when deallocated invode the destructor for the object that is getting deleted.
*/

#include <iostream>
#include <string>
#include <memory>

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

class CPersonSmartPtr
{
    CPerson *_ptr; // Actual pointer
    void safeDelete()
    {
        if (_ptr != nullptr)
        {
            delete (_ptr);
        }
        _ptr = nullptr;
    }

  public:
    // Constructor: Refer https://www.geeksforgeeks.org/g-fact-93/
    // for use of explicit keyword
    explicit CPersonSmartPtr(CPerson *p = NULL) { _ptr = p; }

    // Destructor
    ~CPersonSmartPtr()
    {
        safeDelete();
    }

    CPerson *Release()
    {
        CPerson *p = _ptr;
        _ptr = nullptr;
        return p;
    }
    // Overloading dereferencing operator
    CPerson &operator*() { return *_ptr; }
    // Overloading pointer operator
    CPerson *operator->() { return _ptr; }
    // Overloading the = operator.  This will delete the containted pointer prior to assigning
    void operator=(CPerson *p)
    {
        safeDelete();
        _ptr = p;
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
        CPersonSmartPtr personSmartPtr(somePerson);
        // let the CPersonSmartPtr object handle the lifecycle of the real pointer for us.
        std::cout << "" << personSmartPtr->GetFullName() << std::endl;

        somePerson = new CPerson("Just", "Goofey"); 
        // NOTE: We assigned somePerson to Goofey, but Donald Duck is still goood
        // because a pointer to donald duck still exists in personSmartPtr
        // so we turned over lifecycle management to the smart pointer, thus
        // letting us reuse the primitive somePerson pointer.

        personSmartPtr = somePerson; // this will delete donald duck
        std::cout << "" << personSmartPtr->GetFullName() << std::endl;
    }

    if (true)
    {
        // smart pointer are so important that they are part
        // of the std library.
        CPerson *somePerson = new CPerson("Donald", "Duck");
        std::unique_ptr<CPerson> personSmartPtr(somePerson);
        std::cout << "personSmartPtr->GetFullName()" << personSmartPtr->GetFullName() << std::endl;

         somePerson = new CPerson("Just", "Goofey"); 
         personSmartPtr = (std::unique_ptr<CPerson>(somePerson));
        // let the std::unique_ptr<CPerson> object handle the
        // lifecycle of the real pointer for us.
        // std::unique_ptr<AnythingThatCanHaveAPointer>
        std::unique_ptr<int> intPtr = std::unique_ptr<int>(new int(10)); // (10)  null  null

        std::cout << "*intPtr.get():" << *intPtr.get() << std::endl;
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
