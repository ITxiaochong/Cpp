#ifndef __SLINK__ARR__MYSELF__
#define __SLINK__ARR__MYSELF__
#define MAXSIZE 102 //frozen fixed size
#define BOUNDARY_VALUE 2147483647
#include <iostream>
namespace room2 {
class slink;
typedef int ElementType, pos;
//The cursor value 0 represents the end node of the list
//or standby nodes are exhausted
struct arr { //stalink node
    ElementType el;
    pos cur; //cursor
};
enum Flag {
    HEAD,
    COUNT,
    END
};
typedef struct arr stalink[MAXSIZE];
class slink {
public:
    slink(int val = MAXSIZE)
        : length(0)
        , size(val + 2)
        , boundary_value(BOUNDARY_VALUE)
    {
        initialization(S);
    }
    slink(slink& space)
        : boundary_value(BOUNDARY_VALUE)
    {
        copy(this, space);
    }
    //options
    pos allocnode();
    bool freenode(pos);
    //default delete the first match,if second param == true,delete all matches.
    pos find(ElementType, Flag) const; //Logically returned subscripts
    bool remove(ElementType, bool);
    bool insert(ElementType, pos, bool);
    pos findIndex(ElementType) const; //actual subscripts
    bool updateByIndex(ElementType, pos);
    ElementType findMin() const;
    ElementType findMax() const;
    void list() const;
    //operator overload
    ElementType& operator[](int i)
    {
        //out of boundary or slink not exists
        if (0 == length || i > length - 1 || i < 0)
            return boundary_value;
        pos ptr = S[1].cur; //first datanode slink[0]
        while (i-- && ptr) {
            ptr = S[ptr].cur;
        }
        return S[ptr].el; //optimistically return
    }
    const slink& operator=(const slink& link)
    {
        copy(this, link);
        return *this;
    }
    int getLen() const
    {
        return length;
    }
    int getCapacity() const
    {
        return size - 2;
    }
    // void Json() {};  //return some reference to origin

private:
    int length;
    int size;
    stalink S;
    ElementType boundary_value;
    void initialization(stalink space)
    {
        for (int i = 2; i < size - 1; ++i)
            space[i].cur = i + 1;
        //if space[1].cur = 1 ==> space be a circular linked list
        space[1].cur = 0; //default not a circular linked list
        space[0].cur = 2;
        space[size - 1].cur = 0;
    }
    void copy(slink* ths, const slink& space)
    {
        ths->length = space.length;
        ths->size = space.size;
        int i = 0;
        while (i < ths->size) {
            // S[i++] = space.S[i]; //Aggregate class ,It means the same thing below.
            ths->S[i].el = space.S[i].el;
            ths->S[i].cur = space.S[i].cur;
            ++i;
        }
    }
};
inline pos slink::allocnode()
{
    pos temp = S[0].cur;
    if (0 == temp || length == size - 2)
        return 0;
    S[0].cur = S[temp].cur;
    return temp;
}
inline bool slink::freenode(pos ins)
{
    if (0 == length)
        return false;
    S[ins].cur = S[0].cur;
    S[0].cur = ins;
    return true;
}
inline bool slink::remove(ElementType e, bool flag = false)
{
    if (0 == length)
        return false;
    pos pre = 1; //precursor of the first datanode
    pos ptr = S[1].cur; //get first datanode's ins
    bool has = false;
    if (flag) { //second param 'flag == true' ,function will remove all of matches
        while (ptr) {
            if (e == S[ptr].el) {
                S[pre].cur = S[ptr].cur; //make the successor of precursor be the precursor of successor
                freenode(ptr);
                ptr = S[pre].cur;
                has = true; //Set a tag 'has' that has been found
                --length;
                continue;
            }
            pre = ptr;
            ptr = S[ptr].cur;
        }
    } else {
        while (ptr) {
            if (e == S[ptr].el) {
                S[pre].cur = S[ptr].cur; //make the successor of precursor be the precursor of successor
                freenode(ptr);
                ptr = S[pre].cur;
                has = true; //Set a tag 'has' that has been found
                --length;
                break;
            }
            pre = ptr;
            ptr = S[ptr].cur;
        }
    }
    return has;
}
//default push_back, range of ins in [-1,length]
// Where "-1" means the end and "0" means the beginning
// third param 'aORb' use to choose to insert before or after
inline bool slink::insert(ElementType e, pos ins = -1, bool aORb = false)
{
    //'if aORb == true' traverse times minus one
    if (ins - aORb > length || ins < -1)
        return false; //fail to insert
    if (ins == -1)
        return insert(e, length);
    if (ins == 0)
        return insert(e, 1, true);
    pos ptr = 1; //the head node
    // and we need to traverse (ins - aORb) maybe you should think about it few seconds.
    // Draw a graph to observe traversal behavior similar to skipping the connections between nodes
    // for example:params:(e,3,false)
    //          HEAD -- N1 -- N2 -- N3 -- N4 -- N5 -- ... -- NULL
    // (default)↑   (1) ↑ (2) ↑
    // Obviously we jumped twice and reached the third node.
    // Here params tell us use condition 1.
    // 1. get N3 if we want to insert behind N3. (√)
    // 2. get N2(N3's precursor) if we want to insert before N3
    int i = 0 + aORb; //left boundary add 1, traverse times minus one
    pos m = allocnode(); //      ↓
    if (m == 0)
        return false;
    while (i++ < ins) //0(i) < ins - aORb
        ptr = S[ptr].cur; // find precursor
    S[m].el = e;
    S[m].cur = S[ptr].cur;
    S[ptr].cur = m;
    ++length; //record value of variable 'length' + 1
    return true; //successfully insert
}
inline pos slink::find(ElementType e, Flag flag = HEAD) const
{
    if (0 == length)
        return -1; //no element
    pos ptr = S[1].cur, ins = -1; //first datanode
    if (COUNT == flag) {
        int count = 0;
        while (ptr) {
            ++ins;
            if (e == S[ptr].el)
                ++count; //count the nums of matches
            ptr = S[ptr].cur;
        }
        return count;
    } else if (HEAD == flag) {
        while (ptr) {
            ++ins; //first datanode slink[ins == 0]
            if (e == S[ptr].el)
                return ins;
            ptr = S[ptr].cur;
        }
    } else {
        int tmp = -1;
        while (ptr) {
            ++ins; //first datanode slink[ins == 0]
            if (e == S[ptr].el)
                tmp = ins;
            ptr = S[ptr].cur;
        }
        return tmp;
    }

    return -1; //no match!
}
inline pos slink::findIndex(ElementType e) const
{
    if (0 == length)
        return 0;
    pos ptr = S[1].cur; //the first data node's ins
    bool flag = true; //default running code
    while (flag && ptr) {
        if (e == S[ptr].el) {
            flag = false; //shut down traversing and return pos
            return ptr;
        }
        ptr = S[ptr].cur;
    }
    return 0;
}
//second param get from 'pos find(ElementType e);'
inline bool slink::updateByIndex(ElementType e, pos ins)
{
    if (0 == length)
        return false; //node not exists.
    if (2 > ins || ins > size - 1)
        return false; //out of boundary
    S[ins].el = e;
    return true;
}
inline ElementType slink::findMin() const
{
    if (0 == length)
        return false;
    pos ptr = S[1].cur;
    ElementType min = S[ptr].el;
    ptr = S[ptr].cur;
    while (ptr) {
        if (min > S[ptr].el) {
            min = S[ptr].el;
        }
        ptr = S[ptr].cur;
    }
    return min;
}
inline ElementType slink::findMax() const
{
    if (0 == length)
        return false;
    pos ptr = S[1].cur;
    ElementType max = S[ptr].el;
    ptr = S[ptr].cur;
    while (ptr) {
        if (max < S[ptr].el) {
            max = S[ptr].el;
        }
        ptr = S[ptr].cur;
    }
    return max;
}
inline void slink::list() const
{
    if (0 == length) {
        std::cout << "[" << ']' << std::endl;
        return;
    }
    pos ptr = S[1].cur;
    std::cout << "[";
    int len = length;
    while (--len && ptr) {
        std::cout << S[ptr].el << ", ";
        ptr = S[ptr].cur;
    }
    if (ptr > 1) { //ptr pointer to datanode
        std::cout << S[ptr].el;
    }
    std::cout << "]" << std::endl;
}
}
#endif //__SLINK__ARR_MYSELF
