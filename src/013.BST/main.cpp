/*

*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <cstring>
#include <bitset>
#include <random>
#include <algorithm> // std::for_each
#include <functional>
#include "person.h"
#include "../shared/bst.h"
void BalanceInsertTree(
    std::shared_ptr<BSTNode<int>> rootNode,
    std::vector<std::shared_ptr<int>> &sorted,
    int begin, int end)
{
    if (begin > end)
        return;
    int len = end - begin;

    int mid = begin + len / 2;
    int leftBegin = begin;
    int leftEnd = mid - 1;
    int rightBegin = mid + 1;
    int rightEnd = end;

    std::shared_ptr<int> midVal = sorted[mid];
    rootNode->RecursiveInsert(midVal);

    BalanceInsertTree(rootNode, sorted, leftBegin, leftEnd);
    BalanceInsertTree(rootNode, sorted, rightBegin, rightEnd);
}

std::shared_ptr<BSTNode<int>> BalanceTreeRebuild(
    std::shared_ptr<BSTNode<int>> rootNode)
{
    std::vector<std::shared_ptr<int>> sorted;
    rootNode->SortMostLeft(sorted);
    size_t end = sorted.size();
    size_t mid = end / 2;

    std::shared_ptr<int> midVal = sorted[mid];
    std::shared_ptr<BSTNode<int>> newRoot =
        std::make_shared<BSTNode<int>>(midVal);

    int leftBegin = 0;
    int leftEnd = mid - 1;
    int rightBegin = mid + 1;
    int rightEnd = end - 1;

    BalanceInsertTree(newRoot, sorted, leftBegin, leftEnd);
    BalanceInsertTree(newRoot, sorted, rightBegin, rightEnd);
    return newRoot;
}

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

    std::vector<std::shared_ptr<int>> sorted;
    rootNode->SortMostLeft(sorted);
    std::for_each(sorted.begin(), sorted.end(), myfunction);
    std::cout << std::endl;

    sorted.clear();

    rootNode->SortMostRight(sorted);
    std::for_each(sorted.begin(), sorted.end(), myfunction);

    std::shared_ptr<int> foundPtr = rootNode->FindData(50);
    int found = *foundPtr;

    foundPtr = rootNode->FindData(50000);
    
    sorted.clear();
    std::cout << std::endl;
    std::cout << std::endl;
    std::shared_ptr<BSTNode<int>> newRootNode = BalanceTreeRebuild(rootNode);
    newRootNode->SortMostLeft(sorted);
    std::cout << std::endl;
    std::for_each(sorted.begin(), sorted.end(), myfunction);
    std::cout << std::endl;

    system("pause");
}
