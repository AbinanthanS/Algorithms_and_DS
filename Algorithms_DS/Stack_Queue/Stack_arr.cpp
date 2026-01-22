#include<iostream>
using namespace std;

#define MAX 5
int stack[MAX];
int top = -1;

int isfull(){
	return top == MAX-1;
}
int isempty(){
	return top == -1;
}
void push(int data){
	if (isfull()){
		cout<<"overflow"<<endl;
	}else{
		top++;
		stack[top] = data;
	}
}
int pop(){
	if (isempty()){
		cout<<"under flow"<<endl;
		return -1;
	}else{
		int value = stack[top];
		top--;
		return value;
	}
}
void display(){
	if (isempty()){
		for (int i = top;i>=0;i--){
			cout<<stack[i]<<" ";
		}
	}else{
		cout<<"stack is empty"<<endl;
	}
}
int top_e(){
	if (isempty()){
		cout<<"stack empty"<<endl;
		return -1;
	}else{
		return stack[top];
	}
}
int main(){
	
	push(5);
	push(6);
	cout<<top_e();
	
	return 0;
}
