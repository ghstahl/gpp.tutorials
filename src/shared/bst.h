#include <iostream>
#include <vector>
#include <iterator>
#include <memory>

template <typename T>
class DataContainer
{
  public:
    DataContainer()
    {
        Count = 0;
    }
    DataContainer(std::shared_ptr<T> dataPtr)
    {
        DataPtr = dataPtr;
        Count = 1;
    }
    std::shared_ptr<T> DataPtr;
    int Count;
};

template <typename T>
class BSTNode
{
  private:
    int _duplicates = 0;
    void IncrementDuplicates()
    {
        ++_duplicates;
    }
    void safePushBack(std::vector<DataContainer<T>> &sorted, DataContainer<T> dataContainer, int spreadDuplicates = true)
    {
        if (!spreadDuplicates)
        {
            for (int i = 0; i < GetDuplicates(); ++i)
            {
                ++dataContainer.Count;
            }
        }
        sorted.push_back(dataContainer);
        if (spreadDuplicates)
        {
            for (int i = 0; i < GetDuplicates(); ++i)
            {
                DataContainer<T> dataContainer(DataPtr);
                sorted.push_back(dataContainer);
            }
        }
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

    void SortMostLeft(std::vector<DataContainer<T>> &sorted, int spreadDuplicates = true)
    {
        if (LeftNodePtr.get() == nullptr)
        {
            DataContainer<T> dataContainer(DataPtr);
            safePushBack(sorted, dataContainer, spreadDuplicates);
        }
        else
        {
            LeftNodePtr->SortMostLeft(sorted, spreadDuplicates);
            DataContainer<T> dataContainer(DataPtr);
            safePushBack(sorted, dataContainer, spreadDuplicates);
        }
        if (RightNodePtr.get() != nullptr)
        {
            RightNodePtr->SortMostLeft(sorted, spreadDuplicates);
        }
    }
    void SortMostRight(std::vector<DataContainer<T>> &sorted, int spreadDuplicates = true)
    {
        if (RightNodePtr.get() == nullptr)
        {
            DataContainer<T> dataContainer(DataPtr);
            safePushBack(sorted, dataContainer, spreadDuplicates);
        }
        else
        {
            RightNodePtr->SortMostRight(sorted, spreadDuplicates);
            DataContainer<T> dataContainer(DataPtr);
            safePushBack(sorted, dataContainer, spreadDuplicates);
        }
        if (LeftNodePtr.get() != nullptr)
        {
            LeftNodePtr->SortMostRight(sorted, spreadDuplicates);
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
        std::vector<DataContainer<int>> &sorted,
        int begin, int end)
    {
        if (begin > end)
        {
            return;
        }
        int len = end - begin;

        int mid = begin + len / 2;
        int leftBegin = begin;
        int leftEnd = mid - 1;
        int rightBegin = mid + 1;
        int rightEnd = end;

        std::shared_ptr<int> midVal = sorted[mid].DataPtr;
        rootNode->RecursiveInsert(midVal);

        BalanceInsertTree(rootNode, sorted, leftBegin, leftEnd);
        BalanceInsertTree(rootNode, sorted, rightBegin, rightEnd);
    }

  public:
    static std::shared_ptr<BSTNode<int>> BalanceTreeRebuild(
        std::shared_ptr<BSTNode<int>> originalRootNode)
    {
        std::vector<DataContainer<int>> sorted;
        originalRootNode->SortMostLeft(sorted);
        size_t end = sorted.size();
        size_t mid = end / 2;

        std::shared_ptr<int> midVal = sorted[mid].DataPtr;
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