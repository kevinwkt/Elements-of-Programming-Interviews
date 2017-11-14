#include <stdio.h>
#include <iostream>
#include <stack>
#include <queue>


using namespace std;

struct node{
  int data;
  node* right;
  node* left;
};

int max(int a, int b){
  return a>b?a:b;
}

node* newnode(int val){
  node* temp=new node();
  temp->right=NULL;
  temp->left=NULL;
  temp->data=val;

  return temp;
}

bool sameTree(node *rootOne, node *rootTwo){
  if(rootOne==NULL&&rootTwo==NULL) return true;
  if(rootOne!=NULL&&rootTwo!=NULL)return (rootOne->data==rootTwo->data)&&sameTree(rootOne->left, rootTwo->left)&&sameTree(rootOne->right, rootTwo->right);
  return false;
}

void _deleteTree(node* head){
  if(head==NULL) return;
  _deleteTree(head->left);
  _deleteTree(head->right);
  printf("Deleting %d\n",head->data);
  free(head);

}

void deleteTree(node** head){
  _deleteTree(*head);
  *head=NULL;
}

node* invertTree(node* root){
  if(root==NULL) return NULL;
  node* r=invertTree(root->right);
  node* l=invertTree(root->left);
  root->left=r;
  root->right=l;
  return root;
}

bool isSubTree(node* bigTree, node* smallTree){
  if(smallTree==NULL) return true;
  if(bigTree==NULL) return false;
  if(sameTree(bigTree,smallTree)) return true;
  return isSubTree(bigTree->left,smallTree)||isSubTree(bigTree->right,smallTree);
}

int sizeTree(node* root){
  if(root==NULL) return 0;
  return sizeTree(root->left)+sizeTree(root->right)+1;
}

node* rightRotate(node* root){//When you need LL
  node* newRoot=root->left;
  root->left=newRoot->right;
  newRoot->right=root;
  root->height=max(root->left->height)
}

int heightTree(node* root){
    if(root==NULL) return 0;
    return max(heightTree(root->left),heightTree(root->right))+1;
}

// bool is bst(node* root){
//
// }

bool rootToLeaveSum(node* root, int sum){
  if(root==NULL) return false;
  if(root->left==NULL && root->right==NULL) return (sum==root->data);
  if(rootToLeaveSum(root->left,sum-root->data)||rootToLeaveSum(root->right,sum-root->data)) return true;
  return false;
}

bool isBST(node* root,int min, int max){
  if(root==NULL) return true;
  if(root->data<min||root->data>max) return false;
  return isBST(root->left,min,root->data)&&isBST(root->right,root->data,max);
}

bool isBalanced(node* root){
  if(root==NULL) return true;
  if((abs(heightTree(root->left)-heightTree(root->right))<=1)&&isBalanced(root->left)&&isBalanced(root->right)) return true;
  return false;
}

int getLevel(node* root,int level, int value){
  if(root==NULL) return 0;
  if(root->data==value) return level;
  int down=getLevel(root->left,level+1,value);
  if(down!=0) return down;
  down=getLevel(root->right,level+1,value);
  return down;
}

//That the sum of both children equals the root
bool isSumProperty(node* root){
  if(root==NULL||(root->right==NULL&&root->left==NULL)) return true;
  else{
    int leftDat=0,rightDat=0;
    if(root->left!=NULL) leftDat=root->left->data;
    if(root->right!=NULL) rightDat=root->right->data;
    return (root->data==leftDat+rightDat)&&isSumProperty(root->left)&&isSumProperty(root->right);
  }
}


int howManyLeaves(node* root){
  if(root==NULL) return 0;
  if(root->right==NULL&&root->left==NULL) return 1;
  return howManyLeaves(root->right)+howManyLeaves(root->left);
}

int sumFind(node* root){
  if(root==NULL) return 0;
  return sumFind(root->left)+sumFind(root->right)+root->data;
}

void iterativePostOrder(node* root){
  stack<node*> s1;
  stack<node*> s2;
  s1.push(root);
  while(s1.size()!=0){
    root= s1.top();
    s1.pop();
    s2.push(root);
    if(root->left!=NULL) s1.push(root->left);
    if(root->right!=NULL) s1.push(root->right);
  }

  while(s2.size()!=0){
    root=s2.top();
    printf("%3d",root->data);
    s2.pop();
  }
  printf("\n");
}

void iterativePreOrder(node* root){
  stack<node*> s;
  s.push(root);
  while(s.size()!=0){
    root=s.top();
    s.pop();
    printf("%3d",root->data);
    if(root->right!=NULL) s.push(root->right);
    if(root->left!=NULL) s.push(root->left);
  }
  printf("\n");
}

void iterativeInOrder(node* root){
  if(root==NULL){
    printf("Empty Tree\n");
    return;
  }
  stack<node*> s;
  while(true){
    if(root!=NULL){
      s.push(root);
      root=root->left;
    }else{
      if(s.size()==0) break;
      root=s.top();
      s.pop();
      printf("%3d",root->data);
      root=root->right;
    }
  }
  printf("\n");
}

void breadthFirstTrav(node* root){
  queue<node*> q;
  q.push(root);
  while(q.size()!=0){
    root=q.front();
    printf("%3d",root->data);
    q.pop();
    if(root->left!=NULL) q.push(root->left);
    if(root->right!=NULL) q.push(root->right);
  }
  printf("\n");
}

void breadthFirstTravPrints(node* root){
  queue<node*> q;
  q.push(root);
  q.push(NULL);
  while(q.size()!=0){
    root= q.front();
    q.pop();
    if(root==NULL){
      if(q.size()!=0) {
        printf("\n");
        q.push(NULL);
      }
    }else{
      printf("%3d",root->data);
      if(root->left!=NULL) q.push(root->left);
      if(root->right!=NULL) q.push(root->right);
    }
  }
  printf("\n");
}

bool isBinarySumTree(node* root){
  if(root==NULL||(root->right==NULL&&root->left==NULL)) return true;
  return (root->data==sumFind(root->left)+sumFind(root->right))&&isBinarySumTree(root->left)&&isBinarySumTree(root->right);
}

int main(){
  int sum=21;
  node *root = newnode(10);
  root->left        = newnode(8);
  root->right       = newnode(2);
  root->left->left  = newnode(3);
  root->left->right = newnode(5);
  root->right->left = newnode(2);


  printf("The level of %d is: %d\n",10,getLevel(root,1,10));


  printf("Iterative PostOrder\n");
  iterativePostOrder(root);

  printf("Level-order\n");
  breadthFirstTrav(root);

  printf("Level-order WITH PRINTS\n");
  breadthFirstTravPrints(root);

  printf("Iterative PreOrder\n");
  iterativePreOrder(root);

  printf("Iterative InOrder\n");
  iterativeInOrder(root);

  printf("Invert Tree\n");
  invertTree(root);
  breadthFirstTravPrints(root);

  // if(isBST(root,-1234567890,1234567890))
  //     printf("It is a bst\n");
  // else
  //     printf("It is not a BST\n");

  // isSumProperty(root);

  // if(isSumProperty(root))
  //     printf("It is sum property\n");
  // else
  //     printf("It is not sum property\n");

  // if(rootToLeaveSum(root, sum))
  //     printf("There is a root-to-leaf path with sum %d\n", sum);
  // else
  //     printf("There is no root-to-leaf path with sum %d\n", sum);
}
