#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    cout<<a<<" "<<b<<endl;
    a ^= b;
    b ^= a;
    a ^= b;
    cout<<a<<" "<<b;
    return 0;
}