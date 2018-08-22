/*

*/

#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <bitset>
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
        << "sizeof(char):" << sizeof(char) << std::endl
        << std::endl;

    char theChar = 'D';
    std::bitset<8> xD(theChar);
    std::cout << xD << std::endl;

    theChar = 'a';
    std::bitset<8> xA(theChar);
    std::cout << xA << std::endl;

    // a char is size 1
    // an int is size 4
    // hence if we allocate 4 chars, which will be inorder, then it
    // is big enough for an int
    std::allocator<char> alloc;
    char *buffer = alloc.allocate(4);

    
    std::bitset<32> xBuffer(*buffer);
    std::cout << xBuffer << std::endl;

    std::strcpy(buffer, "hi");

    xBuffer = std::bitset<32>(*buffer);
    std::cout << xBuffer << std::endl;

    // now lets have an int pointer point to the start of the memory
    int *intPtr = (int *)buffer;
    std::cout
        << "Interpretation Matters." << std::endl
        << "========================================" << std::endl
        << "buffer:" << buffer << std::endl
        << "*intPtr:" << *intPtr << std::endl
        << std::endl;

    // now lets turn that buffer into an int we can use
    *intPtr = 7;
    int sum = *intPtr + 3;
    *intPtr = sum;
    xBuffer = std::bitset<32>(*buffer);
    std::cout << xBuffer << std::endl;
    std::cout << "That is sure a lot of zeros and ones just to represent 10"<< std::endl;
    std::cout
        << "Interpretation Matters." << std::endl
        << "========================================" << std::endl
        << "buffer:" << buffer << std::endl
        << "*intPtr:" << *intPtr << std::endl
        << std::endl;

    // a 10 is repsented in memory as a buch of 0's and the 1010
    // 0000 = 0
    // 0001 = 1
    // 0010 = 2
    // ...
    // 1010 = 10
    // a bunch of 0's are in front of that 1010, and a string goes until it hits
    // what it interprets as a null terminator.
    // in this case the null terminator is at the very start, hence it still prints buffer as a string
    // buffer is just empty
    // Saying that, different OS's store things differently so that buffer may look different on an intel box
    // vs some ARM chipped machine, etc.
    // The point is, when you interpret something as a sting that was in int, you get what you get
    // which is usually a bug..

    system("pause");
}
