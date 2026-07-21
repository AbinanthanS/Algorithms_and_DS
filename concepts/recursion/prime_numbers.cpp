#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n, int d = 2){
        if (n<2) return false;
        if (d*d>n) return true;
        if (n%d == 0) return false;
        return isPrime(n,d+1);
    }
    void print(int n,int range){
        if (n>range) return;
        if (isPrime(n)) cout<<n<<" ";
        print(n+1,range);
    }

int main(){
    int n,range;
    cin>>n>>range;
    print(n,range);
}