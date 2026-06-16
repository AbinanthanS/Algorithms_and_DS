#include<bits/stdc++.h>
using namespace std;

void check_ithbit(){
    int a, i;
    cin >> a >> i;
    if (a & (1<<i)) cout<<"Bit is set"; // (n>>i) & 1
    else cout<<"Bit is not set";
    cout<<"\n";
    return;
}
int set_ithbit(){
    int a, i;
    cin >> a >> i;
    return (a | (1<<i));
}
int clear_bit(){
    int a,i;
    cin>>a>>i;
    return (a & ~(1<<i));
}
int main(){
    check_ithbit();
    cout<<set_ithbit();
    cout<<"\n";
    cout<<clear_bit();
    return 0;
}