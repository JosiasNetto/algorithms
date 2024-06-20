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
}BstNode;

BstNode* create_bstnode(Key k, Value ele){
  BstNode* newNode = (BstNode*) malloc(sizeof(BstNode));

  newNode->key = k;
  newNode->element = ele;
  newNode->left = newNode->right = NULL;

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

int find(Bst* bst, Key k){
  return findhelp(bst->root, k);
}

int findhelp(BstNode* rt, Key k){
  if(rt == NULL){
    return NULL;
  }
  else if(rt->key > k){
    return findhelp(rt->left, k);
  } 
  else if(rt->key = k){
    return rt->element;
  }
  else{
    return findhelp(rt->right, k);
  }
}

void insert(Bst* bst, Key k, int element){
  bst->root = inserthelp(bst->root, k, element);
  bst->nodecount ++;
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
  return rt;
}

int remove(Bst* bst, Key k){
  int temp = findhelp(bst->root, k);
  if(temp != NULL){
    bst->root = remove_help(bst->root, k);
    bst->nodecount--;
  }
  return temp;
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