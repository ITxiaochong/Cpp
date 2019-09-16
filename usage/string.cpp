#include <iostream>
using namespace std;

int main()
{
    string str0 { 'c' };
    char c = 'c';
    // string str1('c');    cannot use single char.
    string str2 = { 'c', '\0', c };
    string str3("c");
    string str4(string { c }); //bad way!dont use!

    cout << str0.size() << endl;
    cout << str2.size() << endl;
    cout << str3.size() << endl;
    cout << str4.size() << endl;
}
