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
    int order = strcmp(p1->last_name, p2->last_name);

    if (order == 0)
        return strcmp(p1->first_name, p2->first_name);
    
    return order;
}

int double_order(Cell* p1, Cell* p2, int first, int second){
    if(first == 0)
        return second;

    return  first;
}

List ordered_insertion(List l, Cell* new, int order_func(Cell*, Cell*)){
    if(l == NULL){
        return new; 
    }

    if(order_func(new, l) <= 0){
        new->next = l;
        return new;
    }
    else{
        l->next = ordered_insertion(l->next, new, order_func);
    }

    return l;
}

List double_ordered_insertion(List l, Cell* new, int first(Cell*, Cell*), int second(Cell*, Cell*)){
    if(l == NULL){
        return new; 
    }

    if(double_order(new, l, first(new, l), second(new, l)) <= 0){
        new->next = l;
        return new;
    }
    else{
        l->next = double_ordered_insertion(l->next, new, first, second);
    }

    return l;
}

/*List double_ordered_insertion(List l, Cell* new, int first_order_func(Cell*, Cell*), int second_order_func(Cell*, Cell*)){
    if(l == NULL){
        printf("NULL\n");
        return new; 
    }

    if(first_order_func(new, l) == 1){
        printf("l\n");
        new->next = l;
        return new;
    }else if(first_order_func(new, l) == 0){
        while(irst_order_func(new, l) == 0){
            if(second_order_func(new, l) <= 0);
        }
    }
    else{
        l->next = ordered_insertion(l->next, new, order_func);
    }

    return l;
}*/

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