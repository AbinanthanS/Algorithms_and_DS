#include <iostream>
using namespace std;

string solve(string s,int i) {
    if (i == s.length()) return "";
    return solve(s,i+1) + s[i];
}

int main() {
    string t;
    cin >> t;
    cout<<solve(t,0);
}