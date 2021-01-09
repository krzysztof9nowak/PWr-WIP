#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct _code{
    int test_number;
    // int elemets[4];
    bool was_checked; 
};

typedef struct _code *Code; 

struct list{
    Code code;
    struct list *tail;
};

typedef struct list *List;

void prepend(List *l, Code c){
    List head = malloc(sizeof(struct list));
    head->code = c;
    head->tail = (*l);
    *l = head; 
}

void pop(List *l){
    List tmp = (*l)->tail;
    free(*l);
    *l = tmp;
}

void generate_all_codes(int dim)

int main(){
    struct _code c1 = {3, false};
    struct _code c2 = {5, true};
    List l = malloc(sizeof(struct list));
    prepend(&l, &c1);
    prepend(&l, &c2);
    printf("%d\n", l->code->test_number);
    pop(&l);
    printf("%d\n", l->code->test_number);
}