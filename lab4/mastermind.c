#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define code_length 4
#define number_of_colors 6

struct Code{
    int elements[code_length];
};

struct ListNode{
    struct Code *code;
    struct ListNode *next;
};

void print_code(struct Code code){
    for(int i=0; i<code_length; i++){
        printf("%d ", code.elements[i]);
    }
    printf("\n");
}

void list_append(struct ListNode **ptr, struct Code *code){
    while(*ptr != NULL){
        ptr = &((*ptr)->next);
    }
    struct ListNode *new_node = malloc(sizeof(struct ListNode));
    new_node->next = NULL;
    new_node->code = code;
    *ptr = new_node;
}

int list_length(struct ListNode *ptr){
    int length = 0;
    while(ptr != NULL){
        // print_code(*(ptr->code));
        length++;
        ptr = ptr->next;
    }
    return length;
}

void generate_problem_space_recursive(int dim, struct ListNode **ptr, struct Code basecode){
    if(dim == 0){
        struct Code *new_code_on_heap = malloc(sizeof(struct Code));
        memcpy(new_code_on_heap, &basecode, sizeof(struct Code));
        list_append(ptr, new_code_on_heap);
        return;
    }
    for(int i = 1; i <= number_of_colors; i++){
        basecode.elements[code_length - dim] =  i;
        generate_problem_space_recursive(dim - 1, ptr, basecode);
    }
}

struct ListNode *generate_problem_space(int dim){
    struct Code basecode;
    struct ListNode *root = NULL;
    generate_problem_space_recursive(dim, &root, basecode);
    return root;
}

bool verify(struct Code codeA, struct Code codeB, int valid_red, int valid_white){
    if(codeB.elements[0]==1 && codeB.elements[1]==1 && codeB.elements[2]==2 && codeB.elements[3]==1){
        int kek=0;
    }
        
    int red = 0;
    bool used_elementsA[4] = {false};
    bool used_elementsB[4] = {false};
    for(int i=0; i<code_length; i++)
        if(codeA.elements[i] == codeB.elements[i]){
            red++;
            used_elementsA[i] = true;
            used_elementsB[i] = true;
        }
    if(red != valid_red)
        return false;
    
    int white = 0;
    for(int i=0; i<code_length; i++){
        for(int j=0; j<code_length; j++){
            if(!used_elementsA[i] && !used_elementsB[j] && codeA.elements[i] == codeB.elements[j]){
                white++;
                used_elementsA[i] = true;
                used_elementsB[j] = true;
            }
        }
    }

    return white == valid_white;
}


int main(){
    // utwórz listę wszystkich możliwych kodów
    struct ListNode *possibilities_space = generate_problem_space(code_length);
    int turn_counter = 0;

    // główna pętla programu, wykonuje się dopóki pozostały jakiekolwiek możliwe kody
    while(list_length(possibilities_space) > 0){
        // printf("Moc przestrzeni: %d\n", list_length(possibilities_space));
        
        // w pierwszej turze zgadujemy kod 1212, w następnych podaje pierwszy element list
        struct Code guess;
        if(turn_counter == 0){
            guess.elements[0] = 1;
            guess.elements[1] = 2;
            guess.elements[2] = 1;
            guess.elements[3] = 2;
        } else {
            guess = *(possibilities_space->code);
        }
        
        printf("Zgaduję, że kod to: ");
        print_code(guess);
        turn_counter++;
        
        int red, white;
        printf("Twoja odpowiedź: [czerwone] [białe]\n");
        scanf("%d %d", &red, &white);
        if(red < 0 || white < 0 || red + white > 4){
            printf("To nie możliwe!\n");
            return 1;
        }
        if(red == 4){
            printf("Wygrałem w %d turach\n", turn_counter);
            return 0;
        }


        // z listy usuwamy elementy, które nie spełniają warunku zdanego funkcją verify
        struct ListNode **ptr = &possibilities_space;
        struct ListNode *tmp;
        while((*ptr) != NULL){
            struct Code code = *((*ptr)->code);
            bool valid = verify(guess, code, red, white);
            if(!valid){
                tmp = (*ptr)->next;
                free((*ptr)->code);
                free(*ptr);
                *ptr = tmp;
            }
            else
                ptr = &((*ptr)->next);
        }
    }
    printf("Zostałem podle oszukany!\n");
    return 1;
}
