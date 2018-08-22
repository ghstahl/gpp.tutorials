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
#include <string>
int main(int argc, char *argv[])
{

    std::cout
        << "SIZE MATTERS." << std::endl
        << "========================================" << std::endl
        << "sizeof(bool):" << sizeof(bool) << std::endl
        << "sizeof(bool*):" << sizeof(bool *) << std::endl
        << "sizeof(short):" << sizeof(short) << std::endl
        << "sizeof(short*):" << sizeof(short*) << std::endl
        << "sizeof(int):" << sizeof(int) << std::endl
        << "sizeof(int*):" << sizeof(int*) << std::endl
        << "sizeof(float):" << sizeof(float) << std::endl
        << "sizeof(float*):" << sizeof(float*) << std::endl
        << "sizeof(double):" << sizeof(double) << std::endl
        << "sizeof(double*):" << sizeof(double*) << std::endl
        << "sizeof(std::string):" << sizeof(std::string) << std::endl
        << "sizeof(std::string*):" << sizeof(std::string*) << std::endl
        << std::endl;

    int anInteger = 123;
    std::cout
        << "int anInteger = 123;" << std::endl
        << "sizeof(anInteger):" << sizeof(anInteger) << std::endl
        << "sizeof(int):" << sizeof(int) << std::endl
        << std::endl;

    bool aBool = true;
    std::cout
        << "bool aBool = true;" << std::endl
        << "sizeof(aBool):" << sizeof(aBool) << std::endl
        << "sizeof(bool):" << sizeof(bool) << std::endl
        << std::endl;

    float aFloat = 123.456;
    std::cout
        << "float aFloat = 123.456;" << std::endl
        << "sizeof(aFloat):" << sizeof(aFloat) << std::endl
        << "sizeof(float):" << sizeof(float) << std::endl
        << std::endl;

    std::string aMessage = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
    std::cout
        << "aMessage:"
        << "\"" << aMessage << "\"" << std::endl
        << "sizeof(aMessage):" << sizeof(aMessage) << std::endl
        << "aMessage.size:" << aMessage.size() << std::endl
        << "sizeof(std::string):" << sizeof(std::string) << std::endl
        << std::endl;

    int foo[5] = {16, 2, 77, 40, 12071};
    std::cout
        << "int foo[5] = {16, 2, 77, 40, 12071};" << std::endl
        << "sizeof(foo):" << sizeof(foo) << std::endl
        << "(sizeof(foo) / sizeof(*foo)):" << (sizeof(foo) / sizeof(*foo)) << std::endl
        << std::endl;

    system("pause");
}
