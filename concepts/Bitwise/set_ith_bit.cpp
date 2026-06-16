#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i;
    cin >> n >> i;
    if (n & (1 << i)) cout << "Bit is set"; //((n >> i) & 1) alternate
    else cout << "Bit is not set";
    return 0;
}