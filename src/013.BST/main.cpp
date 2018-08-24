/*

*/

#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <iterator>
#include <cstring>
#include <bitset>
#include <random>
#include <algorithm> // std::for_each
#include <functional>
#include "person.h"
#include "../shared/bst.h"

void myfunction(std::shared_ptr<int> spInt)
{ // function:
    std::cout << ' ' << *spInt;
}
int main(int argc, char *argv[])
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1, 100);
    auto dice = std::bind(distribution, generator);

    std::shared_ptr<int> rand =
        std::make_shared<int>(dice());
    std::shared_ptr<BSTNode<int>> rootNode = std::make_shared<BSTNode<int>>(rand);
    for (int i = 0; i < 10; ++i)
    {
        int roll = dice();

        std::shared_ptr<int> rand =
            std::make_shared<int>(dice());
        rootNode->RecursiveInsert(rand);

        if (roll != 50)
        {
            std::shared_ptr<int> dup =
                std::make_shared<int>(50);
            rootNode->RecursiveInsert(dup);
        }
    }

    std::list<std::shared_ptr<int>> sorted;
    rootNode->SortMostLeft(sorted);
    std::for_each(sorted.begin(), sorted.end(), myfunction);
    std::cout << std::endl;

    sorted.clear();

    rootNode->SortMostRight(sorted);
    std::for_each(sorted.begin(), sorted.end(), myfunction);

    std::cout << std::endl;

    system("pause");
}
