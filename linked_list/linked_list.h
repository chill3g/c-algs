#ifndef LINKED_LIST
#define LINKED_list

#ifndef STD_H
#include "std.h"
#endif // STD_H

typedef struct list {
    item_t item;
    struct list* next;
} list;

static list* create_list(item_t x);
static void insert_to_head(list** l,item_t x);
static void inset_to_bottom(list* l, item_t x);
static list* find_item(list* l,item_t x);
static list* find_predecessor_node(list* l, item_t x);
static void delete_node(list** l,item_t x);
static void print_all_nodes(list* l);

#endif // LINKED_LIST
