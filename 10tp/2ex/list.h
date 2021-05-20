#ifndef LIST_H
#define LIST_H

typedef struct cell{
    char* first_name;
    char* last_name;
    int age;
    struct cell* next;
}Cell, *List;

Cell* create_cell(char* first, char* last, int age);
int age_order(Cell* p1, Cell* p2);
int name_order(Cell* p1, Cell* p2);
List ordered_insertion(List l, Cell* new, int order_func(Cell*, Cell*));
void print_list(List l);
void free_list(List l);

#endif /*LIST_H*/