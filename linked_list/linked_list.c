#include "linked_list.h"

list* create_list(item_t x){
    list* p;
    p = (list*) malloc(sizeof(list));
    p->item = x;
    p->next = NULL;
    return p;
}

void insert_to_head(list** l, item_t x){
    list* p;
    p= (list*)malloc(sizeof(list));
    p->item = x;
    p->next = *l;
    *l = p;
}

void insert_to_bottom(list* l,item_t x){
    list* p;
    list* current;
    current = l;
    p = (list*)malloc(sizeof(list));
    p->item = x;
    p->next = NULL;
    for(;;){
        if (current->next == NULL)
        {
            current->next = p;
            return;
        }
        current = current->next;
    }
}

list* find_item(list* l,item_t x){
    if (l==NULL)
    {
        return NULL;
    }
    if (l->item == x)
    {
        return l;
    }
    return find_item(l->next,x);
}

list* find_predecessor_node(list* l, item_t x){
    if (l== NULL || l->next == NULL)
    {
        return NULL;
    }
    if (l->next->item == x)
    {
        return l;
    }
    return (predecessor_list(l->next,x));
}

void delete_node(list** l, item_t x){
    list* p;
    list* pred;
    p = find_item(*l,x);
    if (p!=NULL)
    {
        pred= predecessor_list(*l,x);
        // check if about to be deleted item is head
        if (pred == NULL)
        {
            *l = p->next;
        }else{
            pred->next = p->next;
        }
        free(p);
    }
}

void print_all_nodes(list* l){
    list* current = l;
    for(;;){
        printf("%d\n",current->item);
        if (current->next == NULL)
        {
            return;
        }
        current = current->next;
    }
}
