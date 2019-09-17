#include "DBS/slink.h"
#include "DBS/slink_arr.h"
#include <iostream>
using namespace std;
using namespace room1;
int main()
{
    struct node {
        int i;
        int* j;
    };
    node a;
    node b = { 1, nullptr };
    a = b;
    cout << a.i << endl;
}