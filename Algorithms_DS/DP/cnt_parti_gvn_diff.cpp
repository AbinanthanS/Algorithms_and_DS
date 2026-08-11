#include<bits/stdc++.h>
using namespace std;

int func(vector<int> &v,int idx,int k){
   if (k == 0) return 1;
   if (idx == 0) return (v[0] == k?1:0);

   int take = 0;
   if (v[idx]<=k) take = func(v,idx-1,k-v[idx]);
   int ntake = func(v,idx-1,k);
   return take+ntake;
}

int tabulation(vector<int> &v, int k){
    int n = v.size();
    vector<vector<int>> dp(n,vector<int> (k+1,0));
    for (int i = 0;i<n;i++) dp[i][0] = 1;
    if (v[0]<=k) dp[0][v[0]] = 1;
    for (int ind = 1;ind<n;ind++){
        for (int tar = 1;tar<=k;tar++){
            int take = 0;
            if (v[ind]<=tar) take = dp[ind-1][tar-v[ind]];
            int ntake = dp[ind-1][tar];
            dp[ind][tar] = take+ntake;
        }
    }
    return dp[n-1][k];
}
int space(vector<int> &v, int k){
    int n = v.size();
    vector<int> prev(k+1,0),curr(k+1,0);
    if (v[0] == 0) prev[0] = 2;
    else prev[0] = 1;
    if (v[0] != 0 && v[0]<=k) prev[v[0]] = 1;
    for (int ind = 1;ind<n;ind++){
        for (int tar = 1;tar<=k;tar++){
            int take = 0;
            if (v[ind]<=tar) take = prev[tar-v[ind]];
            int ntake = prev[tar];
            curr[tar] = take+ntake;
        }
        prev = curr;
    }
    return prev[k];
}
int main(){
    int n,d;
    cin>>n>>d;
    vector<int> v(n);
    for (int i = 0;i<n;i++) cin>>v[i];
    int sum = 0;
    for (int i = 0;i<n;i++) sum += v[i];

    if ((sum+d)%2 != 0 || d>sum) return 0;

    int k = (sum+d)/2;
    int ans;
    //ans = func(v,n-1,k);
    //ans = tabulation(v, k);
    ans = space(v, k);
    cout<<ans;
}

/*

s1-s2 = d
s1+s2 = total sum


s1-d = s2
s1+s2 = total sum
s1+s1 = total sum + d
2*s1 = ts + d

*/