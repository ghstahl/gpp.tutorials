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
};