#include<stdio.h>
#include<stdlib.h>

typedef struct LinkList{
    int val;
    struct LinkList* next;
}LinkList;

LinkList* createLinkList(){
    LinkList* newList = malloc(sizeof(LinkList));
    newList->val = 0;
    newList->next = NULL;
    return newList;
}

typedef struct Stack{
    int size;
    LinkList* head;
    LinkList* tail;
}Stack;

Stack* createStack(){
    Stack* newStack = malloc(sizeof(Stack));
    newStack->tail = createLinkList();
    newStack->head = newStack->tail;
    newStack->size = 0;
    return newStack;
}

void push(Stack *obj, int val){
    LinkList* newList = createLinkList();
    newList->val = val;
    newList->next = obj->head;
    obj->head = newList;
    obj->size++;
}


int isEmpty(Stack *obj){
    if(obj->head == obj->tail){
        return 1;
    }
    return 0;
}
int pop(Stack *obj){
    if(isEmpty(obj))return -1;
    int result = obj->head->val;
    LinkList *target = obj->head;
    obj->head = obj->head->next;
    obj->size--;
    free(target);
    return result;
}


void printStack(Stack *obj){
    int *array = malloc(sizeof(int)*obj->size),i;
    LinkList* curt;
    for(curt = obj->head,i=0; curt!=obj->tail&&i<obj->size; curt = curt->next,i++){
        array[i] = curt->val;
    }
    for(i = 0; i < obj->size; i++){
        printf("%d",array[obj->size-1-i]);
        if(i+1<obj->size)printf(" ");
    }
}

int size(Stack *obj){
    return obj->size;
}


int show(Stack *obj){
    if(isEmpty(obj))return -1;
    return obj->head->val;
}



int main(void){
    Stack* tower1 = createStack();
    Stack* tower2 = createStack();
    Stack* tower3 = createStack();
    int n,i,prevStep=0;

    scanf("%d",&n);
    for(i = 0; i < n; i++){
        push(tower1,n-i);
    }

    printf("Tower1:");
    printStack(tower1);
    printf("\nTower2:");
    printStack(tower2);
    printf("\nTower3:");
    printStack(tower3);

    i = 0;
    while(size(tower3)<n){
        int show1 = show(tower1);
        int show2 = show(tower2);
        int show3 = show(tower3);
        
        if(show1!=-1&&show1!=prevStep&&(show1<show2||show1<show3||show2==-1||show3==-1)){
            if(size(tower1)%2&&(show1<show3||show3==-1)){
                pop(tower1);
                push(tower3,show1);
                prevStep = show1;
            }else if(size(tower1)%2==0&&(show1<show2||show2==-1)){
                pop(tower1);
                push(tower2,show1);
                prevStep = show1;
            }
        }else if(show2!=-1&&show2!=prevStep&&(show2<show1||show2<show3||show1==-1||show3==-1)){
            if(size(tower2)%2&&(show2<show3||show3==-1)){
                pop(tower2);
                push(tower3,show2);
                prevStep = show2;
            }else if(size(tower2)%2==0&&(show2<show1||show1==-1)){
                pop(tower2);
                push(tower1,show2);
                prevStep = show2;
            }
        }else if(show3!=-1&&show3!=prevStep&&(show3<show1||show3<show2||show1==-1||show2==-1)){
            if(size(tower3)%2&&(show3<show2||show2==-1)){
                pop(tower3);
                push(tower2,show3);
                prevStep = show3;
            }else if(size(tower3)%2==0&&(show3<show1||show1==-1)){
                pop(tower3);
                push(tower1,show3);
                prevStep = show3;
            }
        }
        
        printf("\n\nTower1:");
        printStack(tower1);
        printf("\nTower2:");
        printStack(tower2);
        printf("\nTower3:");
        printStack(tower3);
    }
    printf("\n");
}





