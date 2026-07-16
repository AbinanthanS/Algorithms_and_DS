#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v = {1,2,1,3,5,6,4};
    int n = v.size();
    int low = 0,high = n-1,ans = 0;
    while(low<=high){
        int mid = low + (high-low)/2;
        if ((mid == 0 || v[mid-1]<v[mid]) && (mid == n-1 || v[mid+1]<v[mid])){
            cout<<v[mid];
            return 0;
        }
        if (v[mid+1]>v[mid]) low = mid+1;
        else high = mid-1;
    }
    cout<<v[ans];
}

