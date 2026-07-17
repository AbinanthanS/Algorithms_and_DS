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
  if (val<root->data) root->left = bst(root->left,val);
  else root->right = bst(root->right,val);
  return root;
}

//tarversal
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
  inot(root);
  return 0;
}