/*

*/

#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <bitset>
#include <random>
#include <functional>
#include "person.h"
#include "node.h"
int main(int argc, char *argv[])
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1, 100);
    auto dice = std::bind(distribution, generator);

    std::shared_ptr<int> rand =
        std::make_shared<int>(dice());
    std::shared_ptr<Node<int>> rootNode = std::make_shared<Node<int>>(rand);
    for (int i = 0; i < 10; ++i)
    {
        std::shared_ptr<int> rand =
            std::make_shared<int>(dice());
        rootNode->InsertAfter(rand);
    }
    std::shared_ptr<Node<int>> iterNode = rootNode;
    while (iterNode.get() != nullptr)
    {
        std::cout << *(iterNode->DataPtr) << std::endl;
        iterNode = iterNode->NextNodePtr;
    }

    int nIterations = 0;

    while (true)
    {
        nIterations++;
        iterNode = rootNode;
        bool swapped = false;
        while (iterNode.get() != nullptr)
        {
            auto nextNode = iterNode->NextNodePtr;
            if (nextNode.get() != nullptr)
            {
                auto currentDataPtr = iterNode->DataPtr;
                auto nextDataPtr = nextNode->DataPtr;
                int current = *(currentDataPtr);
                int next = *(nextDataPtr);
                if (current > next)
                {
                    // swap
                    iterNode->DataPtr = nextDataPtr;
                    nextNode->DataPtr = currentDataPtr;
                    swapped = true;
                }
            }
            iterNode = iterNode->NextNodePtr;
        }
        if (!swapped)
        {
            break;
        }
    }
    std::cout << "===" << nIterations << "====================================" << std::endl;
    iterNode = rootNode;
    while (iterNode.get() != nullptr)
    {
        std::cout << *(iterNode->DataPtr) << std::endl;
        iterNode = iterNode->NextNodePtr;
    }

    system("pause");
}
