#include <stdio.h>
#include <malloc.h>
#include <string.h>
//ex 12 lab 5

typedef struct node{
    char key[100];
    struct node *left, *right;
}NodeT;

NodeT* create(char key[]){
    NodeT * p = malloc(sizeof(NodeT));
    p->left=NULL;
    p->right=NULL;
    strcpy(p->key, key);
    return p;
}

void insertNode(NodeT ** root, char key[]){
    if((*root)==NULL){
        NodeT* p = create(key);
        *root = p;
        return;
    }
    if(strcmp((*root)->key, key)<=0){
        if((*root)->left==NULL){
            NodeT* p = create(key);
            (*root)->left = p;
            return;
        }
        insertNode(&((*root)->left), key);
        return;
    }
    if((*root)->right==NULL){
        NodeT* p = create(key);
        (*root)->right = p;
        return;
    }
    insertNode(&((*root)->right), key);
    return;
}

void preOrder(NodeT *root){
    if (root == NULL) { printf("# "); return;}
    printf("%s ", root->key);
    preOrder(root->left);
    preOrder(root->right);

}

int main() {
    FILE * in = fopen("fiser.txt", "r");
    NodeT * root = NULL;
    char string[100]= {'\0'};
    while(strcmp(string, "end")!=0){
        fscanf(in,"%s\n", string);
        insertNode(&root, string);
        printf("\nAdding %s \n", string);
        preOrder(root);
    }
    fclose(in);

    return 0;
}
