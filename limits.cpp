#include <climits>
#include <iostream>
#include <limits>
using namespace std;

int main()
{
    cout << INT_MIN << endl; //-2147483648
    cout << INT_MAX << endl; //2147483647

    cout << CHAR_MIN << endl; //-128
    cout << CHAR_MAX << endl; //127

    cout << numeric_limits<int>::min() << endl; //-2147483648
    cout << numeric_limits<int>::max() << endl; //2147483647

    cout << numeric_limits<unsigned>::min() << endl; //0
    cout << numeric_limits<unsigned>::max() << endl; //4294967295

    cout << 0x7fffffff << endl; //2147483647
    cout << 0x80000000 << endl; //-2147483648(int) 2147483648(unsigned)
    cout << 0xffffffff << endl; //4294967295(unsigned) -2147483647(int)

    cout << "Program default print unsigned decimal" << endl;
    cout << "Program Special Processing of Boundary Values of Signed Numbers" << endl;
    cout << "view -0 as -2147483648 in signed numer" << endl;
    cout << "view -0 as 2147483648 in unsigned numer" << endl;
}
