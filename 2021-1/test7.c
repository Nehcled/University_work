#include<stdio.h>
#include<stdlib.h>
#define MAXLENGTH 100

int main(void){
	int length;
	scanf("%d",&length);
	int *arr = (int*)malloc(sizeof(int)*length);
	// int arr[MAXLENGTH];

	for(int i = 0; i < length; i++){
		scanf("%d",&arr[i]);
	}

	int *criticalPoints = (int*)malloc(sizeof(int)*(length-2)); //The biggest number of cirtical point will happen in the point which bigger than it's neighbors or smaller than it's neighbors. And so on, the lenght of array will be number of cirticle point - 2;
	// int criticalPoints[MAXLENGTH-2];

	int index = 0;

	for(int i = 1; i < length-1; i++){
		if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){	//local maximum
			criticalPoints[index] = i;
			index++;
		}else if(arr[i] < arr[i-1] && arr[i] < arr[i+1]){ //local minimum
			criticalPoints[index] = i;
			index++;
		}
	}

	// int minDistance = MAXLENGTH;
	int minDistance = length, maxDistance = criticalPoints[index-1] - criticalPoints[0];
	for(int i = 0; i < index-1; i++){
		if(criticalPoints[i+1] - criticalPoints[i] < minDistance){ //Compare and find minimum distance
			minDistance = criticalPoints[i+1] - criticalPoints[i];
		}
	}

	if(index<2){ //There is not exist distance of critical points when number of critical point is lower than 2.
		printf("max distance:%d min distance:%d\n",-1,-1);
	}else{
		printf("max distance:%d min distance:%d\n", maxDistance, minDistance);
	}

	return 0;
}