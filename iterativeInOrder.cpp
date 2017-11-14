#include <stdio.h>
#include <stack>

using namespace std;

struct node{
  int data;
  node* right;
  node* left;
};

node* newNode(int value){
  node* ret=new node();
  ret->left=NULL;
  ret->right=NULL;
  ret->data=value;
  return ret;
}

void inOrderPrint(node* root){
  if(root==NULL) return;
  stack<node*> stck;
  while(true){
    if(root!=NULL){
      stck.push(root);
      root=root->left;
    }else{
      if(stck.size()==0) break;
      root=stck.top();
      stck.pop();
      printf("%3d",root->data);
      root=root->right;
    }
  }
  printf("\n");
}


//Test case from GEEKS FOR GEEKS
int main(){
  node *root = newNode(10);
  root->left= newNode(8);
  root->right= newNode(3);
  root->left->left= newNode(3);
  root->left->right= newNode(5);
  root->right->left= newNode(2);
  inOrderPrint(root);
}
