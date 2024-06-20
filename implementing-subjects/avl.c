#include <stdio.h>
#include<stdlib.h>

typedef int Key;
typedef int Value;

typedef struct bstnode
{
  Key key;
  Value element;
  struct bstnode* left;
  struct bstnode* right;
  int height;
}BstNode;

BstNode* create_bstnode(Key k, Value ele){
  BstNode* newNode = (BstNode*) malloc(sizeof(BstNode));

  newNode->key = k;
  newNode->element = ele;
  newNode->left = newNode->right = NULL;
  newNode->height = 0;

  return newNode;
}

typedef struct bst{
  BstNode* root;
  int nodecount;
}Bst;

Bst* create_bst(){
  Bst* newTree = (Bst*) malloc(sizeof(Bst));

  newTree->root = NULL;
  newTree->nodecount = 0;

  return newTree;
}

int findhelp(BstNode* rt, Key k){
  if(rt == NULL){
    return -1;
  }
  else if(rt->key > k){
    return findhelp(rt->left, k);
  } 
  else if(rt->key == k){
    return rt->element;
  }
  else{
    return findhelp(rt->right, k);
  }
}

int find(Bst* bst, Key k){
  return findhelp(bst->root, k);
}

int max(int a, int b){
  if(b > a){
    return b;
  }
  else{
    return ;
  }
}

int h(BstNode* rt){
  if(rt == NULL){
    return -1;
  } 
}

int get_balance(BstNode* rt){
  if(rt == NULL){
    return 0;
  }
  return h(rt->left) - h(rt->right);
}

BstNode* insert_help(BstNode* rt, Key k, int element){
  if(rt == NULL){
    return create_bstnode(k, element);
  }
  if(rt->key > k){
    rt->left = insert_help(rt->left, k, element);
  }
  else{
    rt->right = insert_help(rt->right, k, element);
  }

  rt->height = 1 + max(h(rt->left), h(rt->right));
  int balance = get_balance(rt);

  if(balance < -1 && k >= rt->right->key){
    return left_rotate(rt);
  }
  if(balance > 1 && k < rt->left->key){
    return right_rotate(rt);
  }
  if(balance > 1 && k >= rt->left->key){
    rt->left = left_rotate(rt->left);
    return right_rotate(rt);
  }
  if(balance < -1 && k > rt->right->key){
    rt->right = right_rotate(rt->right);
    return left_rotate(rt);
  }
  return rt;







  return rt;
}

void insert(Bst* bst, Key k, int element){
  bst->root = insert_help(bst->root, k, element);
  bst->nodecount ++;
}

BstNode* get_min(BstNode* rt){
  if(rt->left == NULL){
    return rt;
  }
  return get_min(rt->left);
}

BstNode* delete_min(BstNode* rt){
  if(rt->left == NULL){
    return rt->right;
  }
  rt->left = delete_min(rt->left);
  return rt;
}

BstNode* remove_help(BstNode* rt, Key k){
  if(rt == NULL){
    return NULL;
  }
  if(rt->key > k){
    rt->left = remove_help(rt->left, k);
  }
  else if(rt->key < k){
    rt->right = remove_help(rt->right, k);
  }
  else{
    if(rt->left == NULL){
      return rt->right;
    }
    else if(rt->right == NULL){
      return rt->left;
    }
    else{
      BstNode* temp = get_min(rt->right);
      rt->element = temp->element;
      rt->key = temp->key;
      rt->right = delete_min(rt->right);
    }
  }
  return rt;
}

int remove_key(Bst* bst, Key k){
  int temp = findhelp(bst->root, k);
  if(temp != -1){
    bst->root = remove_help(bst->root, k);
    bst->nodecount--;
  }
  return temp;
}



