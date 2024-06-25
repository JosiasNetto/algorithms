#include <stdio.h>
#include <stdlib.h>

typedef struct bstnode{
    int key;
    struct bstnode* left;
    struct bstnode* right;
    int height;
    int size;
}BstNode;

BstNode* create_bstnode(int k){
    BstNode* newNode = (BstNode*) malloc(sizeof(BstNode));

    newNode->key = k;
    newNode->left = newNode->right = NULL;
    newNode->height = 0;
    newNode->size = 1;

    return newNode;
}

typedef struct bst{
    BstNode* root;
    int nodeCount;
}Bst;

Bst* create_bst(){
    Bst* newTree = (Bst*) malloc(sizeof(Bst));

    newTree->root = NULL;
    newTree->nodeCount = 0;

    return newTree;
}

int find_help(BstNode* rt, int k){
    if(rt == NULL){
        return -1;
    }
    if(rt->key > k){
        return(find_help(rt->left, k));
    }
    else if(rt->key == k){
        return rt->key;
    }
    else{
        return find_help(rt->right, k);
    }
}

int find(Bst* bst, int k){
    return find_help(bst->root, k);
}

int max(int a, int b){
    if(b > a){
        return b;
    }
    else{
        return a;
    }
}

int h(BstNode* rt){
    if(rt == NULL){
        return -1;
    }
    return rt->height;
}

int get_balance(BstNode* rt){
    if(rt == NULL){
        return 0;
    }
    return h(rt->left) - h(rt->right);
}

int size(BstNode* rt){
  if(rt == NULL){
    return 0;
  }
  else{
    return rt->size;
  }
}

BstNode* right_rotate(BstNode* rt){
    BstNode* l = rt->left;
    BstNode* lr = l->right;

    l->right = rt;
    rt->left = lr;

    rt->height = max(h(rt->left), h(rt->right)) + 1;
    l->height = max(h(l->left), h(l->right)) + 1;

    rt->size = 1 + (size(rt->left) + size(rt->right));
    l->size = 1 + (size(l->left) + size(l->right));
    

    return l;
}

BstNode* left_rotate(BstNode* rt){
    BstNode* r = rt->right;
    BstNode* rl = r->left;

    r->left = rt;
    rt->right = rl;

    rt->height = max(h(rt->left), h(rt->right)) + 1;
    r->height = max(h(r->left), h(r->right)) + 1;

    rt->size = 1 + (size(rt->left) + size(rt->right));
    r->size = 1 + (size(r->left) + size(r->right));

    return r;
}

BstNode* insert_help(BstNode* rt, int k){
    if(rt == NULL){
        return create_bstnode(k);
    }
    if(rt->key > k){
        rt->left = insert_help(rt->left, k);
    }
    else{
        rt->right = insert_help(rt->right, k);
    }
    
    rt->height = 1 + max(h(rt->left), h(rt->right));
    rt->size = 1 + (size(rt->left) + size(rt->right));
    
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

void insert(Bst* bst, int k){
    bst->root = insert_help(bst->root, k);
    bst->nodeCount++;
}

int find_index_help(BstNode* rt, int k){
  if(rt == NULL){
    return -1;
  }
  else if(rt->key > k){
    return find_index_help(rt->left, k);
  }
  else if(rt->key < k){
    int right_index = find_index_help(rt->right, k);
    if(right_index != -1){
      return (right_index + size(rt->left)) + 1;
    }
    else{
      return -1;
    }
  }
  else{
    return size(rt->left) + 1;
  }
}

int find_index(Bst* bst, int k){
  return find_index_help(bst->root, k);
}

int main(){

  int q;
  scanf("%d", &q);

  Bst* bst = create_bst();

  for(int i = 0; i < q; i++){
    int x, y;
    scanf("%d %d", &x, &y);

    if(x == 1){
      insert(bst, y);
    }
    else if(x == 2){
      int index = find_index(bst, y);
      if(index != -1){
        printf("%d\n", index);
      }
      else{
        printf("Data tidak ada\n");
      }
    }
  }
}