#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void dfs(int** graph,int size,int node){
    printf("%s%d",node?" ":"",node);
    int *connect = malloc(sizeof(int)*size);
    for(int i = 0; i < size; i++){
        connect[i] = graph[i][node];
        graph[i][node] = 0;
    }
    for(int i = 0; i < size; i++){
        if(graph[node][i]){
            dfs(graph,size,i);
        }
    }
}


int main(){
    int num;
    scanf("%d",&num);
    int **graph = malloc(sizeof(int*)*num);
    for(int i = 0; i < num; i++){
        graph[i] =  malloc(sizeof(int)*num);
        for(int j = 0; j < num; j++){
            scanf("%d",&graph[i][j]);
        }
    }
    dfs(graph,num,0);
    return 0;
}