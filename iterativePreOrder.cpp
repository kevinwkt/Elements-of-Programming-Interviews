#include <stdio.h>
#include <stack>

using namespace std;

struct node{
  int data;
  node* right;
  node* left;
};

node* newNode(int val){
  node* nd=new node();
  nd->left=NULL;
  nd->right=NULL;
  nd->data=val;
  return nd;
}

void preOrderPrint(node* root){
  if(root==NULL) return;  //if the given tree is empty, dont do shit
  stack<node*> stck;
  stck.push(root);
  while(stck.size()!=0){
    node* temp=stck.top();
    stck.pop();
    printf("%3d",temp->data);
    // cout<<temp->data<<endl;
    if(temp->right!=NULL) stck.push(temp->right);
    if(temp->left!=NULL) stck.push(temp->left);
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
  preOrderPrint(root);
}
