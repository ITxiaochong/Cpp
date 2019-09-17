#include "DBS/slink.h"
#include "DBS/slink_arr.h"
#include <iostream>
using namespace std;
using namespace room1;
int main()
{
    int arr1[10] = { 0 };
    int arr2[10] = { 0 };
    int arr3[10] = { 0 };
    int arr4[10] = { 0 };
    for (int i = 0; i < 10;) {
        arr1[i] = ++i; //equal arr[i] = i;++i;
    }
    for (int i = 0; i < 10; ++i) {
        cout << arr1[i] << endl;
    }

    // ----------------------------------

    for (int j = 0; j < 10;) {
        arr2[++j] = j;
    }
    for (int j = 0; j < 10; ++j) {
        cout << arr2[j] << endl;
    }

    // ----------------------------------

    for (int k = 0; k < 10;) {
        arr3[k] = k++;
    }
    for (int k = 0; k < 10; ++k) {
        cout << arr3[k] << endl;
    }
}