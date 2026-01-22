#include<iostream>
using namespace std;

struct Node{
	int data;
	struct Node* next;
};

struct Node* createNode(int data){
	//memory allocation for new node
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if (newNode == NULL){
		cout<<"memory allocation failed"<<endl;
		return NULL;
	}
	newNode -> data = data;
	newNode -> next = NULL;
	return newNode; //returns address of new node
}

void displaylist(struct Node* head){
	struct Node* temp = head;
	while(temp!=NULL){
		cout<<temp->data<<" -> ";
	    temp = temp ->next;
	}
	cout<<"NULL"<<endl;
}

void insert_begin(struct  Node** head,int data){
	struct Node* newNode = createNode(data);
	newNode->next = *head; //links newnode to current head
	*head = newNode;//previous head points to new node making it head
}

void insert_end(struct Node** head,int data){
	
	struct Node* newNode = createNode(data);
	if (*head == NULL){
		*head = newNode;
		return;
	}
	struct Node* temp = *head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
}

void insert_atpos(struct Node** head,int data,int position){
	struct Node* newNode = createNode(data);
	if (position == 0){
		newNode->next= *head;
		*head = newNode;
		return;
	}
	
	struct Node* temp =  *head;
	for (int i = 0;i<position -1 && temp != NULL;i++){
		temp = temp->next;
	}
	
	if (temp == NULL){
		cout<<"position out of bounds"<<endl;
		return;
	}
	
	newNode->next = temp->next;
	temp->next = newNode;
	
	
}

void delete_begin(struct Node** head){
	if (*head == NULL){
		return; //empty list
	}
	struct Node* temp = *head;
	*head = (*head) -> next;
	free(temp);
}

void delete_atpos(struct Node** head,int position){
	
	if (*head == NULL){
		return;
	}
	
	struct Node* temp = *head;
	
	if (position == 0){
		*head = (*head)->next;
		free(temp);
		return;
	}
	
	for (int i = 0;i<position-1;i++){
		temp = temp->next;
	}
	if (temp == NULL){
		cout<<"position out of bound "<<endl;
		return;
	}
	
	struct Node* nodetodelete = temp->next;
	temp->next = nodetodelete->next;
	free(nodetodelete);
	
}

void delete_end(struct Node** head){
	if (*head == NULL){
		cout<<"list empty"<<endl;
		return;
	}
	if ((*head)->next == NULL){ //if lisit has one node it deletes
		free(*head);
		*head = NULL;
		return;
	}
	//traverse to second last node
	struct Node* temp = *head;
	while(temp->next->next != NULL){
		temp = temp->next;
	}
	
	free(temp->next);
	temp->next = NULL;
}

void delete_byData(struct Node**head,int data){
	if (*head == NULL){
		cout<<"list is empty"<<endl;
		return;
	}
	//if node to delete is head
	struct Node* temp = *head;
	if (temp->data == data){
		*head = temp->next;  //move the head pointer to next node
		free(temp); // free the old head
		return;
	}
	
	//traverse the list to find the node with the given value
	struct Node* prev = NULL;
	while(temp != NULL && temp -> data != data){
		prev = temp;
		temp = temp->next;
	}
	//if the value not found in the list
	if (temp == NULL){
		cout<<"node not found"<<endl;
		return;
	}
	prev->next = temp->next;
	free(temp);
}

void freelist(struct Node** head){
	struct Node* temp;
	
	while(*head != NULL){
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}

int main(){
	
	struct Node* node1 = NULL;
	//struct Node* node2 = createNode(1);
//	struct Node* node3 = createNode(2);
//	struct Node* node4 = createNode(3);
	
//	node1->next = node2;
//	node2->next = node3;
//	node3->next = node4;

	int a;
    for (int i = 0;i<5;i++){
    	cin>>a;
    	insert_end(&node1,a); 
	}
	insert_begin(&node1,6);  
	insert_begin(&node1,7); 
	
	insert_end(&node1,8);
	
	insert_atpos(&node1,9,7);
	
	//delete_begin(&node1);
	//delete_atpos(&node1,2);
	//delete_end(&node1);
//	delete_byData(&node1,3);
//	freelist(&node1); //free's entire list
	displaylist(node1);      // passing (head) can access the nodes but cannot change/modify
	
/*
	free(node1);
	free(node2);
	free(node3);
	free(node4);
*/
    return 0;
}
