#include<stdio.h>
#include<stdlib.h>


int bs(int *array, int max,int min,int target){
	if(min>max)return -1;
	int mid = (max+min)/2;
	printf("%d %d %d\n",min,mid,max);
	printf("%d %d %d\n",array[min],array[mid],array[max]);
	if(array[mid]==target){
		return mid;
	}else if(array[mid]<target){
		return bs(array,max,mid+1,target);
	}else{
		return bs(array,mid-1,min,target);
	}
}


int main(void){
	int length = 0;
	scanf("%d",&length);
	int *array = calloc(1,sizeof(int)*length);
	for(int i = 0; i < length; i++){
		scanf("%d",&array[i]);
	}
	int target = 0;
	scanf("%d",&target);
	printf("%d\n",bs(array,length-1,0,target));
}