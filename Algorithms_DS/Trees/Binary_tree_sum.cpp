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
  if (n == 0 || v[0] == -1) return nullptr;
  queue<Node*> q;
  Node* root = new Node(v[0]);
  q.push(root);
  int i = 1;
  while(!q.empty() && i<n){

    Node* curr = q.front();
    q.pop();
    if (i<n && v[i] != -1){
      curr->left = new Node(v[i]);
      q.push(curr->left);
    }
    i++;
    
    if (i<n && v[i] != -1){
      curr->right = new Node(v[i]);
      q.push(curr->right);
    }
    i++;

  }
  
  return root;
}

void sumofnodes(Node* root,int &sum){
  if (root == nullptr) return;
  sumofnodes(root->left,sum);
  sum += root->data;
  sumofnodes(root->right,sum);
  return;
}

int main(){
  vector<int> v;
  int x;
  while(cin>>x) v.push_back(x);
  int n = v.size();
  Node* root = buildtree(v,n);
  int sum = 0;
  sumofnodes(root,sum);
  cout<<sum;
  return 0;
}