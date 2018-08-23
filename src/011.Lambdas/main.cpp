/*
https://github.com/AnthonyCalandra/modern-cpp-features/blob/master/CPP11.md#lambda-expressions
*/

#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <bitset>
 

int main(int argc, char *argv[])
{
    int a = 1, b = 2;
    int x = 1;
    auto getX = [=] {
        // cannot modify x here
        return x;
    };
    auto getX2 = [&] {
        // [&] means that we can modify x
        x = 99;
        return x;
    };
    auto modAndAddX3 = [a, &b] {
        // capture objects a by value, b by reference.
        // [&] means that we can modify x

        // cannot modify a, can modify b
        b = 99;
        return a + b;
    };
    auto addX = [=](int y) { return x + y; };
    std::cout << "getX:" << getX() << std::endl;
    std::cout << "getX2:" << getX2() << std::endl;
    std::cout << "x:" << x << std::endl;
    std::cout << "addX:" << addX(3) << std::endl;

    std::cout << "a:" << a << " b:" << b << std::endl;
    std::cout << "modAndAddX3:" << modAndAddX3() << std::endl;
    std::cout << "a:" << a << " b:" << b << std::endl;

    system("pause");
}
