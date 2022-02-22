#include<stdio.h>
#include<stdlib.h>

int* mergeSort(int* arr,int size){
    if(size<2)return arr;
    
    int size1 = size/2;
    int size2 = size-size/2;
    int* arr1 = mergeSort(arr,size1);
    int* arr2 = mergeSort(arr+size1,size2);
    int* res = malloc(sizeof(int)*size);
    
    for(int i = 0, j = 0, resIndex = 0; resIndex < size; resIndex++){
        if(i < size1 && j < size2){
            if(arr1[i]>arr2[j]){
                res[resIndex] = arr2[j++];
            }else{
                res[resIndex] = arr1[i++];
            }
        }else if(i < size1){
            res[resIndex] = arr1[i++];
        }else{
            res[resIndex] = arr2[j++];
        }
    }
    for(int i = 0; i < size; i++){
        arr[i] = res[i];
    }
    free(res);

    return arr;
}

int* insertionSort(int* arr, int size){
    int i,j,temp;
    for(int i = 0; i < size; i++){
        temp = arr[i];
        for(j = i-1; j > -1 && arr[j] > temp; j--){
            arr[j+1] = arr[j];
        };
        arr[j+1] = temp;
        for(int i = 0; i < size; i++){
            printf("%d", arr[i]);
            if(i < size - 1)printf(" ");
        }
        printf("\n");
    }
    return arr;
}



void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void quickSort(int* farr, int farrSize, int* arr, int size){
    if(size<2)return;
    int max = size-1, pivot = arr[0];
    for(int i = size-1; i; i--){
        if(arr[i]>pivot){
            swap(&arr[max--],&arr[i]);
        }
    }
    swap(&arr[max],&arr[0]);

    for(int i = 0; i < farrSize; i++){
        printf("%d",farr[i]);
        if(i<farrSize-1)printf(" ");
    }
    printf("\n");

    quickSort(farr,farrSize,arr,max);
    quickSort(farr,farrSize,arr+max+1,size-max-1);
}


int main(void){
    int size;
    scanf("%d",&size);
    int *array = malloc(sizeof(int)*size);
    for(int i = 0; i < size; i++){
        scanf("%d",&array[i]);
    };
    quickSort(array,size,array,size);
    return 0;
}