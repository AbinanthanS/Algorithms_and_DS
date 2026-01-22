#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m;
	cin>>n>>m;
	int adj[n+1][n+1];
	for (int i = 0;i<m;i++){
	    for (int j = 0;j<m;j++){
	        adj[i][j] = 0; 
	    }
	}
	for (int i = 0;i<m;i++){
	    int u,v;
	    cin>>u>>v;
	    adj[u][v]++;
	    adj[v][u]++;
	}
	for (int i = 0;i<m;i++){
	    for (int j = 0;j<m;j++){
	        cout<<adj[i][j]<<" ";
	    }
	    cout<<"\n";
	}
}
_
