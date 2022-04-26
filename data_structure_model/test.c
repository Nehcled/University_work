#include<stdio.h>
#include<stdlib.h>

int main(void){
    int** graph = malloc(sizeof(int*)*100000);
    for(int i = 0; i < 100000; i++){
        graph[i] = malloc(sizeof(int)*100000);
    }
}