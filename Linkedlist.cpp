#include <iostream>

enum {Smaller,Larger,Similar};

//Any class in this linked list must support 2 functions
//show (cout the values) and compare (returns relative position)

class Data
{
public:
    Data(int newVal): value(newVal) {}
    ~Data() {}
    int compare(const Data&);
    void show() {std::cout << value << "\n";}
private:
    int value;
};

//This function decides where in the list a particular object belongs
int Data::compare(const Data& otherData)
{
    if (value < otherData.value)
        return Smaller;
    if (value > otherData.value)
        return Larger;
    else
        return Similar;
}

//An Abstract Data Type representing the node object of the list.
//Every derived class must override insert() and show().
class Node
{
public:
    Node() {}
    virtual ~Node() {}
    virtual Node* insert(Data* data) = 0;
    virtual void show() = 0;
private:
};

// A Node to hold objects of type Data.
class InternalNode : public Node
{
public:
    InternalNode(Data* data, Node* next);
    virtual ~InternalNode() {delete next;delete data;}
    virtual Node* insert (Data* data);
    virtual void show()
    {data->show(); next->show();} //delegate
private:
    Data* data; // points to itself
    Node* next; // points to next node in the linked list
};

//a simple constructor
InternalNode::InternalNode(Data* newData, Node*newNext):
data(newData), next(newNext)
{
}

//A function to store a new object in the list.
//The object is passed through the node which figures out
//where it goes to and inserts it into the list
Node* InternalNode::insert(Data* otherData)
{
int result = data->compare(*otherData);

switch (result)
{
case Similar:           //fall through
case Larger:             //new data comes before me
    {
        InternalNode* dataNode =
            new InternalNode(otherData, this);
            return dataNode;
    }
case Smaller:           //pass to the next node and let it handle it
    next = next->insert(otherData);
    return this;
return this; // to appease the compiler
}
}

// The last node in the list
class TailNode : public Node
{
public:
    TailNode() {}
    virtual ~TailNode() {}
    virtual Node* insert(Data* data);
    virtual void show() {}
private:
};

//If data comes in to me it must be inserted before me
//since nothing goes after the tail
Node* TailNode::insert(Data* data)
{
    InternalNode* dataNode = new InternalNode(data,this);
    return dataNode;
}

//The HeadNote holds no data but points to the beginning of the list
class HeadNode : public Node
{
public:
    HeadNode();
    virtual ~HeadNode() {delete next;}
    virtual Node* insert (Data* data);
    virtual void show() {next->show();}
private:
    Node* next;
};

// The first node in the list which creates the tail

HeadNode::HeadNode()
{
    next = new TailNode;
}

// Since nothing comes before the head, just pass the data to the next node
Node* HeadNode::insert(Data* data)
{
    next = next->insert(data);
    return this;
}

class LinkedList
{
public:
    LinkedList();
    ~LinkedList(){ delete head; }
    void insert(Data* data);
    void showAll() { head->show(); }
private:
    HeadNode* head;
};

// In the front, the HeadNote was created which creates the TailNode
LinkedList::LinkedList()
{
    head = new HeadNode;
}

//Delegate to a HeadNote
void LinkedList::insert(Data* pData)
{
    head->insert (pData);
}

// Main Program
int main()
{
    Data* pData;
    int val;
    LinkedList llist;

    // store user values in a list
    while (true)
    {
        std::cout << "Enter Value (0 to end list)";
        std::cin >> val;
        if (!val)
            break;
        pData = new Data(val);
        llist.insert(pData);
    }
    // displaying list
    llist.showAll();
    return 0;
}
