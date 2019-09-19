#ifndef __SLINK__MYSELF__
#define __SLINK__MYSELF__
namespace room1 {
class slink;
struct node;
typedef int ElementType, LENGTH;
typedef struct node *successor, *HEAD;
struct node {
    node(ElementType e = 0, successor ptr = nullptr)
        : el(e)
        , next(ptr) {};
    ElementType el;
    successor next;
};
class slink {
public:
    slink()
        : length(1)
    {
        head = new node; //head -> headNode(no data scope)
    };
    slink(const slink& s)
    {
        length = s.length;
        head = s.head;
    }
    ~slink() { delete head; }
    //options
    int getLen(); //num of nodes in slink
    ElementType* getMin(); //min_value
    ElementType* getMax(); //max_value
    long long getSum(); //summery
    int getMean(); //mean value
    int unshift(); //insert node in the head
    ElementType shift(); //delete node in the head and return it's value
    ElementType getElem(int);
    int locate(ElementType);
    int insertNode(ElementType);
    int deleteNode(ElementType, int);
    void list();

private:
    LENGTH length;
    HEAD head;
    // HEAD ohead;  //it should be a bucket and element will be ordered when insert
};
inline int slink::getLen()
{
    return length;
}
inline ElementType* slink::getMin()
{
    if (1 == length)
        return nullptr; //only headNode(no data scope) hook on slink
    successor current = head->next; //point to first dataNode
    struct { //here also can just use a node* if you wanna save memory.
        successor ins; //record the minimum's ins
        ElementType val; //record the minimum's value
    } min;
    min.val = current->el; //Assuming that the first data node is the minimum
    min.ins = current;
    while (current) {
        if (current->el < min.val) {
            min.val = current->el;
            min.ins = current;
        }
        current = current->next;
    }
    return &min.ins->el;
}
inline ElementType* slink::getMax()
{
    if (1 == length)
        return nullptr;
    auto current = head->next; //test auto /auto*
    auto ins = current;
    ElementType max = current->el;
    while (current) {
        if (max < current->el) {
            max = current->el;
            ins = current;
        }
        current = current->next;
    }
    return &ins->el;
}
inline long long slink::getSum()
{
    if (1 == length)
        return 0;
    auto current = head->next; //point to first datanode
    long long sum = 0;
    while (current) {
        sum += current->el;
        current = current->next;
    }
    return sum;
}
inline int slink::insertNode(ElementType e)
{
    //sort need ohead
    if (1 == length)
        return false;
    auto ptr = head;
    while (ptr->next) {
        ptr = ptr->next;
    }
    successor newNode = new node(e);
    ptr->next = newNode;
    ++length;
    return 1;
}
}

#endif //__SLINK__MYSELF__