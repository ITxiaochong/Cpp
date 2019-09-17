// #include "DBS/slink.h"
#include "DBS/slink_arr.h"
#include <iostream>
#include <timer>
using namespace std;
using namespace room2;
int main()
{
    timer(0);
    timer(1);
    slink slink;
    int i = 0;
    while (++i < 102) {
        slink.insert(i);
    }
    // cout << slink.getLen() << endl;
    // slink.remove(7, true);
    timerEnd(1);
    timer(2);
    slink.list();
    timerEnd(2);
    timerEnd(0);
}