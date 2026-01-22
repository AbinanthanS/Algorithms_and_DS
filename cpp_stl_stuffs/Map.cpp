#include<bits/stdc++.h>
using namespace std;

void print(unordered_map<int,string> m){
	cout<<m.size()<<endl;
	for (auto i:m){
		
		cout<<i.first<<" "<<i.second<<endl;
	}
}

int main(){
	unordered_map<int,string> m;
	m[1]= "abc";// O(log(n))  //un-map O(1)
	m[2]= "abcd";
	m[3]= "abcde";
	m.insert({4,"abcdef"});
	m[5] = "abb";
//	m.clear();
//	m.erase(3);// O(log(n)) 
	auto it = m.find(1); // O(log(n)) //un-map log(1)
	if (it != m.end()) m.erase(it);
	//for (auto it = m.begin();it != m.end();++it) cout<<(*it).first<<" "<<(*it).second<<endl;
	print(m);
}
