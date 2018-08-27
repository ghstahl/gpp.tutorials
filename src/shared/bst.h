#include <iostream>
#include <vector>
#include <iterator>
#include <memory>

template <typename T>
class BSTNode
{
  private:
    int _duplicates = 0;
    void IncrementDuplicates()
    {
        _duplicates++;
    }

  public:
    BSTNode() {}
    ~BSTNode() {}
    BSTNode(std::shared_ptr<T> data)
    {
        DataPtr = data;
        pParentNode = nullptr;
    }
    std::shared_ptr<T> DataPtr;
    BSTNode *pParentNode;
    std::shared_ptr<BSTNode> LeftNodePtr;
    std::shared_ptr<BSTNode> RightNodePtr;

    int GetDuplicates()
    {
        return _duplicates;
    }
    void SortMostLeft(std::vector<std::shared_ptr<T>> &sorted)
    {
        if (LeftNodePtr.get() == nullptr)
        {
            sorted.push_back(DataPtr);
            for (int i = 0; i < GetDuplicates(); ++i)
            {
                sorted.push_back(DataPtr);
            }
        }
        else
        {
            LeftNodePtr->SortMostLeft(sorted);
            sorted.push_back(DataPtr);
            for (int i = 0; i < GetDuplicates(); ++i)
            {
                sorted.push_back(DataPtr);
            }
        }
        if (RightNodePtr.get() != nullptr)
        {
            RightNodePtr->SortMostLeft(sorted);
        }
    }
    void SortMostRight(std::vector<std::shared_ptr<T>> &sorted)
    {
        if (RightNodePtr.get() == nullptr)
        {
            sorted.push_back(DataPtr);
            for (int i = 0; i < GetDuplicates(); ++i)
            {
                sorted.push_back(DataPtr);
            }
        }
        else
        {
            RightNodePtr->SortMostRight(sorted);
            sorted.push_back(DataPtr);
            for (int i = 0; i < GetDuplicates(); ++i)
            {
                sorted.push_back(DataPtr);
            }
        }
        if (LeftNodePtr.get() != nullptr)
        {
            LeftNodePtr->SortMostRight(sorted);
        }
    }
    std::shared_ptr<T> FindData(T data)
    {
        T incomming = data;
        T current = *(DataPtr);

        if (incomming == current)
        {
            return DataPtr;
        }
        else
        {
            if (incomming < current)
            {
                // go left
                if (LeftNodePtr.get() == nullptr)
                {
                    return nullptr;
                }
                else
                {
                    return LeftNodePtr->FindData(data);
                }
            }
            else
            {
                // go right
                if (RightNodePtr.get() == nullptr)
                {

                    return nullptr;
                }
                else
                {
                    return RightNodePtr->FindData(data);
                }
            }
        }
    }
    void RecursiveInsert(std::shared_ptr<T> data)
    {
        T incomming = *(data);
        T current = *(DataPtr);

        if (incomming == current)
        {
            IncrementDuplicates();
        }
        else
        {
            if (incomming < current)
            {
                // go left
                if (LeftNodePtr.get() == nullptr)
                {
                    LeftNodePtr = std::make_shared<BSTNode<T>>(data);
                    LeftNodePtr->pParentNode = this;
                }
                else
                {
                    LeftNodePtr->RecursiveInsert(data);
                }
            }
            else
            {
                // go right
                if (RightNodePtr.get() == nullptr)
                {
                    RightNodePtr = std::make_shared<BSTNode<T>>(data);
                    RightNodePtr->pParentNode = this;
                }
                else
                {
                    RightNodePtr->RecursiveInsert(data);
                }
            }
        }
    }

  private:
    static void BalanceInsertTree(
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

  public:
    static std::shared_ptr<BSTNode<int>> BalanceTreeRebuild(
        std::shared_ptr<BSTNode<int>> originalRootNode)
    {
        std::vector<std::shared_ptr<int>> sorted;
        originalRootNode->SortMostLeft(sorted);
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
};