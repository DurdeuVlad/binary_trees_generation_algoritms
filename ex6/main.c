#include <stdio.h>
#include <malloc.h>

// ex 15, lab 5

typedef struct node{
    int key;
    struct node *left, *right;
}NodeT;

NodeT* create(int key){
    NodeT * p = malloc(sizeof(NodeT));
    p->key=key;
    p->right=NULL;
    p->left=NULL;
    return p;
}

void insert(NodeT ** root, int key){
    if(*root==NULL) {
        *root = create(key);
        return;
    }
    if((*root)->key<=key){
        if((*root)->right==NULL){
            (*root)->right= create(key);
            return;
        }
        insert(&(*root)->right, key);
    }
    else { // add else here
        if((*root)->left==NULL){
            (*root)->left = create(key);
            return;
        }
        insert(&(*root)->left, key);
    }
}


void generate(NodeT ** root, int key[], int length){
    (*root) = create(key[length/2]);
    for(int i=length/2-1;i>0;i--){
        insert(&(*root)->left, key[i]);
    }
    for(int i=length/2+1;i<length;i++){
        insert(&(*root)->right, key[i]);
    }

}

void preOrder(NodeT *root){
    if (root == NULL) { printf("# "); return;}
    printf("%d ", root->key);
    preOrder(root->left);
    preOrder(root->right);

}

int main() {
    int key_list[] = {1, 2, 3, 4 , 5, 6, 7, 8};
    NodeT * root = NULL;
    generate(&root, key_list, 8);
    preOrder(root);
    return 0;
}
