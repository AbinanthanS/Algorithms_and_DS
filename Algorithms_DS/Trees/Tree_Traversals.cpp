#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = nullptr;
    }
};

class Solution{
    public:

    Node* buildTree(vector<int> &v){
        int n = v.size();
        queue<Node*> q;
        Node* root = new Node(v[0]);
        q.push(root);

        int i = 1;
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            if (i<n && v[i] != -1){
                curr->left = new Node(v[i]);
                q.push(curr->left);
            }
            i++;
            if (i<n && v[i]!=-1){
                curr->right = new Node(v[i]);
                q.push(curr->right);
            }
            i++;
        }
        return root;
    }

    vector<vector<int>> levelOrder(Node* root){
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> level;
            int n = q.size();
            for (int i = 0;i<n;i++){
                Node* curr = q.front();
                q.pop();
                level.push_back(curr->data);
                if (curr->left != nullptr) q.push(curr->left);
                if (curr->right != nullptr) q.push(curr->right);
            }
            ans.push_back(level);
        }
        return ans;
    }

    void inOrder(Node* root){
        if (root == nullptr) return;
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }

    void postOrder(Node* root){
        if (root == nullptr) return;
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }

    void preOrder(Node* root){
        if (root == nullptr) return;
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }

};

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0;i<n;i++) cin>>v[i];

    Solution solution;
    Node* root = solution.buildTree(v);

    cout<<"IN-Order : ";
    solution.inOrder(root);
    cout<<"\n";

    cout<<"POST-Order : ";
    solution.postOrder(root);
    cout<<"\n";

    cout<<"PRE-Order : ";
    solution.preOrder(root);
    cout<<"\n";

    cout<<"LEVEL-Order : "<<"\n";
    vector<vector<int>> result = solution.levelOrder(root);
    int l = 1;
    for (auto i:result){
        cout<<"level "<<l<<": ";
        for (auto j:i) cout<<j<<" ";
        cout<<endl;
        l++;
    }
    return 0;
}