#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode* createTree(int val){
    TreeNode*new = malloc(sizeof(TreeNode));
    new->val = val;
    new->left = new->right = NULL;
    return new;
}

TreeNode* findBST(TreeNode* root, int val){
    if(!root)return NULL;
    if(val == root->val)return root;

    if(val > root->val){
        return findBST(root->right, val);
    }else if(val < root->val){
        return findBST(root->left, val);
    }

    return NULL;
}
TreeNode* insertBST(TreeNode* root, int val){
    if(findBST(root,val))return NULL;
    
    TreeNode* curt = root, *new = malloc(sizeof(TreeNode));
    new->val = val;
    new->left = new->right = NULL;

    if(!root)return  new;
    
    while((val < curt->val && curt->left )||(val > curt->val && curt->right)){\
        if(val < curt->val)curt = curt->left;
        else if(val > curt->val)curt = curt->right;
    }
    if(val < curt->val){
        curt->left = new;
    }else if(val > curt->val){
        curt->right = new;
    }
    
    return new;
}

void deleteBST(TreeNode* root, int val){
    if(!findBST(root,val))return;
    
    TreeNode* curt = root, * parent = NULL;
    while(curt->val != val){
        parent = curt;
        if(val > curt-> val){
            curt = curt->right;
        }else if(val < curt->val){
            curt = curt->left;
        }
    }


    if(!curt->left&&!curt->right){
        if(val > parent->val){
            parent->right = NULL;
        }else{
            parent->left = NULL;
        }
        free(curt);
    }else if(!curt->left){
        if(val > parent->val){
            parent->right = curt->right;
        }else{
            parent->left = curt->right;
        }
        free(curt);
    }else{
        TreeNode*target = curt;
        parent = curt;
        curt = curt->left;
        while(curt->right){
            parent = curt;
            curt = curt->right;
        }
        // printf("%d %d %d\n",curt->val,target->val,parent->val);
        if(curt->val>parent->val){
            parent->right = curt->left;
        }else if(curt->val< parent->val){
            parent->left = curt->left;
        }
        target->val = curt->val;
        free(curt);
    } 
}

void preorder(TreeNode* root,int val){
    if(!root)return;
    if(root->val!=val)printf(" ");
    printf("%d",root->val);
    preorder(root->left,val);
    preorder(root->right,val);
}


int main(void){
    int size,first;
  	scanf("%d",&size);
  	scanf("%d",&first);
    TreeNode* tree = createTree(first);
  	for(int i = 0; i < size-1; i++){
     	scanf("%d",&first);
      	insertBST(tree,first);
    }
  	scanf("%d",&first);
  	deleteBST(tree,first);
  	scanf("%d",&first);
  	insertBST(tree,first);
  	preorder(tree,tree->val);
}