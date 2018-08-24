/*
 

Output:

 
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
        << "sizeof(short int):" << sizeof(short int) << std::endl
        << "sizeof(short int*):" << sizeof(short int*) << std::endl
        << "sizeof(int):" << sizeof(int) << std::endl
        << "sizeof(int*):" << sizeof(int*) << std::endl
        << "sizeof(long):" << sizeof(long) << std::endl
        << "sizeof(long*):" << sizeof(long*) << std::endl
        << "sizeof(long int):" << sizeof(long int) << std::endl
        << "sizeof(long int*):" << sizeof(long int*) << std::endl
        << "sizeof(long long):" << sizeof(long long) << std::endl
        << "sizeof(long long*):" << sizeof(long long*) << std::endl
        << "sizeof(long long int):" << sizeof(long long int) << std::endl
        << "sizeof(long long int*):" << sizeof(long long int*) << std::endl
        << "sizeof(unsigned long long int):" << sizeof(unsigned long long int) << std::endl
        << "sizeof(unsigned long long int*):" << sizeof(unsigned long long int*) << std::endl
        << "sizeof(float):" << sizeof(float) << std::endl
        << "sizeof(float*):" << sizeof(float*) << std::endl
        << "sizeof(double):" << sizeof(double) << std::endl
        << "sizeof(double*):" << sizeof(double*) << std::endl
        << "sizeof(long double):" << sizeof(long double) << std::endl
        << "sizeof(long double*):" << sizeof(long double*) << std::endl
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
