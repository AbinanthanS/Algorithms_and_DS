#include <bits/stdc++.h>
using namespace std;


// Custom lower_bound: returns iterator to first element >= target
int lower_bound_custom(const vector<int>& a, int target) {
    int left = 0, right = a.size(); // right is exclusive
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (a[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left; // can be a.size() if all elements < target
}

// Custom upper_bound: returns iterator to first element > target
int upper_bound_custom(const vector<int>& a, int target) {
    int left = 0, right = a.size(); // right is exclusive
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (a[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left; // can be a.size() if all elements <= target
}


void firstGreater(vector<int>& a, int target) {
    auto it = upper_bound(a.begin(), a.end(), target);
    cout<<"index - "<<((it == a.end()) ? -1 : (it - a.begin()))<<'\n';
    cout<<"element - "<<a[(it == a.end() ? -1 : it - a.begin())];
    cout<<'\n';
}
void firstLess(vector<int>& a, int target) {
    auto it = lower_bound(a.begin(), a.end(), target);
    cout<<"index - "<<((it == a.begin())?-1: (it - a.begin()) - 1)<<'\n';
    cout<<"element - "<<a[(it == a.begin() ? -1 : it - a.begin())-1];
    cout<<'\n';
}
void firstGreaterEqual(vector<int>& a, int target) {
    auto it = lower_bound(a.begin(), a.end(), target);
    cout<<"index - "<<((it == a.end()) ? -1 : (it - a.begin()))<<'\n';  
    cout<<"element - "<<a[(it == a.end()) ? -1 : (it - a.begin())];
    cout<<'\n';
}
void firstLessEqual(vector<int>& a , int target) {
    auto it = upper_bound(a.begin(), a.end(), target);
    cout<<"index - "<<((it == a.begin()) ? -1:(it - a.begin())-1)<<'\n';
    cout<<"element - "<<a[(it == a.begin()) ? -1 : (it - a.begin())-1];
    cout<<'\n';
}
int main() {

	vector<int> v = {3,4,5,6,9,10};
	int target = 6;
	cout<<"firstGreater : "<<'\n';
	firstGreater(v,target);
	cout<<"firstLess : "<<'\n';
	firstLess(v,target);
	cout<<"firstGreaterEqual : "<<'\n';
	firstGreaterEqual(v,target);
	cout<<"firstLessEqual : "<<'\n';
	firstLessEqual(v,target);

}

