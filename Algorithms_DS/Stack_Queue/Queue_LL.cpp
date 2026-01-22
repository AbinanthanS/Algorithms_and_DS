#include<iostream>
using namespace std;

struct Node{
	int data;
	struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

int isempty(){
	return front == NULL;
}

void enqueue(int value){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if (!newNode){
		cout<<"memory allocation failed"<<endl;
		return;
	}
	newNode->data = value;
	newNode->next = NULL;
	
	if (rear == NULL){
		front = rear = newNode;//newNode is the both front and rear
		return;
	}
	rear->next = newNode;
	rear = newNode;
}

int dequeue(){
	if (isempty()){
		cout<<"underflow"<<endl;
		return -1;
	}
	struct Node* temp = front;
	int deq_value = front->data;
	front = front->next;
	if (front == NULL){
		rear = NULL;
	}
	free(temp);
	return deq_value;
}

int get_front(){
	if(isempty()){
		cout<<"queue is empty"<<endl;
		return -1;
	}else{
		return front->data;
	}
}

void display(){
	if (isempty()){
		cout<<"queue is empty"<<endl;
	}else{
		struct Node* temp = front;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp= temp->next;
		}
		cout<<endl;
	}
}

int main(){
	enqueue(5);
	enqueue(4);
	enqueue(3);
	enqueue(2);
	enqueue(9);
	display();
	cout<<get_front();
	cout<<"\n";
	dequeue();
	display();
	cout<<get_front();
	
	
}
