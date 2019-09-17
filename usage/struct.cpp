#include <iostream>
using namespace std;

// Aggregate class
struct node1 {
    int i;
    int* j;
};
int main()
{
    // Aggregate class
    struct node2 {
        int i;
        int* j;
    };
    struct node1 node1;
    struct node2 node2;
    struct node1 node1_another = { 1, nullptr };
    struct node1 node2_another = { 2, nullptr };
    //out of function
    cout << node1.i << endl; //6422352
    cout << node1.j << endl; //0x401a4
    //in function
    cout << node2.i << endl; //199743924
    cout << node2.j << endl; //0x4019e
    //default
    node1 = node1_another;
    // node2 = node1_another;   //fail to assign because of different type
    cout << node1.i << endl; //1
    cout << node1.j << endl; //0
}