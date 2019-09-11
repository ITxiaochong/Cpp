#ifndef __ARRAY__
#define __ARRAY__
const int a = 5;
int c = a; //neglect top const,top const赋值时被忽略,c仍然是一个变量
constexpr int b = a; //a kind of constexpr expression  ,here it works as the keyword 'const' ,add top const feature
//a kind of constexpr expression,only pass int literal can you view it as index of array
constexpr int integer(int num) { return num; }

int arr[a]; // ok, because 'a' is const_value
int arr2[b];
int arr3['v']; //ok,because char -> int

// int arr4[4.3];//error,double cannot convert to int
// int arr3[c];  //error,because 'b' is not const_value or a int/char literal
int assignment(int i)
{
    int* arr = new int[i];
    //int* ptr = (int*)malloc(sizeof(int) * i);
    // new 相比malloc 会自动调用constructor 而且malloc需要头文件的支持 new 内部是基于malloc,new 可以使用malloc重载
}
#endif
