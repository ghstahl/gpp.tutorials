/*

./a.exe a -s 1 2.34 "I like cheese, I just do"
is the same as

./a.exe "a" "-s" "1" "2.34" "I like cheese, I just do"

you put "" around anything that has a space in it.

output

You have entered 6 arguments:
arg[0]: a.exe
arg[1]: a
arg[2]: -s
arg[3]: 1
arg[4]: 2.34
arg[5]: I like cheese, I just do
NOTE: every argument is a string, even though some look like they are numbers.

*/

#include <iostream>
int main(int argc, char *argv[])
{
    std::cout << "You have entered " << argc
              << " arguments:"
              << "\n";

    for (int i = 0; i < argc; ++i)
        std::cout << "arg[" << i << "]: " << argv[i] << std::endl;

    std::cout
        << "NOTE: every argument is a string, even though some look like they are numbers."
        << std::endl;

    system("pause");
}
