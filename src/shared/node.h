#include <memory>
template <typename T>
class Node
{
  public:
    Node() {}
    Node(std::shared_ptr<T> data)
    {
        DataPtr = data;
    }
    std::shared_ptr<T> DataPtr;
    std::shared_ptr<Node> NextNodePtr;

    void Remove(){
        // NOTE: a previous node may exist  and it is pointing to this.
        // So CLEARLY we can't get rid of this

        // We need to copy what we are pointing to into ourselves, thus becoming what we are pointing to
        auto nextNode = NextNodePtr;  // take a temp pointer to the next node.
        NextNodePtr = nextNode->NextNodePtr;
        DataPtr = nextNode->DataPtr;
    }
    void InsertBefore(std::shared_ptr<T> data)
    {
        // THIS node will become the new data that is being inserted.
        // the real node being inserted is actually this 
        // 1. Copy this nodes data into the new node
        std::shared_ptr<Node> newNode =
            std::make_shared<Node>(DataPtr);
        newNode->NextNodePtr =  NextNodePtr;
        
        // the previous node, if there is one, is pointing to this node
        // so leave the node alone, but change its content.
        DataPtr = data;
        NextNodePtr = newNode;
   }
    void InsertAfter(std::shared_ptr<T> data)
    {
 
        std::shared_ptr<Node> newNode =
            std::make_shared<Node>(data);
        newNode->NextNodePtr = NextNodePtr;
        
        NextNodePtr = newNode;
   }
};