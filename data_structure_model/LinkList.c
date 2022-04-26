#include<stdio.h>
#include<stdlib.h>
#define DATATYPE int

struct ListNode{
    DATATYPE val;
    struct ListNode* next;
    struct ListNode** tail;
};

struct ListNode* createList(){
    struct ListNode* newNode = (struct ListNode*)calloc(1,sizeof(struct ListNode));
    newNode->tail = (struct ListNode**)calloc(1,sizeof(struct ListNode*));
    *newNode->tail = newNode;
    return newNode;
}

void insert(struct ListNode* obj, DATATYPE val){
    struct ListNode* newNode = (struct ListNode*)calloc(1,sizeof(struct ListNode));
    obj->next = newNode;

    newNode->val = val;

    newNode->tail = obj->tail;
    *newNode->tail = newNode;
}

void print(struct ListNode* obj){
    struct ListNode* curt;
    for(curt = obj->next; curt; curt = curt->next){
        printf("%d%s",curt->val,curt->next?"->":"");
    }
}
int main(void){
    struct ListNode* head = createList();
    printf("%d",head->next->val);
    print(head);
}