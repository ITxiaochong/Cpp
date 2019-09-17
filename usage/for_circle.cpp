#include <iostream>
using namespace std;

int main()
{
    int arr1[10] = { 1 };
    int arr2[10] = { 2 };
    int arr3[10] = { 3 };
    int arr4[10] = { 4 };
    //precedence 'rvalue expression' > 'lvalue expression'
    //1.right operation 'k++' make variable k become k+1,but k++ return a value copy from k's value before changing
    //2.left operation '[k]' get value from varible k after changing.
    //3.mid operation '=' make right inject into left variable
    for (int i = 0; i < 10;) {
        arr1[i] = ++i; //1,1,2,3,4,5,6,7,8,9
    }
    for (int i = 0; i < 10; ++i) {
        cout << arr1[i] << endl;
    }

    cout << "first---------------" << endl;
    // first----------------------------------

    for (int j = 0; j < 10;) {
        arr2[++j] = j; //3,1,2,3,4,5,6,7,8,9
    }
    for (int j = 0; j < 10; ++j) {
        cout << arr2[j] << endl;
    }
    cout << "second---------------" << endl;

    // second----------------------------------

    for (int k = 0; k < 10;) {
        arr3[k] = k++;
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