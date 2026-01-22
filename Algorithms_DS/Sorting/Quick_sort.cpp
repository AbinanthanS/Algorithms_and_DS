#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &arr,int low,int high){
	
	int pivot = arr[low];
	int i = low;
	int j = high;
	
	while(i<j){
		while(arr[i]<=pivot && i<=high-1){
			i++;
		}
		while(arr[j]>pivot&&j>= low+1){
			j--;
		}
		if (i<j) swap(arr[i],arr[j]);
	}
	
	swap(arr[low],arr[j]);
	
	return j;
}

void qs(vector<int> &arr,int low,int high){
	if (low<high){
		int pIndex = partition(arr,low,high);
			qs(arr,low,pIndex-1);
			qs(arr,pIndex+1,high);
		
	}
}

vector<int> quicksort(vector<int> arr){
	qs(arr,0,arr.size()-1);
	return arr;
}

int main(){
	vector<int> arr;
	int a,n;
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>a;
		arr.push_back(a);
	}
	arr = quicksort(arr);
	for(auto i : arr){
		cout<<i<<" ";
	}
	return 0;
}
