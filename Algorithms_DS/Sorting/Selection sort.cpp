#include<iostream>
using namespace std;

void Selection_sort(int arr[],int n){
	for(int i = 0;i<=n-2;i++){
		int min = i;
		for (int j =i;j<=n-1;j++){
			if(arr[j]<arr[min]) {   
			min = j; 
			}
		}
	swap(arr[min],arr[i]);
	}
}

int main(){
	
	int n;
	cin>>n;
	int arr[n];
	for (int i = 0;i<n;i++){
	    cin>>arr[i];
	}
	Selection_sort(arr,n);
	for(int i = 0;i<n;i++) cout<<arr[i]<<" ";
	return 0;
}
