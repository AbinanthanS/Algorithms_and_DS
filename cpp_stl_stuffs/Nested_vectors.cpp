#include<bits/stdc++.h>
using namespace std;
//array of vectors && vectors of vectors
void Vec_dis1(vector<pair<int,int>> &v){
	for (int i = 0;i<v.size();i++){
		cout<<v[i].first<<" "<<v[i].second<<endl;
	}
}

void Vec_dis2(vector<int> &v){
	for (int i = 0;i<v.size();i++){
	cout<<v[i]<<" ";
	}
	cout<<endl;
}

void Vec_pair(){
	vector<pair<int,int>> v; // = {{1,2},{3,4},{4,5}};

	int n;
	cin>>n;
	for (int i = 0;i<n;i++){
		int x,y;
		cin>>x>>y;
		v.push_back({x,y}); // 0r make_pair(x,y)
	}
	Vec_dis1(v);
}

void Vec_vec(){
	int N;
	cin>>N;
	vector<int> v[N];
	for (int i = 0;i<N;i++){
		int n;
		cin>>n;
		for (int j = 0;j<n;j++){
			int x;
			cin>>x;
			v[i].push_back(x);
		}
	}
	for (int i = 0;i<N;i++){
	    Vec_dis2(v[i]);
	}
}

void Vec_Vec(){
	int N;
	cin>>N;
	vector<vector<int>> v;
	for (int i = 0;i<N;i++){    
		int n;
		cin>>n;
		vector<int> temp; //(or) v.push_back(vector<int>());
		for (int j = 0;j<n;j++){
			int x;
			cin>>x;
			temp.push_back(x); //(or) v[i].push_back(x);
		}
		v.push_back(temp);
	}
	for(int i = 0;i<v.size();i++){
		Vec_dis2(v[i]);
	}
}

int main(){
	//Vec_pair();
	//Vec_vec();
	Vec_Vec();

	return 0;
}
