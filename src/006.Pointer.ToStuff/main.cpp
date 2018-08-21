/*
http://www.cplusplus.com/doc/tutorial/arrays/

Output:

Create and array called foo, and initialize it with 5 integers.
ptrInt:0x61fef8
that ptrInt value, like the address of your house, is called the pointer address
dereferemced *ptrInt points to:16
Now for pointer math
find out how many items in the array and exactly print them.
foo[0]:16
foo[1]:2
foo[2]:77
foo[3]:40
foo[4]:12071
lets calculated the number of items in the array wrong, and assme there are 10 in there.
foo[0]:16
foo[1]:2
foo[2]:77
foo[3]:40
foo[4]:12071
foo[5]:16
foo[6]:5
foo[7]:7
foo[8]:5
foo[9]:6422300
NOTE: What exactly are those last 5 numbers?.
Press any key to continue . . .
*/

#include <iostream>
int main(int argc, char *argv[])
{

    std::cout
        << "Create and array called foo, and initialize it with 5 integers."
        << std::endl;
    int foo[5] = {16, 2, 77, 40, 12071};
    int numberOfItemsInArray = (sizeof(foo) / sizeof(*foo));

    /* 
A pointer, well, points to things.  A pointer, itself takes up memory

*/

    // this is a pointer that only points to what it interprets as an integer.
    // When the pointer advances, it only advances in increments of an integer
    int *ptrInt = nullptr;

    // lets point ptrInt to the stat of our foo array.
    ptrInt = foo;

    // lets print ptrInt
    std::cout
        << "ptrInt:"
        << ptrInt
        << std::endl;
    std::cout << "that ptrInt value, like the address of your house, is called the pointer address"
              << std::endl;
    // if you want to know what the pointer points to you must dereference it.
    int whatYouAre = *ptrInt;
    std::cout << "dereferemced *ptrInt points to:"
              << whatYouAre
              << std::endl;

    std::cout << "Now for pointer math"
              << std::endl;
    std::cout
        << "find out how many items in the array and exactly print them."
        << std::endl;

    ptrInt = foo; // points to start of the foo array
    for (int i = 0; i < numberOfItemsInArray; ++i, ++ptrInt)
    {
        std::cout
            << "foo[" << i << "]:"
            << *ptrInt
            << std::endl;
    }

    std::cout
        << "lets calculated the number of items in the array wrong, and assme there are 10 in there."
        << std::endl;
    // now lets overstep the array and show we can read random memory
    // that memory will be interpreted as an integer, but we only have
    // 5 in the array, but printed 10.  We read over the array .
    // This is the type of bug you may never find in a million line piece of code.
    ptrInt = foo; // points to start of the foo array
    for (int i = 0; i < numberOfItemsInArray * 2; ++i, ++ptrInt)
    {
        // NOTE: anything past foo[4] is memory but memory to what and
        // certainly not memory that has been allocated for that foo array
        std::cout
            << "foo[" << i << "]:"
            << *ptrInt
            << std::endl;
    }

    std::cout
        << "NOTE: What exactly are those last 5 numbers?."
        << std::endl;

    system("pause");
}
