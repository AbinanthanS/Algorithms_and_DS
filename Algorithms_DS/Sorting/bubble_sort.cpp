#include<bits/stdc++.h>
using namespace std;

void Bubble_Sort(int arr[],int n)
{
	for (int step = 0;step<n-1;step++){
	 for (int i=0;i<n-step-1;i++){
		if (arr[i]>arr[i+1]) swap(arr[i],arr[i+1]);
	 }
        }	
}

int main(){

	int n;
	cin>>n;

	vector<int> arr(n);

	for (int i = 0;i<n;i++) cin>>arr[i];

	Bubble_Sort(arr.data(),n);
	
	for (int i = 0;i<n;i++) cout<<arr[i]<<" ";
	
	return 0;
}
