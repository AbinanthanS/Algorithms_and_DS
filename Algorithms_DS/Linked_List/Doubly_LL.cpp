#include<iostream>
using namespace std;

struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node* createNode(int data){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if (newNode == NULL){
		cout<<"memory allocation failed"<<endl;
		return NULL ;
	}
	newNode->data = data;
	newNode->next = NULL;
	newNode->next = NULL;
	
	return newNode;
}

void display(struct Node* head){
	struct Node* temp = head;
	while (temp != NULL){
		cout<<temp->data<<"->";
		temp = temp->next;
	}
	cout<<"NULL\n";
}

void display_reverse(struct Node* head){
	if (head == NULL){
		cout<<"list empty\n";
		return;
	}
	struct Node* temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	while(temp != NULL){
		cout<<temp->data<<"<-";
		temp = temp->prev;
	}
	cout<<"\n";
}

void insert_begin(struct Node** head,int data){
	struct Node* newNode = createNode(data);
	if (*head == NULL){
		*head = newNode;
		return;
	}
	newNode->next = *head;
	(*head)->prev = newNode;
	*head = newNode;
}

void insert_end(struct Node**head,int data){
	struct Node* newNode = createNode(data);
	if(*head == NULL){
		*head = newNode;
		return;
	}
	struct Node* temp = *head;
	
	while(temp->next!= NULL){
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
	newNode->next = NULL;
}

void insert_atpos(struct Node**head,int data,int position){
	struct Node* newNode = createNode(data);
	if (position == 0){
		newNode->next = *head;
		(*head)->prev = newNode;
		*head = newNode;
		return;
	}
	struct Node* temp = *head;
	for (int i = 0;i<position -1 && temp != NULL;i++){
		temp = temp->next;
	}
	if (temp == NULL){
		cout<<"position out of bounds"<<endl;
		free(newNode);
		return;
	}
	if (temp->next != NULL){
		temp->next->prev =newNode;
	}
	newNode->next = temp->next;
	temp->next = newNode;
	
}

void delete_begin(struct Node**head){
	if (*head == NULL){
		cout<<"empty list"<<endl;
		return;
	}
	struct Node* temp = *head;
	*head = (*head)->next;
	free(temp);
}

void delete_byvalue(struct Node**head,int value){
	if (*head == NULL){
		cout<<"empty list\n";
		return;
	}
	struct Node* temp = *head;
	if(temp->data == value){
		*head = temp->next;
		if (*head != NULL){
			(*head)->prev = NULL;
		}
		free(temp);
		return;
	}
	
	while(temp != NULL && temp->data != value){
		temp = temp->next;
	}
	if (temp == NULL){
		cout<<value;
		return;
	}
	
	if (temp->next != NULL){
		temp->next->prev = temp->prev;
	}
	if (temp->prev != NULL){
		temp->prev->next = temp->next;
	}
	free(temp);
}

int main(){
	struct Node* node1 = NULL;
	//node1->next = NULL;
	insert_begin(&node1,5);
	insert_end(&node1,6);
	//delete_begin(&node1);
	insert_atpos(&node1,7,2);
	delete_byvalue(&node1,5);
	display(node1);
	//display_reverse(node1);
return 0;
}
