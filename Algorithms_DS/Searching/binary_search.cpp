#include<bits/stdc++.h>
using namespace std;
int UpperBound(int n,vector<int> arr,int x){
    int l = 0,r = n-1;
    while(l<r){
        int mid = (l+r)/2;
        if(arr[mid]<=x) l = mid+1;
        else r = mid;
    }
    return l;
}
int LowerBound(int n,vector<int> arr,int x){
    int l = 0,r = n-1;
    while(l<r){
        int mid = (l+r)/2;
        if(arr[mid]<x) l = mid+1;
        else r = mid;
    }
    return l;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0;i<n;i++) cin>>arr[i];
    int x;
    cin>>x;
    cout<<"UpperBound: "<<arr[UpperBound(n,arr,x)]<<" index: "<<UpperBound(n,arr,x)<<endl;
    cout<<"LowerBound: "<<arr[LowerBound(n,arr,x)]<<" index: "<<LowerBound(n,arr,x)<<endl;
}
