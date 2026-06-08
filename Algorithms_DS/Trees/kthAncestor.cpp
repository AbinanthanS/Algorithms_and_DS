#include<bits/stdc++.h>
using namespace std;

int kthAncestor(int n, vector<vector<int>> &edges, int v, int k) {

    vector<vector<int>> adj(n + 1);

    for (auto &e : edges) {
        int u = e[0];
        int w = e[1];

        adj[u].push_back(w);
        adj[w].push_back(u);
    }

    vector<int> parent(n + 1, -1);

    queue<int> q;
    q.push(1);
    parent[1] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int child : adj[node]) {
            if (parent[child] == -1) {
                parent[child] = node;
                q.push(child);
            }
        }
    }
    while (v != 0 && k--) v = parent[v];
    return (v == 0 ? -1 : v);
}

int main() {

    int n, k, v;
    cin >> n >> k >> v;

    vector<vector<int>> edges(n - 1, vector<int>(2));

    for (int i = 0; i < n - 1; i++) cin >> edges[i][0] >> edges[i][1];
    cout<<kthAncestor(n, edges, v, k);
    return 0;
}