#include <stdio.h>
#include <malloc.h>
#include <string.h>

// test anul trecut subiectul d

typedef struct node{
    char key;
    struct node * left, * right;
}NodeT;

NodeT * create(char key){
    NodeT * p = malloc(sizeof(NodeT));
    p->key=key;
    p->right=NULL;
    p->left=NULL;
}

//void preordine(NodeT** arbore, char string[]) {
//    if (strlen(string) == 0)return;
//    char current = string[0];
//    int i = 0;
//    while (current != '\0') {
//        current = string[i];
//        if (arbore == NULL) {
//            arbore = create(current);
//            i++;
//            continue;
//        }
//        (*arbore)->right = create(string[i]);
//        (*arbore)->left = create(string[i + 1]);
//
//    }
//
//}

//void preordine(NodeT** arbore, char string[]){
//    if(strlen(string)<=0)return;
//    if(strchr("+-*", (*arbore)->key)!=NULL) {
//        if ((*arbore)->left == NULL) {
//            (*arbore)->left = create(string[0]);
//            preordine(arbore, string + 1);
//        } else {
//            (*arbore)->right = create(string[0]);
//            preordine(arbore, string + 2);
//        }
//        return;
//    }
//    if(strchr("+-*", (*arbore)->key)==NULL){
//        if((*arbore)->left==NULL){
//            (*arbore)->left = create(string[0]);
//        }
//        else{
//            (*arbore)->right = create(string[0]);
//        }
//        return;
//    }
//
//}

void insert(NodeT** arbore, char string[]){
    NodeT* list[100];
    int p=0;
    for(int i=0;i<strlen(string);i++){
        if(*arbore==NULL){
            *arbore=create(string[i]);
            list[p]=*arbore;
            continue;
        }
        if(strchr("+-*", string[i])!=NULL){
            NodeT * new = create(string[i]);
            if(list[p]->left==NULL)
                list[p]->left = new;
            else
                list[p]->right = new;
            p++;
            list[p]=new;
            continue;
        }

        if(list[p]->left==NULL)
            list[p]->left = create(string[i]);
        else if(list[p]->right==NULL)
            list[p]->right = create(string[i]);
        else{
            p--;
            if(list[p]->left==NULL){
                list[p]->left = create(string[i]);
            }
            else{
                list[p]->right = create(string[i]);
            }
        }

    }
}

void preOrder(NodeT *root){
    if (root == NULL) { return;}
    printf("%c ", root->key);
    preOrder(root->left);
    preOrder(root->right);
}

int calculate(NodeT* arbore){
    if(arbore==NULL)return 0;
    if(strchr("+-*", arbore->key)==NULL){
        return arbore->key-'0';
    }
    switch (arbore->key) {
        case '+':
            return calculate(arbore->left)+calculate(arbore->right);
        case '-':
            return calculate(arbore->left)-calculate(arbore->right);
        case '*':
            return calculate(arbore->left)*calculate(arbore->right);
    }
    return calculate(arbore->left)+calculate(arbore->right);
}

void afisare_calc(NodeT* arbore, char list[]){
    if(arbore==NULL)return;
    if(strchr("+-*", arbore->key)==NULL){
        printf("\n pe %c aplicam %s", arbore->key, list);
        return;
    }
    list[strlen(list)+1]='\0';
    list[strlen(list)]=arbore->key;
    char aux[100];
    strcpy(aux, list);
    afisare_calc(arbore->left, list);
    strcpy(list, aux);
    afisare_calc(arbore->right, list);
}


int main() {
    char string1[]="+12";
    char string2[]="*+324";
    char string3[]="-9*4-54";
    NodeT * arbore = NULL;
    insert(&arbore, string3);
    preOrder(arbore);
    printf("\n");
    int sum = calculate(arbore);
    printf("Calc: %d", sum);
    char list[100]={};
    afisare_calc(arbore, list);
    return 0;
}
