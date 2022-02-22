#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode{
	int val;
  	struct TreeNode* left;
 	struct TreeNode* right;
}TreeNode;

TreeNode* buildTree(int val){
	TreeNode* newNode = malloc(sizeof(TreeNode));
  	newNode->val = val;
  	newNode->left = newNode->right = NULL;
	return newNode;
}


void preorder(TreeNode* root, int* flag){
    if(!root)return;
    printf("%s%d",*flag?"":" ",root->val);
    *flag = 0;
    preorder(root->left, flag);
    preorder(root->right, flag);
}


int main(void){
	int size, val,target,flag;
  
  	scanf("%d",&size);
  	TreeNode **queue = malloc(sizeof(TreeNode*)*(size+1));
    queue[1] = NULL;
  	for(int i = 1; i <= size; i++){
      	scanf("%d",&val);
    	queue[i] = buildTree(val);
    }
    scanf("%d",&target);
    for(int i = size; i > 0; i--){
        if(queue[i]->val == target){
            target = i;
            break;
        }
    }
    queue[target] = NULL;
    // for(int i = target; i<size; i++){
    //     queue[i] = queue[i+1];
    // }
    // queue[size--] = NULL;
  	for(int i = 1; i <= size; i++){
    	if(i*2<=size){
        	queue[i]->left = queue[i*2];
      	}
        if(i*2+1<=size){
            queue[i]->right = queue[i*2+1];
        }
    }
    flag = 1;
    preorder(queue[1],&flag);
}