#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int d){
        data = d;
        left = right = nullptr;
    }
};

Node* buildtree(vector<int> &v, int n){
    if (v[0] == -1 || n == 0) return nullptr;
    int i = 1;
    queue<Node*> q;
    Node* root = new Node(v[0]);
    q.push(root);
    while(!q.empty()){
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

int height(Node* root){
    if (root == nullptr) return 0;
    return 1 + max(height(root->left),height(root->right));
}




int main(){
    int x;
    vector<int> v;
    while(cin>>x) v.push_back(x);
    int n = v.size();
    Node* root = buildtree(v,n);
    cout<<height(root);
}