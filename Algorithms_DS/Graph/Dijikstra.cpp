#include<bits/stdc++.h>
using namespace std;

vector<int> dijikstra(int src,vector<vector<pair<int,int>>> adj,int n){
    vector<int> dist(n,INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,src});
    while(!pq.empty()){
        int node = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (d > dist[node]) continue;
        for (auto i:adj[node]){
            int v = i.first;
            int wt = i.second;
            if (d+wt<dist[v]){
                dist[v] = d + wt;
                pq.push({dist[v],v});
            }
        }
    }
    return dist;
}

int main(){
    vector<vector<int>> edges = {
        {0, 1, 1},
        {0, 2, 2},
        {1, 3, 4},
        {2, 3, 3},
        {1, 2, 0}
    };
    vector<vector<pair<int,int>>> adj(4);
    for (auto edge : edges){
        int u = edge[0],v = edge[1],wt = edge[2];
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    int n = adj.size();
    int src;
    cin>>src;
    vector<int> result = dijikstra(src,adj,n);
    for (int i = 0; i < result.size(); i++){
        if (result[i] == INT_MAX){
            cout << "Distance from source to node " << i << " is -1" << endl;
            continue;
        }
        cout << "Distance from source to node " << i << " is " << result[i] << endl;
    }
}