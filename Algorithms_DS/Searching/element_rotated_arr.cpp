#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v = {5,6,1,2,3};
    int n = v.size();
    int low = 0,high = n-1,target = 6;
    while(low<=high){
        int mid = low + (high-low)/2;
        if (v[mid] == target){
            cout<<mid;
            return 0;
        }
        if (v[low]<=v[mid]){
            if (v[low]<=v[mid]) low = mid+1;
            else high = mid-1;
        }else{
            if (v[mid]<=v[high]) high = mid-1;
            else low = mid+1;
        }
    }
    cout<<-1;
}

