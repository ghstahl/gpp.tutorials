/*
http://www.cplusplus.com/doc/tutorial/arrays/

Output:

Create and array called foo, and initialize it with 5 integers.
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
foo[5]:5
foo[6]:6
foo[7]:5
foo[8]:6422336
foo[9]:2641920
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
    std::cout
        << "find out how many items in the array and exactly print them."
        << std::endl;
    for (int i = 0; i < numberOfItemsInArray; ++i)
    {
        std::cout
            << "foo[" << i << "]:"
            << foo[i]
            << std::endl;
    }

    std::cout
        << "lets calculated the number of items in the array wrong, and assme there are 10 in there."
        << std::endl;
    // now lets overstep the array and show we can read random memory
    // that memory will be interpreted as an integer, but we only have
    // 5 in the array, but printed 10.  We read over the array .
    // This is the type of bug you may never find in a million line piece of code.
    for (int i = 0; i < numberOfItemsInArray * 2; ++i)
    {
        // NOTE: anything past foo[4] is memory but memory to what and
        // certainly not memory that has been allocated for that foo array
        std::cout
            << "foo[" << i << "]:"
            << foo[i]
            << std::endl;
    }

    std::cout
        << "NOTE: What exactly are those last 5 numbers?."
        << std::endl;

    system("pause");
}
