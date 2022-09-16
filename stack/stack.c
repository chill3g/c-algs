#include "stack.h"

stack_t* create_stack(int size){
    stack_t* st;
    st = (stack_t*)malloc(sizeof(stack_t));
    st->base = (item_t*)malloc(size * sizeof(item_t));
    st->top = st->base;
    st->length = 0;
    st->cap = size;
    return st;
}

void push(stack_t* st, item_t x){
    if (st->top < st->base + st->cap)
    {
        *(st->top) = x;
        st->top++;
        st->length++;
        return;
    }
    printf("push to full stack");
}

item_t pop(stack_t* st){
    if (st->base == st->top)
    {
       printf("stack is empty");
       item_t def = -1;
       return def;
    }
    st->length--;
    st->top--;
    return *(st->top);
}
