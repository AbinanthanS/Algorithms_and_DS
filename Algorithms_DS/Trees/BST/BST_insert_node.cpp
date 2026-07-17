#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  Node* left;
  Node* right;
  Node(int x){
    data = x;
    left = right = nullptr;
  }
};

Node* bst(Node* root,int val){
  if (root == nullptr) return new Node(val);
  if (root->data > val) root->left = bst(root->left,val);
  else root->right = bst(root->right,val);
  return root;
}


void insert(Node* root,int val){
  
  if (root == nullptr) return;
  
  if (root->data > val){
    if (root->left == nullptr){
      root->left = new Node(val);
      return;
    }
    insert(root->left,val);
  }
  else{
    if (root->right == nullptr){
      root->right = new Node(val);
      return;
    }
    insert(root->right,val);
  }
}

void inot(Node* root){
  if (root == nullptr) return;
  inot(root->left);
  cout<<root->data<<" ";
  inot(root->right);
}

int main(){
  int n;
  cin>>n;
  Node* root = nullptr;
  for (int i = 0;i<n;i++){
    int val;
    cin>>val;
    root = bst(root,val);
  }
  int node;
  cin>>node;
  insert(root,node);
  inot(root);
  return 0;
}