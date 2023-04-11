#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define SIZE 7

// lab6 ex 7

typedef struct node{
    char key[30];
    struct node * next;
}NodeT;

NodeT * create(char key[]){
    NodeT * p = malloc(sizeof(NodeT));
    strcpy(p->key, key);
    p->next=NULL;
    return p;
}

int f1(char cuvant[]){
    int sum=0;
    for(int i=0;i<strlen(cuvant);i++){
        sum+=cuvant[i];
    }
    return sum % strlen(cuvant);
}

int f2(int a){
    return a%SIZE;
}

void insert(NodeT** tabel, char key[]){
    int index = f2(f1(key));
    if(tabel[index]==NULL){
        tabel[index] = create(key);
        return;
    }
    NodeT*p=tabel[index];
    tabel[index] = create(key);
    tabel[index]->next=p;
}

void afiseaza(NodeT* tabel[SIZE]){
    for(int i=0;i<SIZE;i++){
        printf("%d. ", i);
        if(tabel[i]==NULL){
            printf("NULL\n");
            continue;
        }
        NodeT * p = tabel[i];
        while(p!=NULL){
            printf("%s ", p->key);
            p=p->next;
        }
        printf("\n");
    }
}

int main() {
    NodeT* tabelDispersie[SIZE];
    for(int i=0;i<SIZE;i++){
        tabelDispersie[i]=NULL;
    }
    FILE * IN = fopen("aoleo.txt", "r");
    int a=0;
    fscanf(IN, "%d", &a);
    for(int i=0;i<a;i++){
        char string[100];
        fscanf(IN, "%s\n", string);
        insert(&tabelDispersie, string);
    }
    afiseaza(tabelDispersie);
    fclose(IN);
    return 0;
}
