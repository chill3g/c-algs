#ifndef STACK
#define STACK
#include "std.h"

typedef struct{
    item_t* base;
    item_t* top;
    int length;
    int cap;
}stack_t;

void push(stack_t* st,item_t x);
item_t pop(stack_t* st);
bool is_empty(stack_t* st);

#endif
