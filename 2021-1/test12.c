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

void inorder(TreeNode* root, int* flag){
    if(!root)return;
    inorder(root->left, flag);
    printf("%s%d",*flag?"":" ",root->val);
    *flag = 0;
    inorder(root->right, flag);
}

void postorder(TreeNode* root, int* flag){
    if(!root)return;
    postorder(root->left, flag);
    postorder(root->right, flag);
    printf("%s%d",*flag?"":" ",root->val);
    *flag = 0;
}

int main(void){
	int size, val;
  
  	scanf("%d",&size);
  	TreeNode **queue = malloc(sizeof(TreeNode*)*(size+1));
    queue[1] = NULL;
  	for(int i = 1; i <= size; i++){
      	scanf("%d",&val);
    	queue[i] = buildTree(val);
    }
  
  	for(int i = 1; i <= size; i++){
    	if(i*2<=size){
        	queue[i]->left = queue[i*2];
      	}
        if(i*2+1<=size){
            queue[i]->right = queue[i*2+1];
        }
    }
    int flag = 1;
    printf("DLR:");
    preorder(queue[1],&flag);
    flag = 1;
    printf("\nLDR:");
    inorder(queue[1],&flag);
    flag = 1;
    printf("\nLRD:");
    postorder(queue[1],&flag);
    printf("\n");
}