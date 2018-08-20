/*

./a.exe a -s 1 2.34 "I like cheese, I just do"
is the same as
./a.exe "a" "-s" "1" "2.34" "I like cheese, I just do"
you put "" around anything that has a space in it.

https://www.geeksforgeeks.org/converting-strings-numbers-cc/
*/

#include <iostream>
#include <sstream>
int main(int argc, char *argv[])
{
    std::cout << "You have entered " << argc
              << " arguments:"
              << "\n";

    for (int i = 0; i < argc; ++i)
        std::cout << "arg[" << i << "]: " << argv[i] << std::endl;

    std::stringstream firstNumberStream(argv[3]); // better be what looks like a number
    std::stringstream secondNumberStream(argv[4]);

    int firstNumber = 0;
    firstNumberStream >> firstNumber; // firstNumber is now assigned to what was passed in.

    float secondNumber = 0.0;           // we are passing in 2.34, which is NOT and integer
    secondNumberStream >> secondNumber; // secondNumber is now assigned to what was passed in.

    // integer and float math matter, so lets do both.

    // even though one of the numbers is a float,
    //what it gets assigned to is an int.  intResult will throw away an decimal
    int intResult = firstNumber + secondNumber;
    std::cout << "intResult:" << intResult << std::endl;

    float floatResult = firstNumber + secondNumber;
    std::cout << "floatResult:" << floatResult << std::endl;

    system("pause");
}
