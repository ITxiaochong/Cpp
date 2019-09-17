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
typedef struct arr stalink[MAXSIZE];
class slink {
public:
    slink()
        : length(0)
        , size(MAXSIZE)
        , boundary_value(BOUNDARY_VALUE)
    {
        initialization(S);
    }
    slink(const slink& space)
        : size(MAXSIZE)
        , boundary_value(BOUNDARY_VALUE)
    {
        copy(space);
    }
    //options
    pos allocnode();
    bool freenode(pos);
    //default delete the first match,if second param == true,delete all matches.
    bool remove(ElementType, bool);
    bool insert(ElementType, pos, bool);
    pos find(ElementType);
    bool updateByIndex(ElementType, pos);
    bool findMin(ElementType*);
    bool findMax(ElementType*);
    void list();
    //operator overload
    ElementType& operator[](int i)
    {
        //out of boundary or slink not exists
        if (0 == length || i > length - 1 || i < 0)
            return boundary_value;
        pos ptr = S[1].cur;
        while (--i && ptr) {
            ptr = S[ptr].cur;
        }
        if (0 == i)
            return S[ptr].el;
        return boundary_value;
    }
    const slink& operator=(slink& link)
    {
        copy(link);
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
        for (int i = 1; i < MAXSIZE - 1; ++i)
            space[i].cur = i + 1;
        space[0].cur = 2;
        space[MAXSIZE - 1].cur = 0;
    }
    void copy(const slink& space)
    {
        int i = 0;
        while (i < MAXSIZE) {
            S[i++] = space.S[i]; //Aggregate class ,It means the same thing below.
        }
        length = space.length;
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
    pos has = false;
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
inline pos slink::find(ElementType e)
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
        ++ptr;
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
inline bool slink::findMin(ElementType* e)
{
    if (0 == length)
        return false;
    pos ptr = S[1].cur;
    *e = S[ptr].el;
    ptr = S[ptr].cur;
    while (ptr) {
        if (*e > S[ptr].el) {
            *e = S[ptr].el;
        }
        ptr = S[ptr].cur;
    }
    return true;
}
inline bool slink::findMax(ElementType* e)
{
    if (0 == length)
        return false;
    pos ptr = S[1].cur;
    *e = S[ptr].el;
    ptr = S[ptr].cur;
    while (ptr) {
        if (*e < S[ptr].el) {
            *e = S[ptr].el;
        }
        ptr = S[ptr].cur;
    }
    return true;
}
inline void slink::list()
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
