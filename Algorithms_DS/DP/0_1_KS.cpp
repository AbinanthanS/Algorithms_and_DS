#include<bits/stdc++.h>
using namespace std;

int func(vector<int> &val,vector<int> &w,int idx,int cap, vector<vector<int>> &dp){
    if (idx == 0){
        if (w[0]<=cap) return val[0];
        return 0;
    }

    if (dp[idx][cap] != -1) return  dp[idx][cap];

    int ntake = 0 + func(val,w,idx-1,cap,dp);
    int take = INT_MIN;
    if (w[idx] <= cap) take = val[idx]+func(val,w,idx-1,cap-w[idx],dp);
    return dp[idx][cap] = max(ntake,take);
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
    int ans = func(val,w,n-1,cap,dp);
    cout<<ans;
    return 0;
}