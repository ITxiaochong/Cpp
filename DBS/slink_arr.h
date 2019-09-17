#ifndef __SLINK__ARR__MYSELF__
#define __SLINK__ARR__MYSELF__
#define MAXSIZE 102 //frozen fixed size
namespace room2 {
class slink;
typedef int ElementType;
struct arr { //stalink node
    ElementType el;
    int cur; //cursor
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

private:
    int length;
    int size;
    stalink S;
    void initialization(stalink space)
    {
        for (int i = 1; i < MAXSIZE - 1;)
            space[i].cur = ++i;
        space[0].cur = 2;
        space[MAXSIZE - 1].cur = 0;
    }
    void copy(const slink& space)
    {
        int i = 0;
        while (i < MAXSIZE) {
            S[i] = space.S[i];  //Aggregate class ,It means the same thing below.
            // S[i].el = space.S[i].el;
            // S[i].cur = space.S[i].cur;
        }
        length = space.length;
    }
};
}
#endif //__SLINK__ARR_MYSELF
