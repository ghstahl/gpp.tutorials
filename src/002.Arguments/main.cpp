/*

./a.exe a -s 1 2.34 "I like cheese, I just do"
is the same as

./a.exe "a" "-s" "1" "2.34" "I like cheese, I just do"

you put "" around anything that has a space in it.

output

H:\Github\ghstahl\gpp.tutorials\src\001.HelloWorld>.\a.exe
hello world!
10+2=20
Press any key to continue . . .

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
