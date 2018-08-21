/*

*/

#include <iostream>
#include <string>
#include <sstream>
std::string ConvertToHex(int val)
{
    std::stringstream stream;
    stream << std::hex << val;
    std::string result(stream.str());
    return result;
}
int main(int argc, char *argv[])
{

    std::cout
        << "SIZE MATTERS." << std::endl
        << "========================================" << std::endl
        << "sizeof(int):" << sizeof(int) << std::endl
        << "sizeof(int*):" << sizeof(int *) << std::endl
        << std::endl;

    int a = INT32_MAX;
    int b = INT32_MIN;

    std::cout
        << "SIZE MATTERS." << std::endl
        << "========================================" << std::endl
        << "a:" << a << "  " << ConvertToHex(a) << std::endl
        << "(a<<1):" << (a << 1) << "  " << ConvertToHex(a << 1) << std::endl
        << "b:" << b << "  " << ConvertToHex(b) << std::endl
        << "b<<1:" << (b << 1) << "  " << ConvertToHex(b << 1) << std::endl

        << std::endl;

    system("pause");
}
