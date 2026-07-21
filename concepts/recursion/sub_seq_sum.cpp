#include<bits/stdc++.h>
using namespace std;


int sub_sum_cnt(vector<int> &v,int n,int idx,int sum,int k){
    if (idx == n){
        if (sum == k) return 1;
        return 0;
    }
    sum += v[idx];
    int l = sub_sum_cnt(v,n,idx+1,sum,k);
    sum -= v[idx];
    int r = sub_sum_cnt(v,n,idx+1,sum,k);
    return l+r;
}

void print_sub_sum(vector<int> &v,vector<int> &d,int n,int idx,int sum,int k){
    if (idx>=n) return;
    sum += v[idx];
    d.push_back(v[idx]);
    if (sum == k){
        for (auto i:d) cout<<i<<" ";
        cout<<"\n";
    }
    print_sub_sum(v,d,n,idx+1,sum,k);
    d.pop_back();
    sum -= v[idx];
    print_sub_sum(v,d,n,idx+1,sum,k);
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n),d;
    for (int i = 0;i<n;i++) cin>>v[i];
    int sum = 0;

    cout<<sub_sum_cnt(v,n,0,sum,k)<<"\n";

    print_sub_sum(v,d,n,0,sum,k);
    
    return 0;
}