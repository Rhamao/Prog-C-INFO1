#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Cell* create_cell(char* first, char* last, int age){
    Cell *c = (Cell*)malloc(sizeof(Cell));
    c->first_name = (char *)malloc((strlen(first)+1)*sizeof(char));
    c->last_name = (char *)malloc((strlen(last)+1)*sizeof(char));
    strcpy(c->first_name, first);
    strcpy(c->last_name, last);  
    c->age = age;
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

List ordered_insertion(List l, Cell* new, int order_func(Cell*, Cell*)){
    if(l == NULL){
        printf("null\n");
        return new; 
    }

    if(order_func(new, l) == 1 && order_func(new, l->next) <= 0){
        printf("l\n");
        List buff = l->next;
        l->next = new;
        l->next->next = buff;
        return l;
    }
    else{
        printf("next\n");
        l = ordered_insertion(l->next, new, order_func);
    }

    /*if(order_func(new,*l) <= 0){
        List* buff = l;
        *l = (*l)->next;
        *buff = new;
        (*buff)->next = *l;
        printf("%d", (*l)->age);
    }*/

    return l;
}

void print_list(List l){
    while(l!=NULL){
        printf("%s %s %d\n", l->first_name, l->last_name, l->age);
        l = l->next;
    }
    return;
}

void free_list(List l){
    free(l);
    return;
}