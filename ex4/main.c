#include <stdio.h>
#include <string.h>
#include <malloc.h>

// ex 8 lab 4

typedef struct node{
    char key;
    struct node * left, *right;
}NodeT;

NodeT* create(char key){
    NodeT* p = malloc(sizeof(NodeT));
    p->key=key;
    p->left=NULL;
    p->right=NULL;
    return p;
}

/// this takes a string which is made of a tree in postorder and builds the tree
void insert_postorder(NodeT** root, char key[]){
    if(key==NULL)exit(1);
    NodeT* stiva[20] = {};
    int esp = 0;
    char* key_preorder = strrev(key);
    for(int i=0;i < strlen(key_preorder);i++){
        printf("\nPutting key[%d]=%c", i, key_preorder[i]);
            if(*root == NULL){
                *root = create(key_preorder[i]);
                stiva[esp] = *root;
                continue;
            }
//            int placed = 0;
            while(1){
                printf(" stiva[%d]=%c ", esp, stiva[esp]->key);

                if(stiva[esp]->right==NULL){
                    printf("Creating a key on right child");
                    stiva[esp]->right = create(key_preorder[i]);
                    if(strchr("*+-",key_preorder[i])!=NULL){
                        stiva[esp+1]=stiva[esp]->right;
                        esp++;
                    }
                    break;
                }
                if(stiva[esp]->left==NULL){
                    printf("Creating a key on left child");
                    stiva[esp]->left = create(key_preorder[i]);
                    if(strchr("*+-",key_preorder[i])!=NULL){
                        stiva[esp+1]=stiva[esp]->left;
                        esp++;

                    }
                    //placed = 1;
                    break;
                }
                esp--;
                if(esp<0)exit(2);
            }
    }
}

void postOrder(NodeT ** root, char key[]){

//    if(strlen(key)<=2){
//        return;
//    }
//    if (root == NULL) {
//        *root = create(key[2]);
//        (*root)->left = create(key[0]);
//        (*root)->right = create(key[1]);
//        postOrder(&root, key+3);
//        return;
//    }


//    NodeT* p = *root;
//    *root = create(key[1]);
//    (*root)->right = create(key[0]);
//    (*root)->left = p;
//    postOrder(&root, key+2);



}

void postOrderAfisare(NodeT *root){
    if (root == NULL) {
//        printf("NULL ");
        return;
    }
    postOrderAfisare(root->left);
    postOrderAfisare(root->right);
    printf("%c ", root->key);
}



int main() {
    char string[] = {"ac+d-#e-*"};
    NodeT* root = NULL;
    insert_postorder(&root, string);
    printf("\n");
    postOrderAfisare(root);
    return 0;
}
