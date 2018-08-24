#include <iostream>
#include <list>
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
    void SortMostLeft(std::list<std::shared_ptr<T>> &sorted)
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
                    LeftNodePtr = std::make_shared<BSTNode>(data);
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
                    RightNodePtr = std::make_shared<BSTNode>(data);
                    RightNodePtr->pParentNode = this;
                }
                else
                {
                    RightNodePtr->RecursiveInsert(data);
                }
            }
        }
    }
};