void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void quickSort(int* farr, int farrSize, int* arr, int size){
    if(size<2)return;
    int max = size-1, pivot = arr[0];
    for(int i = size-1; i > -1; i--){
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