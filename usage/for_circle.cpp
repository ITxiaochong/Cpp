#include <iostream>
using namespace std;

int main()
{
    int arr1[10] = { 1 };
    int arr2[10] = { 2 };
    int arr3[10] = { 3 };
    int arr4[10] = { 4 };
    //precedence 'lvalue expression' > 'rvalue expression'
    //'k++' or '++k' be an independent  arithmetic unit
    //'k++' will be replaced the copy value of origin k
    //'++k' will be replaced "itseleves + 1"
    for (int i = 0; i < 10;) {
        arr1[i] = ++i; //1,1,2,3,4,5,6,7,8,9
    }
    for (int i = 0; i < 10; ++i) {
        cout << arr1[i] << endl;
    }

    cout << "first---------------" << endl;
    // first----------------------------------

    for (int j = 0; j < 10;) {
        arr2[++j] = j; //2,1,2,3,4,5,6,7,8,9
    }
    for (int j = 0; j < 10; ++j) {
        cout << arr2[j] << endl;
    }
    cout << "second---------------" << endl;

    // second----------------------------------

    for (int k = 0; k < 10;) {
        arr3[k] = k++; //3,0,1,2,3,4,5,6,7,8
    }
    for (int k = 0; k < 10; ++k) {
        cout << arr3[k] << endl;
    }
    cout << "third---------------" << endl;

    // third----------------------------------
    for (int l = 0; l < 10;) {
        arr4[l++] = l; //1,2,3,4,5,6,7,8,9,10
        // gradually similar to 'while(l++ < 10) arr4[l] = l;'
    }
    for (int l = 0; l < 10; ++l) {
        cout << arr4[l] << endl;
    }
    cout << "fourth---------------" << endl;
}