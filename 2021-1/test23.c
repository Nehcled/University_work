#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

int parent[1000];

int cmp(const void* a, const void* b){
    return *(int*)a-*(int*)b;
}

int find(int target){
    if(parent[target]==-1)return target;
    return parent[target] = find(parent[target]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    // printf("a:%d,b:%d\n",a,b);
    if(a!=b){
        parent[b] = a;
    }
}

int main(){
    int num;
    scanf("%d",&num);
    int **graph = malloc(sizeof(int*)*num);
    int *result = malloc(sizeof(int)*(num-1));
    int resIndex = 0;

    for(int i = 0; i < num; i++){
        parent[i] = -1;
        graph[i] = malloc(sizeof(int)*num);
        for(int j = 0; j < num; j++){
            scanf("%d",&graph[i][j]);
        }
    }

    for(int i = 0; i < num-1; i++){
        int minR,minC,min = INT_MAX;
        for(int j = 0; j < num; j++){
            for(int k = j; k < num; k++){
                if(graph[j][k] && graph[j][k] < min && find(k)!=find(j)){
                    min = graph[j][k];
                    minR = j;
                    minC = k;
                }
            }
        }
        graph[minR][minC] = 0;
        Union(minC,minR);
        result[resIndex++] = min;
        printf("minr:%d minc:%d min:%d\n",minR,minC,min);
        for(int j = 0;j  < num; j++){
            printf("%d ",parent[j]);
        }
        printf("\n");
    }

    for(int i = 0; i < num-1; i++){
        printf("%d%s",result[i],i<num-1?" ":"");
    }

    return 0;
}