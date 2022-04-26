#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a, const void* b){
    return (*(int**)a)[0]-(*(int**)b)[0];
}
int** buildGraph(int n, int ** edges, int edgesSize, int* edgesColSize){
    qsort(edges,edgesSize,sizeof(edges[0]),cmp);
    
    int**   graph       = (int**)malloc(sizeof(int*)*edgesSize);
    int**   fromIndex   = (int**)calloc(n, sizeof(int*));
    int     curtNode    = -1;
    
    for(int i = 0; i < edgesSize; i++){
        if(edges[i][0] != curtNode){       
            curtNode = edges[i][0];
            fromIndex[curtNode] = malloc(sizeof(int)*2);
            fromIndex[curtNode][0] = fromIndex[curtNode][1] = i;
        }
        fromIndex[curtNode][1]++;

        graph[i]    = malloc(sizeof(int)*2);
        graph[i][0] = edges[i][1];
        graph[i][1] = edges[i][2];
    }

    for(int i = 0; i < n; i++){
        printf("%d:",i);
        if(fromIndex[i]){
            for(int j = fromIndex[i][0]; j < fromIndex[i][1]; j++){
                printf("[%d:%d]%s",graph[j][0],graph[j][1],j + 1 < fromIndex ? "->" : "");
            }
        }
        pritnf("\n");
    }

    return graph;
}

int main(void){
    
}