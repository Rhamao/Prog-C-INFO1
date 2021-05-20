#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Cell* allocate_cell(char* first, char* last, int age){
    Cell *c = (Cell*)malloc(sizeof(Cell));
    c->first_name = (char*) sizeof(first);
    c->last_name = (char*) sizeof(last);
    c->age = 0;
    c->next = NULL;
    return c;
}
int age_order(Cell* p1, Cell* p2){
    int order;
    order = p1->age < p2->age ? -1 : 1;
    order = p1->age == p2->age ? 0 : order;
    return  order;
}

int name_order(Cell* p1, Cell* p2){
    int buff = strcmp(p1->last_name, p2->last_name);
    if (buff == 0)
        return strcmp(p1->first_name, p2->first_name);
    else
        return buff;
}
void ordered_insertion(List* l, Cell* new, int order_func(Cell*, Cell*)){
    if((*l)->  == NULL)
        return NULL;
    return;
}
void print_list(List l){return;}

void free_list(List l){
    free(l);
    return;
}