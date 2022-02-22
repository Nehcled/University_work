#include<stdio.h>
#include<stdlib.h>
#define SIZE 4
void swap(int *a, int *b){
    int hold = *a;
    *a = *b;
    *b = hold;
}

int factorial(int n){
    if(!n)return 1;
    return factorial(n-1);
}

void recursive(int *arr, int size, int* record, int**result, int resultSize, int* resultIndex){
    if(size==1){
        record[resultSize-size] = arr[0];
        for(int i = 0; i < resultSize; i++){
            result[*resultIndex][i] = record[i];
        }
        (*resultIndex)++;
        return;
    }

    for(int i = 0; i < size; i++){
        swap(&arr[0],&arr[i]);
        record[resultSize-size] = arr[0];
        recursive(&arr[1],size-1,record,result,resultSize,resultIndex);
        swap(&arr[0],&arr[i]);
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int permuteSize = factorial(numsSize);
    int resultIndex = 0;
    int *record = malloc(sizeof(int)*permuteSize);
    int **result = malloc(sizeof(int*)*permuteSize);
    
    *returnSize = permuteSize;
    *returnColumnSizes = malloc(sizeof(int)*permuteSize);
    
    for(int i = 0; i < permuteSize; i++){
        result[i] = malloc(sizeof(int)*numsSize);
        (*returnColumnSizes)[i] = numsSize;
    }  
    
    
    recursive(nums,numsSize,record,result,numsSize,&resultIndex);
    
    return result;
}
int main(void){
    int array[SIZE] = {1,2,3,4};
    int result[SIZE];
    int *num,**numsSize;
    permute(array,SIZE,num,numsSize);
}