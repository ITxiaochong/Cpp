#ifndef __ARRAY__
#define __ARRAY__
#include <malloc.h>

// ########################################################
//define, make variables get memory
const int a = 5;
//neglect top const,c -> variable int
int c = a;
//a kind of constexpr expression  ,here it works as the keyword 'const' ,add top const feature
constexpr int b = a;
//a kind of constexpr expression,only pass int literal or const/constexpr can you view it as index of array
constexpr int integer(int num) { return num; }

// ########################################################
int arr[a]; // ok, cosnt int
int arr2[b]; //ok, constexpr int
int arr3['v']; //ok,because char -> int
int arr4[integer(5)]; //ok, constexpr

// int arr5[4.3];//error,double cannot convert to int
// int arr6[c];  //error,not a const value

// ########################################################
//
int assignment(int i)
{
    int* arr = new int[i];
    // 1.'new' compare to 'malloc' constructor will be called
    // 2.'malloc'need <malloc.h> actually. 'operator new' is based on 'malloc',which can be overloaded.
    int* ptr = (int*)malloc(sizeof(int) * i);
}
// ########################################################
#endif
