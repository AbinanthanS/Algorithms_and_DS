#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0;i<n;i++) cin>>v[i];
    vector<vector<int>> ans;
    for (int num = 0;num < (1 << n);num++){
        vector<int> subset;
        for (int i = 0;i<n;i++) if (num&(1<<i)) subset.push_back(v[i]);
        ans.push_back(subset);
    }
    for (auto i:ans){
        if (i.empty()){
            cout<<"{}"<<"\n";
            continue;
        }
        for (auto j:i) cout<<j<<" ";
        cout<<"\n";
    }
}


/*

no.of subsets is always 2^n

in bitwise 2^n is written as (1<<n) [left shift]

*/