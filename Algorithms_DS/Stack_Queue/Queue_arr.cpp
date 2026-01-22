#include<iostream>
using namespace std;

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

int isempty(){
	return front == -1;
}
int isfull(){
	return rear == MAX-1;
}

void enqueue(int value){
	if(isfull()){
		cout<<"queue overflow"<<endl;
	}else{
		if(isempty()){
			front = 0;
		}
		rear++;
		queue[rear] = value;
	}
}

int dequeue(){
	if(isempty()){
		cout<<"queue underflow"<<endl;
		return -1;
	}else{
		int deq_value = queue[front];
		
		if (front == rear){
			front = rear = -1;
		}else{
			front++;
		}
		return deq_value;
	}
}

int get_front(){
	if (isempty()){
		cout<<"queue is empty"<<endl;
		return -1;
	}else{
		return queue[front];
	}
}

void display(){
	if (isempty()){
		cout<<"no elements"<<endl;
	}else{
		for (int i = front;i<=rear;i++){
			cout<<queue[i]<<" ";
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
	//cout<<get_front();
	dequeue();
	display();
}
