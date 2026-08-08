#include<bits/stdc++.h>
using namespace std;

int func(vector<int> &v,int idx,int tar,vector<vector<int>> &dp){
    if (tar == 0) return 1;
    if (idx == 0) return (v[0] == tar ? 1 : 0);
  
    if (dp[idx][tar] != -1) return dp[idx][tar];
    int take = 0;
    if (v[idx]<=tar) take = func(v,idx-1,tar-v[idx],dp);
    int ntake = func(v,idx-1,tar,dp);
    return take+ntake;
}

int tabulation(vector<int> &v,int k,int n){
    vector<vector<int>> dp(n,vector<int> (k+1,0));

    dp[0][0] = 1;
    if (v[0]<=k) dp[0][v[0]] = 1;

    for (int ind = 1;ind<n;ind++){
        for (int tar = 0;tar<=k;tar++){
            int take = 0;
            if (v[ind]<=tar) take = dp[ind-1][tar-v[ind]];
            int ntake = dp[ind-1][tar];
            dp[ind][tar] = take+ntake;
        }
    }
    return dp[n-1][k];
}

int space_optimized(vector<int> &v,int k,int n){

    vector<int> prev(k+1,0),cur(k+1,0);
    
    prev[0] = 1;
    if (prev[v[0]]<=k) prev[v[0]] = 1;

    for (int ind = 1;ind<n;ind++){
        for (int tar = 0;tar<=k;tar++){
            int take = 0;
            if (v[ind]<=tar) take = prev[tar-v[ind]];
            int ntake = prev[tar];
            cur[tar] = take+ntake;
        }
        prev = cur;
    }
    return prev[k];
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0;i<n;i++) cin>>arr[i];
    int tar;
    cin>>tar;
    vector<vector<int>> dp(n,vector<int> (tar+1,-1));
    //int ans = func(arr,n-1,tar,dp);
    //int ans = tabulation(arr,tar,n);
    int ans = space_optimized(arr,tar,n);
    cout<<ans;
    return 0;
}