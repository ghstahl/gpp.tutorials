/*

./a.exe a -s 1 2.34 "I like cheese, I just do"
is the same as
./a.exe "add" "1" "2.34"
you put "" around anything that has a space in it.

https://www.geeksforgeeks.org/converting-strings-numbers-cc/

output:

You have entered 4 arguments:
arg[0]: H:\Github\ghstahl\gpp.tutorials\src\004.Arguments.Operants\a.exe
arg[1]: add
arg[2]: 1
arg[3]: 2.34
intResult:3
floatResult:3.34
Press any key to continue . . .


H:\Github\ghstahl\gpp.tutorials\src\004.Arguments.Operants>a.exe mult 2 3.45
You have entered 4 arguments:
arg[0]: a.exe
arg[1]: mult
arg[2]: 2
arg[3]: 3.45
intResult:6
floatResult:6.9
Press any key to continue . . .

H:\Github\ghstahl\gpp.tutorials\src\004.Arguments.Operants>a.exe div 9 2.3
You have entered 4 arguments:
arg[0]: a.exe
arg[1]: div
arg[2]: 9
arg[3]: 2.3
intResult:3
floatResult:3.91304
Press any key to continue . . .

*/

#include <iostream>
#include <sstream>
#include <string>
int main(int argc, char *argv[])
{
    std::cout << "You have entered " << argc
              << " arguments:"
              << "\n";

    for (int i = 0; i < argc; ++i)
        std::cout << "arg[" << i << "]: " << argv[i] << std::endl;

    std::stringstream firstNumberStream(argv[2]); // better be what looks like a number
    std::stringstream secondNumberStream(argv[3]);

    int firstNumber = 0;
    firstNumberStream >> firstNumber; // firstNumber is now assigned to what was passed in.

    float secondNumber = 0.0;           // we are passing in 2.34, which is NOT and integer
    secondNumberStream >> secondNumber; // secondNumber is now assigned to what was passed in.

    std::string operant(argv[1]);

    int intResult = 0;
    float floatResult = 0.0;

    // integer and float math matter, so lets do both.
    if (operant.compare("add") == 0)
    {
        intResult = firstNumber + secondNumber;
        floatResult = firstNumber + secondNumber;
    }
    if (operant.compare("mult") == 0)
    {
        intResult = firstNumber * secondNumber;
        floatResult = firstNumber * secondNumber;
    }
    if (operant.compare("div") == 0)
    {
        intResult = firstNumber / secondNumber;
        floatResult = firstNumber / secondNumber;
    }

    std::cout << "intResult:" << intResult << std::endl;
    std::cout << "floatResult:" << floatResult << std::endl;

    system("pause");
}
