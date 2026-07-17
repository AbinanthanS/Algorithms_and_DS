// #include<bits/stdc++.h>
// using namespace std;

// int bfs(vector<vector<int>> &v,int r,int c){
    
//     int n = v.size(),m = v[0].size();
//     vector<vector<int>> dist(n,vector<int>(m,0));
//     queue<pair<pair<int,int>,int>> q;
    
//     q.push({{r,c},1});

//     int drow[4] = {-1,1,0,0};
//     int dcol[4] = {0,0,-1,1};

//     int mx_path = 0;
//     while(!q.empty()){
//         int row = q.front().first.first;
//         int col = q.front().first.second;
//         int l = q.front().second;
//         q.pop();
//         mx_path = max(mx_path,l);
//         for (int i = 0;i<4;i++){
//             int nr = drow[i]+row;
//             int nc = dcol[i]+col;
//             if ((nr < n && nr>=0) && (nc < m && nc >=0)){
//                 if (v[row][col] < v[nr][nc] && dist[nr][nc] < l+1){
//                     q.push({{nr,nc},l+1});
//                     dist[nr][nc] = l+1;
//                 }
//             }
//         }
//     }
//     return mx_path;
// }

// int main(){

//     int n,m;
//     cin>>n>>m;

//     vector<vector<int>> v(n,vector<int>(m));
//     for (int i = 0;i<n;i++){
//         for (int j = 0;j<m;j++){
//             cin>>v[i][j];
//         }
//     }

//     int mx_path = 0;
//     for (int i = 0;i<n;i++){
//         for (int j = 0;j<m;j++){
//             mx_path = max(mx_path,bfs(v,i,j));
//         }
//     }
//     cout<<mx_path;
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> v;
vector<vector<int>> memo;

int drow[4] = {-1, 1, 0, 0};
int dcol[4] = {0, 0, -1, 1};

int dfs(int r, int c) {
    if (memo[r][c] != 0) return memo[r][c]; // already computed

    int best = 1; // path of length 1 (just this cell)
    for (int i = 0; i < 4; i++) {
        int nr = r + drow[i];
        int nc = c + dcol[i];
        if (nr >= 0 && nr < n && nc >= 0 && nc < m && v[nr][nc] > v[r][c]) {
            best = max(best, 1 + dfs(nr, nc));
        }
    }
    return memo[r][c] = best;
}

int main() {
    cin >> n >> m;
    v.assign(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> v[i][j];

    memo.assign(n, vector<int>(m, 0));

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ans = max(ans, dfs(i, j));

    cout << ans;
    return 0;
}
