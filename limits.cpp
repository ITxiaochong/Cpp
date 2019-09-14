#include <climits>
#include <iostream>
#include <limits>
using namespace std;

int main()
{
    cout << INT_MIN << endl;
    cout << INT_MAX << endl;

    cout << CHAR_MIN << endl;
    cout << CHAR_MAX << endl;

    cout << numeric_limits<int>::min() << endl;
    cout << numeric_limits<int>::max() << endl;

    cout << 0x7fffffff << endl;
    cout << 0xffffffff << endl;
}
