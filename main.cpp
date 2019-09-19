#include "DBS/slink_arr.h"
#include "DBS/stack_arr.h"
#include <iostream>
#include <timer>
using namespace std;
// using namespace room2;
using namespace room3;
int main()
{
    stack stack1(10);
    cout << stack1.getAva() << endl;
    int i = 0;
    while (i++ < 12) {

        stack1.push(i);
    }
    stack stack2 = stack1;
    cout << stack2.getAva() << endl;
    cout << stack2.front() << '\n';
    cout << stack2.getLen() << '\n';
    stack2.list();
    cout << stack1.full() << endl;
}