#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m;
	cin>>n>>m;
    vector<int> adj[n+1];//vector of arrays
    set<int> s;
    for (int i = 0;i<m;i++){
        int u,v;cin>>u>>v;
        s.insert(u);s.insert(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for (auto i:s){
        for (auto a:adj[i]){
            cout<<a<<" ";
        }
        cout<<"\n";
    }
    
}

