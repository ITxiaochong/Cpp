#ifndef __SLINK__ARR__MYSELF__
#define __SLINK__ARR__MYSELF__
#define MAXSIZE 102 //frozen fixed size
namespace room2 {
class slink;
typedef int ElementType, pos;
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
    {
        initialization(S);
    }
    slink(const slink& space)
        : size(MAXSIZE)
    {
        copy(space);
    }
    //options
    pos allocnode();
    int freenode(pos); //success:1 fail:0
    //default delete the first match,if second param == true,delete all matches.
    int remove(ElementType, bool);
    int insert(ElementType, pos, bool);
    pos find(ElementType);
    int updateByIndex(ElementType, pos);
    void findMin(ElementType*);
    void findMax(ElementType*);
    void list();
    // void Json() {};  //return some reference to origin

private:
    int length;
    int size;
    stalink S;
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
            S[i] = space.S[i]; //Aggregate class ,It means the same thing below.
            ++i;
        }
        length = space.length;
    }
};
inline pos slink::allocnode()
{
    if (S[0].cur || length == size - 2)
        return 0;
    pos temp = S[0].cur;
    S[0].cur = S[temp].cur;
    return temp;
}
inline int slink::freenode(pos ins)
{
    if (!length)
        return 0;
    S[ins].cur = S[0].cur;
    S[0].cur = ins;
    return 1;
}
inline int slink::remove(ElementType e, bool flag = false)
{
    return 0;
}
//default push_back, range of ins in [-1,length]
// Where "-1" means the end and "0" means the beginning
// third param 'aORb' use to choose to insert before or after
inline int slink::insert(ElementType e, pos ins = -1, bool aORb = false)
{
    //'if aORb == true' traverse times minus one
    if (ins - aORb > length || ins < -1)
        return 0; //fail to insert
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
        return 0;
    while (i++ < ins) //0(i) < ins - aORb
        ptr = S[ptr].cur; // find precursor
    S[m].cur = S[ptr].cur;
    S[ptr].cur = m;
    return 1; //successfully insert
}
inline pos slink::find(ElementType e)
{
    return 0;
}
//second param get from 'pos find(ElementType e);'
inline int slink::updateByIndex(ElementType e, pos ins)
{
    return 0;
}
inline void slink::findMin(ElementType* e)
{
}
inline void slink::findMax(ElementType* e)
{
}
inline void slink::list()
{
}
}
#endif //__SLINK__ARR_MYSELF
