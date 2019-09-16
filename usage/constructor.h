#ifndef __CONSTRUCTOR__MYSELF__
#define __CONSTRUCTOR__MYSELF__
class example;
class example {
    example() {}; //default constructor
    example(const example& el) {}; //default constructor
    //you can use the operator '.' in this '{}' like 'el.member'
};
#endif //__CONSTRUCTOR__MYSELF__