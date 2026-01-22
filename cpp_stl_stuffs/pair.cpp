#include<bits/stdc++.h>
using namespace std;


void pair_array(){
	int a[] = {1,2,3};
	int b[] = {4,5,6};
	pair<int,int> p_arr[3];
	p_arr[0] = {1,4};
	p_arr[1] = {2,5};
	p_arr[2] = {3,6};
	//swap(p_arr[0],p_arr[2]);
	for(int i = 0;i<3;i++){
		cout<<p_arr[i].first<<" "<<p_arr[i].second<<endl;
	}
}

void pair_tie(){

    pair<int, int> pair1 = { 1, 2 };
    int a, b;
    tie(a,b) = pair1;
    cout << a << " " << b << "\n";

    pair<int, int> pair2 = { 3, 4 };
    tie(a, ignore) = pair2;

    // prints old value of b
    cout << a << " " << b << "\n";
    
    pair<int, pair<int, char> > pair3 = { 3, { 4, 'a' } };
    int x, y;
    char z;

    // tie(x,y,z) = pair3; Gives compilation error
    // tie(x, tie(y,z)) = pair3; Gives compilation error
    // Each pair needs to be explicitly handled
      tie(x,ignore) = pair3;
    tie(y, z) = pair3.second;
    cout << x << " " << y << " " << z << "\n";

  

}

void pair_swap(){ //The pairs must be of the same type. 
	pair<int,string> p1(1,"abcdef");
	pair<int,string> p2(2,"abc");
	
	swap(p2,p1);
	cout<<p1.first<<" "<<p1.second<<endl;
	
}

int main(){
	pair<int,string> p(1,"abcdef"),p1(p);
	
	p.first = 1;
	p.second = "abcd";//or
	
	p = {1,"abcde"};
	
	p = make_pair(2,"abc");//or
	
	
	//pair<int,string> p1(p);//copying 
	//cout<<p1.first<<" "<<p1.second<<endl;
	
   //cout<<p.first<<" "<<p.second<<endl;

     pair<string, double> p2("hello world", 1.23);
     //cout<<p2.first<<" "<<p2.second<<endl;
	
//	pair_swap();
	
//	pair_tie();
	
pair_array();
	
}
