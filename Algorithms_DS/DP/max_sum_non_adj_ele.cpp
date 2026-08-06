#include<bits/stdc++.h>
using namespace std;

//recursive + memoization TC O(n) SC O(n)+O(n) 
int func(vector<int> &v,int idx,vector<int> &dp){
    if (idx == 0) return v[idx];
    if (idx<0) return 0;
    if (dp[idx] != -1) return dp[idx];
    int p = v[idx] + func(v,idx-2,dp);
    int np = func(v,idx-1,dp);
    return dp[idx] = max(p,np);
}
//space complexity :O(n) (removed the stack space)
//tabulation (bottom up)

int func2(vector<int> &v,int n){
    vector<int> dp(n);
    dp[0] = v[0];
    for (int i = 1;i<n;i++){
        int p = v[i];
        if (i>1) p  += dp[i-2];
        int np = dp[i-1];
        dp[i] = max(p,np);
    }
    return dp[n-1];
}


int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0;i<n;i++) cin>>v[i];

    // vector<int> dp(n,-1);
    // cout<<func2(v,n);

    //space optimized:
    int prev = v[0],prev2 = 0;
    for (int i = 0;i<n;i++){
        int p = v[i];
        if (i>1) p += prev2;
        int np = prev;
        int curr = max(p,np);
        prev2 = prev;
        prev = curr;
    }
    cout<<prev;
}