#include<iostream>
using namespace std;

struct Node{
	int data;
	struct Node* next;
};

struct Node* top = NULL;

int isempty(){
	return top == NULL;
}

void push(int value){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if (!newNode){
		cout<<"heap overflow"<<endl;
		return;
	}
	newNode->data = value;
	newNode->next = top;
	top = newNode;
	//cout<<value<<" pushed into stack"<<endl;
}

int pop(){
	if (isempty()){
		cout<<"stack underflow"<<endl;
		return -1;
	}else{
		struct Node* temp = top;
		int pop_value = top->data;
		free(temp);
		cout<<pop_value<<"popped from stack"<<endl;
		return pop_value;
	}
}
int top_e(){
	if (isempty()){
		cout<<"no element"<<endl;
		return -1;
	}else{
		return top->data;
	}
}

void display(){
	if (isempty()){
		cout<<"stack is empty"<<endl;
	}else{
		struct Node* temp = top;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp = temp->next;
		}
	}
}

int main(){
	push(5);
	push(6);
	push(7);
	display();
	cout<<top_e();
return 0;
}
