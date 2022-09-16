#include "array.h"

array_t* create_array(int size){
    array_t* arr;
    arr = (array_t*)malloc(sizeof(array_t));
    arr->base = (item_t*)malloc(size * sizeof(item_t));
    arr->length = 0;
    arr->cap = size;
    arr->copy = NULL;
    return arr;
}

void push(item_t x, array_t* arr){
    *(arr->base + arr->length) = x;
    arr->length++;
    if (arr->copy != NULL || arr->length >= .75 * arr->cap)
    {
        int additional_copies = 4;
        if (arr->copy == NULL)
        {
            arr->copy = (item_t*)malloc(2 * arr->cap * sizeof(item_t));
        }
        for(;;){
            if (additional_copies>0 && arr->copy_len < arr->length)
            {
                *(arr->copy + arr->copy_len)= *(arr->base +arr->copy_len);
                arr->copy_len++;
                additional_copies--;
            }else{
                break;
            }
        }
        if (arr->length == arr->copy_len)
        {
            free(arr->base);
            arr->base = arr->copy;
            arr->copy = NULL;
            arr->cap *=2;
            arr->copy_len = 0;
        }
        
    }
    
}

item_t pop(array_t* arr){
    if (arr->length == 0)
    {
        return -111;
    }
    item_t tmp = *(arr->base+arr->length);
    arr->length--;
    if (arr->length == arr->copy_len)
    {
        free(arr->base);
        arr->base = arr->copy;
        arr->copy_len =0;
        arr->cap *=2;
        arr->copy = NULL;
    }
    return tmp;
}
