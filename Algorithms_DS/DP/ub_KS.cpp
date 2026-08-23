#include<bits/stdc++.h>
using namespace std;

int func(vector<int> &val,vector<int> &w,int idx,int cap, vector<vector<int>> &dp){
    
    if (idx == 0) if (w[0]<=cap) return (cap/w[0])*val[0];

    if (dp[idx][cap] != -1) return  dp[idx][cap];

    int ntake = 0 + func(val,w,idx-1,cap,dp);
    int take = INT_MIN;
    if (w[idx] <= cap) take = val[idx]+func(val,w,idx,cap-w[idx],dp);
    return dp[idx][cap] = max(ntake,take);
}         

int tabulation(vector<int> &val,vector<int> &w,int cap){
    int n = val.size();
    vector<vector<int>> dp(n,vector<int> (cap+1,0));

    for (int i = w[0];i<=cap;i++) dp[0][i] = (i/w[0])*val[0];

    for (int ind = 1;ind<n;ind++){
        for (int c = 0;c <= cap; c++){
            int ntake = dp[ind-1][c];
            int take = INT_MIN;
            if (w[ind]<=c) take = val[ind]+dp[ind][c-w[ind]];
            dp[ind][c] = max(ntake,take);
        }
    }
    return dp[n-1][cap];
}

int space_optimized(vector<int> &val,vector<int> &w,int cap){
    int n = val.size();
    vector<int> prev(cap+1,0),cur(cap+1,0);
    
    for (int i = w[0];i<=cap;i++) prev[i] = (i/w[0])*val[0];

    for (int ind = 1;ind<n;ind++){
        for (int c = 0;c <= cap; c++){
            int ntake = prev[c];
            int take = INT_MIN;
            if (w[ind]<=c) take = val[ind] + prev[c-w[ind]];
            cur[c] = max(ntake,take);
        }
        prev = cur;
    }
    return prev[cap];

}

int main(){
    int n;
    cin>>n;
    vector<int> val(n),w(n);
    for (int i = 0;i<n;i++) cin>>w[i];
    for (int i = 0;i<n;i++) cin>>val[i];
    int cap;
    cin>>cap;
    vector<vector<int>> dp(n,vector<int>(cap+1,-1));
    //int ans = func(val,w,n-1,cap,dp);
    //int ans = tabulation(val,w,cap);
    int ans = space_optimized(val,w,cap);
    cout<<ans;
    return 0;
}