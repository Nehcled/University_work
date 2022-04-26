#include<stdio.h>
#include<stdlib.h>


typedef struct HeapNode{
    int val;
    int priority;
}HeapNode;

typedef struct minPriorityQueue{
    int maxQueueSize;
    int amountOfElements;
    HeapNode *queue;    
}minPriorityQueue;

minPriorityQueue* createMinHeap(int maxQueueSize){
    minPriorityQueue* new = malloc(sizeof(minPriorityQueue));
    new->queue = malloc(sizeof(HeapNode)*(maxQueueSize+1));
    new->maxQueueSize = maxQueueSize+1;
    new->amountOfElements = 0;
    return new; 
}

void minHeapfiy(minPriorityQueue* obj,int node){
    int left = node*2;
    int right = node*2+1;
    int smallest = node;
    HeapNode *queue = obj->queue;
    if(left <= obj->amountOfElements && queue[left].priority < queue[smallest].priority){
        smallest = left;
    }
    if(right <= obj->amountOfElements && queue[right].priority < queue[smallest].priority){
        smallest = right;
    }
    if(smallest != node){
        HeapNode temp = queue[smallest];
        queue[smallest] = queue[node];
        queue[node] = temp;

        minHeapfiy(obj,smallest);
    }
}
int getParent(int node){
    return node/2;
}
void minHeapInsert(minPriorityQueue* obj, int val, int priority){
    int index = ++obj->amountOfElements;
    obj->queue[index].val = val;
    obj->queue[index].priority = priority;
    while(index>1 && obj->queue[getParent(index)].priority > obj->queue[index].priority){
        HeapNode temp = obj->queue[index];
        obj->queue[index] = obj->queue[getParent(index)];
        obj->queue[getParent(index)] = temp;
        index = getParent(index);
    }
}

void printHeap(minPriorityQueue* obj){
    for(int i = 1; i <= obj->amountOfElements; i++){
        printf("%d ",obj->queue[i].val);
    }
    printf("\n");
}

int extractMin(minPriorityQueue* obj){
    if(obj->amountOfElements==0){
        return -1;
    }
    int result = obj->queue[1].val;
    obj->queue[1] = obj->queue[obj->amountOfElements--];
    minHeapfiy(obj,1);
    return result;
}

int findPosition(minPriorityQueue* obj, int key){
    int i = 0;
    for(i = 1; i <= obj->amountOfElements; i++){
        if(obj->queue[i].priority==key){
            break;
        }
    }
    return i;
}
int main(void){
    int n = 10;
    minPriorityQueue* heap = createMinHeap(n*2);
    minHeapInsert(heap,1,1);
    int min,result=0;
    for(int i = 0; i < n;){
        min = extractMin(heap);
        if(result!=min){
            result = min;
            printf("%d\n",min);
            minHeapInsert(heap,min*2,min*2);
            minHeapInsert(heap,min*3,min*3);
            minHeapInsert(heap,min*5,min*5);
            printHeap(heap);
            i++;
        }
        
    }
    printf("%d",result);
}