#ifndef ARRAY
#define ARRAY

#include "std.h"

typedef struct {
    item_t* base;
    int length;
    int cap;
    item_t* copy;
    int copy_len;
} array_t;

array_t* create_array(int size);
void push(item_t x, array_t arr);
item_t pop(array_t* arr);

#endif
