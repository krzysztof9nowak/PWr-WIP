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
        length++;
        ptr = ptr->next;
    }
    return length;
}

void generate_problem_space_recursive(int dim, struct ListNode **ptr, struct Code basecode){
    if(dim == 0){
        struct Code *newcode_heap = malloc(sizeof(struct Code));
        memcpy(newcode_heap, &basecode, sizeof(struct Code));
        list_append(ptr, newcode_heap);
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
    int red = 0;
    bool used_elements[4] = {false};
    for(int i=0; i<code_length; i++)
        if(codeA.elements[i] == codeB.elements[i]){
            red++;
            used_elements[i] = true;
        }
    if(red != valid_red)
        return false;
    
    int white = 0;
    for(int i=0; i<code_length; i++){
        for(int j=0; j<code_length; j++){
            if(!used_elements[i] && !used_elements[j] && codeA.elements[i] == codeB.elements[j]){
                white++;
                used_elements[i] = true;
            }
        }
    }

    return white == valid_white;
}


int main(){
    struct ListNode *problemspace = generate_problem_space(code_length);
    int turn_counter = 0;
    while(list_length(problemspace) > 0){
        // printf("Moc przestrzeni: %d\n", list_length(problemspace));
        struct Code guess = *(problemspace->code);
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


        struct ListNode **ptr = &problemspace;
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
