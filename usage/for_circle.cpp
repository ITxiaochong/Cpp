#include <iostream>
using namespace std;

int main()
{
    int arr[10] = { 0 };
    for (int i = 0; i < 10; ++i) {
        arr[i] = i;
    }
    for (int i = 0; i < 10;) {
        arr[i] = ++i;//++i ,here not create a temp value
    }
}