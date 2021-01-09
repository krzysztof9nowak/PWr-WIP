#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node{
    int value;
    struct node* left;
    struct node* right;
};
typedef struct node Node;
typedef Node *Tree;


void print_prefix(Tree ptr){
    if(ptr == NULL)
        return;
    printf("%d ", ptr->value);
    print_prefix(ptr->left);
    print_prefix(ptr->right);
}

void insert_sorted(Tree *ptr, int val){
    if(*ptr==NULL){
        (*ptr)=malloc(sizeof(Node));
        (*ptr)->value=val;
        (*ptr)->left=NULL;
        (*ptr)->right=NULL;
        return;
    }
    if(val<(*ptr)->value)
        insert_sorted(&((*ptr)->left), val);
    else if(val>(*ptr)->value)
        insert_sorted(&((*ptr)->right), val);
    
    // assert(0); // taka wartosc juz jest w drzewie
}

int count_nodes(Tree tree){
    if(tree == NULL)
        return 0;
    return 1 + count_nodes(tree->left) + count_nodes(tree->right);
}

int count_leafs(Tree tree){
    if(tree==NULL)
        return 0;
    if((tree->left==NULL) && (tree->right==NULL))
        return 1;
    return count_leafs(tree->left) + count_leafs(tree->right);
}

int max(int a, int b){
    if(a>b)
        return a;
    return b;
}

int height(Tree tree){
    if(tree == NULL)
        return 0;
    return 1 + max(height(tree->left), height(tree->left));
}

void remove_tree(Tree *ptr){
    if((*ptr)==NULL)
        return;
    remove_tree(&((*ptr)->left));
    remove_tree(&((*ptr)->right));
    printf("%d ", (*ptr)->value);
    free(*ptr);
    *ptr = NULL;
}

// O(height^2) ?
void remove_brute(Tree *tree){
    Tree *ptr = tree;

    while((*tree) != NULL){
        if((*ptr)->left != NULL){
            ptr = &((*ptr)->left);
            continue;
        }
        if((*ptr)->right != NULL){
            ptr = &((*ptr)->right);
            continue;
        }
        printf("%d ", (*ptr)->value);
        free(*ptr);
        *ptr = NULL;
        ptr = tree;
    }
}

void remove_better(Tree *root){
    exit(1);
    // int depth = 0;
    // Tree *ptr = root;
    // Tree *backtrack[65]; // długość wieksza niz liczba bitów szyny adresowej procesora zalatwia sprawe

    // while((*root) != NULL){
    //     if(*ptr->left != NULL){
    //         backtrack[depth++] = ptr;
    //         (*ptr) = (*ptr)->left;
    //         continue;
    //     }
    //     if((*ptr)->right != NULL){
    //         backtrack[depth++] = ptr;
    //         (*ptr) = (*ptr)->right;
    //         continue;
    //     }
    //     free(*ptr);
    //     *ptr = NULL;
    //     ptr = backtrack[--depth];
    // }
}

int main(){
    Tree root = malloc(sizeof(Node));
    root->value=10;
    root->left=NULL;
    root->right=NULL;
    insert_sorted(&root, 1);
    insert_sorted(&root, 5);
    insert_sorted(&root, 3);
    print_prefix(root); printf("\n");
    printf("nodes: %d\n", count_nodes(root));
    printf("leafs: %d\n", count_leafs(root));
    printf("height: %d\n", height(root));

    printf("removing: ");
    remove_brute(&root); 
    printf("\n");

    return 0;
}