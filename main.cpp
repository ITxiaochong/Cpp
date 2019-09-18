// #include "DBS/slink.h"
#include "DBS/slink_arr.h"
#include <iostream>
#include <timer>
using namespace std;
using namespace room2;
int main()
{
    slink slink1(10);
    slink slink3(5);
    for (int i = 0; i < 5; i++)
        slink1.insert(i);
    slink slink2(slink1);
    // cout << slink2[0] << endl;
    slink1.remove(1);
    slink1.insert(1, 1);
    slink1.list();
    // cout << slink[2] << endl;
    // cout << slink.find(2, HEAD) << endl;
    // cout << slink.findMin() << endl;
    // cout << slink.findMax() << endl;
    // cout << slink.findMax() << endl;
}