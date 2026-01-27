#include<iostream>
using namespace std;
/*
constexpr is a feature added in C++ 11. 
The main idea is a performance improvement of programs by doing computations at compile time rather than run time.
*/
constexpr int square(int x) { return x*x; }
constexpr long int fact(int n) { return (n<=1) ? 1 : n*fact(n-1); }  
int main(){
    constexpr int x = square(5);
    constexpr long int y = fact(5);
    cout<<x<<"\n";
    cout<<y;
    return 0;
}