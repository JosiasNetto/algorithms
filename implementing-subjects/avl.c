#include <stdio.h>
#include<stdlib.h>

typedef int Key;
typedef int Value;

typedef struct bstnode // Struct of the node of a bst
{
  Key key;  //The key of the node
  Value element;  //The value of the key of the node
  struct bstnode* left; //Pointer to the left node
  struct bstnode* right;  //Pointer to the right node
  int height; //Height of the node
}BstNode;

//Func that create a node with his key and value
BstNode* create_bstnode(Key k, Value ele){ 
  BstNode* newNode = (BstNode*) malloc(sizeof(BstNode));  //Malloc a space in the memory for the Node

  newNode->key = k; //Declare the key of the node
  newNode->element = ele; //Declare the element of the node
  newNode->left = newNode->right = NULL;  //Declare that the two pointers point to nothing in the start 
  newNode->height = 0;  //Initial height of the node is 0

  return newNode; //Return the pointer of the Node 
}

typedef struct bst{ //The struct of the Bst tree
  BstNode* root;  //The root node, that gona to point to his subsequent nodes
  int nodecount;  //The count of the nodes in the tree
}Bst;

//Func that creeate the bst tree
Bst* create_bst(){
  Bst* newTree = (Bst*) malloc(sizeof(Bst));  //Malloc the space in the memory for the tree

  newTree->root = NULL; //Declare the root as NULL
  newTree->nodecount = 0; //Stard the count with zero nodes

  return newTree; //Return the pointer of the tree
}

//Func that aux the main find
int findhelp(BstNode* rt, Key k){ //Receive the node and the seached key as arguments 
  if(rt == NULL){ //If don`t exist, return -1
    return -1;
  }
  else if(rt->key > k){ //If the seached key is smaler then the actual node key, go find in the left node 
    return findhelp(rt->left, k);
  } 
  else if(rt->key == k){  //If the actual node key is equal to the searched key, return the element of the key
    return rt->element;
  }
  else{ //If the seached key is bigger then the actual key, go find in the right node
    return findhelp(rt->right, k);
  }
}

//Main func to find a key in a bst
int find(Bst* bst, Key k){  //Receive the tree and the wanted key as arguments
  return findhelp(bst->root, k);  //Return the result of the help func to find
}

//Func that return the bigger int in two numbers
int max(int a, int b){  
  if(b > a){
    return b;
  }
  else{
    return a;
  }
}

//Func that return the height of a node
int h(BstNode* rt){
  if(rt == NULL){ //If is a NULL node, the height is equal to -1
    return -1;
  } 
  return rt->height;  //Else, return the actual height
}

int get_balance(BstNode* rt){ //Return the balance of the height of the tree
  if(rt == NULL){ //If is a Null node, return 0
    return 0;
  }
  return h(rt->left) - h(rt->right);  //Return the height of the left subtree - the hieght of the right subtree
}

//Func that right rotates a node of the tree
BstNode* right_rotate(BstNode* rt){ 
  BstNode* l = rt->left;  //Declare the new root of the nodes, that is the left node of the actual root
  BstNode* lr = l->right; //Aux var that receive the right node of the left node of the past root

  l->right = rt;  //Receive the past root as the right node of the new root
  rt->left = lr;  //The left node of the past root, now points to the past right node node of the actual root
  rt->height = max(h(rt->left), h(rt->right)) + 1;  //Update the height of the rt node
  l->height = max(h(l->left), h(l->right)) + 1; //Update the height of the new root node

  return l; //Return the new root 
}

//Func that lef rotates a node of the tree
BstNode* left_rotate(BstNode* rt){  
  BstNode* r = rt->right; //declare the new root of the nodes, that is the right node of the actual root
  BstNode* rl = r->left;  //Aux var that points to the left node of the new root node

  r->left = rt; //Receive the past root as the left node of the new root
  rt->right = rl; //The right node of the past root, now points to the past left node of the new root

  rt->height = max(h(rt->left), h(rt->right)) + 1;  //Update the height of the rt node
  r->height = max(h(r->left), h(r->right)) + 1; //Update the height of the new root node

  return r; //Return the new root
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
  if(balance < -1 && k < rt->right->key){
    rt->right = right_rotate(rt->right);
    return left_rotate(rt);
  }
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

void pre_order(BstNode* rt){
  if(rt != NULL){
    printf(" %d", rt->key);
    pre_order(rt->left);
    pre_order(rt->right);
  }
}

void in_order(BstNode* rt){
  if(rt != NULL){
    in_order(rt->left);
    printf(" %d", rt->key);
    in_order(rt->right);
  }
}

void pos_order(BstNode* rt){
  if(rt != NULL){
    pos_order(rt->left);
    pos_order(rt->right);
    printf(" %d", rt->key);
  }
}



int main(){

  int n;
  int element;
  scanf("%d", &n);

  Bst* Tree = create_bst();

  for(int i  = 0; i < n; i++){
    scanf("%d", &element);
    insert(Tree, element, 0);
  }

  printf("Pre order :");
  pre_order(Tree->root);


  printf("\nIn order  :");
  in_order(Tree->root);
  
  
  printf("\nPost order:");
  pos_order(Tree->root);


  return 0;
}
