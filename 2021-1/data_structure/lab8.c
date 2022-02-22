#include<stdio.h>
#include<stdlib.h>

void trav(char*s , int size, char** combination, char* record, int* combinationIndex, int combinationSize, int length){
    if(s[0]=='\n'){
        memcpy(combination[*combinationIndex],record,combinationSize+1);
        (*combinationIndex)++;
        return;    
    }
    
    for(int i = 0; i <= length-size; i++){
        record[combinationSize-size] = s[0];
        trav(s+1,size-1,combination,record,combinationIndex,combinationSize,length);
    }
}

int main(void){
	int n,val;
  	scanf("%d",&n);
  	Node* head = createNode();
  	for(int i = 0; i < n; i++){
    	scanf("%d",&val);
      	add(head,val,-1);
    }

  	scanf("%d",&val);
    int pos = search(head,val);
  	printf("%d\n",pos);
  	scanf("%d",&val);
    add(head,val,pos);
  	printList(head);
    
  return 0;
}






