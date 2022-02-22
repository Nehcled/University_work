#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

typedef struct Node{
    int val;
    int* size;
    struct Node* next;
    struct Node* prev;
}Node;

Node* createList(){
    Node* new = malloc(sizeof(Node));
    new->size = malloc(sizeof(int));
    *(new->size) = 0;
    new->next = new->prev = NULL;
    return new; 
}

void insertion(Node* obj, int val, int insertIndex){
    if(*(obj->size)>=MAXSIZE){
        printf("memory is full!\n");
        return;
    }
    Node* prev,*curt,*new = malloc(sizeof(Node));
    int i;
    for(prev = obj, curt = obj->next, i = 0; curt&&i<insertIndex; prev = curt,curt = curt->next, i++);
    prev->next = new, new->prev = prev, new->next = curt;
    if(curt){
        curt->prev = new;
    }
    new->val = val;
    new->size = prev->size;
    *(new->size)++;
}

void printList(Node* obj){
    Node* curt;
    printf("next\n");
    for(curt = obj->next; curt->next; curt = curt->next){
        printf("%d->",curt->val);
    }
    printf("%d",curt->val);
    printf("\nprev\n");

    for(;curt->prev; curt = curt->prev){
        printf("%d",curt->val);
        if(curt->prev)printf("->");
    }
    printf("\n");
}

int main(void){
    int array[2147483647] = {0};



}

