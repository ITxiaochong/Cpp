"C++ Program Syntax" 

Recently,I've Learning syntax from a book named <<C++ primer 5th>>.
This is my first time to study Cpp.
Now,here I'd like to share some test-case that I do.

```cpp
----------------------------
./tools/timer 
a tool function for getting the run time of code snippets. (for Win user!)
use it to test your algorithems and data structure.
how to use it?in your cpp source if you wanna test your qSort.

#include "timer" 
#include <vector>
...
int main()
{
    vector<int> vec{1,0,6,1,3,9,3,7,1,0};
    timer('A');
        code snippets...
        quickSort(vec);
    timerEnd('A');
}

----------------------------
```

```cpp
Directory Specification


tools--
      |--- timer        //a tool function

usage--
      |--- array.h        //syntax in array
      |--- headfile.txt   //syntax in headfile
      |--- limits.cpp     //syntax in limits
      |--- string.cpp     //syntax in string
      |--- for_circle.cpp //how operator'++' works?
(ElementType == int)      
BDS  --                 //basic data structure and some related operations 
      |--slink.h
      |--dlink.h
      |--link_arr.h     //static linked list implemented with array.
      |--queue.h
      |--deque.h        //two-way linked-list
      |--queue_arr.h    //queue implemented with array
      |--stack.h
      |--stack_arr.h    //stack implemented with array
      |--cross_link.h   // + slink
      |--btree.h  
      |--btree_arr.h    //binary tree implemented with array
      |--heap.h        
      |--heap_arr.h     //heap/pile implemented with array
      |--graph.h
      |--graph_arr.h    //graph implements with array

(ElementType == generic)
ADS  --                 //advanced data structure and some related operations
      |--...            
main.cpp                //to test code , you don't have to download it
```