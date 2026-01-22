#include<bits/stdc++.h>
using namespace std;

void print(multiset<string> s){
	for (string val:s) cout<<val<<" ";cout<<endl;
}

int main(){

	//set<string> s; 
	multiset<string> s;
	s.insert("abc"); // log(n) same for multiset //un-set O(1)
	s.insert("def");
	s.insert("cef");
	s.insert("ghi");
	auto it = s.find("abc"); // log(n) " //un-set O(1)
	if (it != s.end()) s.erase(it);
	s.erase("abc");
	print(s);
	
}
