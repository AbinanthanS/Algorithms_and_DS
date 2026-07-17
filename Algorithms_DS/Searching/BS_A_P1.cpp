#include<bits/stdc++.h>
using namespace std;

bool check(int load,int k,vector<int> &v){
    int cnt = 1,sum = 0;
    for (int i = 0;i<v.size();i++){
        sum += v[i];
        if (sum > load){
            cnt++;
            sum = v[i];
        }
    }
    return (cnt>k)?false:true;
}

int main(){

    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    int mx = INT_MIN,sum = 0;
    for (int i = 0;i<n;i++){
        cin>>v[i];
        mx = max(mx,v[i]);
        sum += v[i];
    }

    int low = mx,high = sum,ans;
    while(low<=high){
        int mid = low+(high-low)/2;
        if (check(mid,k,v)){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    cout<<ans;
    return 0;
}