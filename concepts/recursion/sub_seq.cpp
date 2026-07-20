#include<bits/stdc++.h>
using namespace std;

void sub_seq(vector<int> &v,vector<int> &d,int idx,int n){
    if (idx>=n){
        for (auto &i:d) cout<<i<<" ";
        if (d.empty()) cout<<"{}";
        cout<<"\n";
        return;
    }

    d.push_back(v[idx]);
    sub_seq(v,d,idx+1,n);
    d.pop_back();
    sub_seq(v,d,idx+1,n);    
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n),d;
    for (int i = 0;i<n;i++) cin>>v[i];
    sub_seq(v,d,0,n);
}