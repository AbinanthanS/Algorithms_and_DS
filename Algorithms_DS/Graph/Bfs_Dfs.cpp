#include <bits/stdc++.h>
using namespace std;

void Dfs(vector<vector<int>> adj,int visited[],int node,vector<int> &ans){
    visited[node]++;
    ans.push_back(node);
    for (auto i:adj[node]){
        if (visited[i] == 0){
            Dfs(adj,visited,i,ans);
        }
    }
}

void dfs(vector<vector<int>> &adj){
    int visited[adj.size()+1] = {0};
    visited[0]++;
    vector<int> ans;
    Dfs(adj,visited,0,ans);
    cout<<"DFS : ";
    for (auto i:ans) cout<<i<<" ";
}

void bfs(vector<vector<int>> adj){
    int visited[adj.size()+1]= {0};
	queue<int> q;
	q.push(0);
	visited[0]++;
	vector<int> bfs;
	
	while(!q.empty()){
	    int node = q.front();
	    q.pop();
	    bfs.push_back(node);
	    
	    for (auto i:adj[node]){
	        if (visited[i] == 0){
	            visited[i]++;
	            q.push(i);
	        }
	    }

	}
	cout<<"BFS : ";
	for (auto i:bfs) cout<<i<<" ";cout<<"\n";
}

int main() {
	int n,m;cin>>n>>m;
	//adj list
	vector<vector<int>> adj(n+1);
	for (int i = 0;i<m;i++){
	    int u,v;cin>>u>>v;
	    adj[u].push_back(v);
	    adj[v].push_back(u);
	}
	bfs(adj);
	dfs(adj);
 }

