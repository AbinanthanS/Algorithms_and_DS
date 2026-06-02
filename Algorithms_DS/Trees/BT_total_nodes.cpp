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

Node* buildtree(vector<int> &v,int n){
  if (n == 0) return nullptr;
  queue<Node*> q;
  Node* root = new Node(v[0]);
  q.push(root);
  int i = 1;
  while(!q.empty() && i<n){
    Node* curr = q.front();
    q.pop();
    if (i<n){
      curr->left = new Node(v[i]);
      q.push(curr->left);
    }
    i++;
    
    if (i<n){
      curr->right = new Node(v[i]);
      q.push(curr->right);
    }
    i++;
  }
  return root;
}

int countleaf(Node* root){
  if (root == nullptr) return 0;
  return 1+countleaf(root->left)+countleaf(root->right);
}

int main(){
  int n;
  cin>>n;
  vector<int> v(n);
  for (int i = 0;i<n;i++) cin>>v[i];
  Node* root = buildtree(v,n);
  cout<<"Total Nodes: "<<countleaf(root);
  return 0;
}