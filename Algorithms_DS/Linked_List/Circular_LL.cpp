#include<iostream>
using namespace std;

struct Node{
	int data;
	struct Node* next;
};

struct Node* createNode(int data){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if (newNode == NULL){
		cout<<"memory allocation failed"<<"\n";
		return NULL;
	}
	newNode -> data = data;
	newNode -> next = NULL;
	return newNode;
}

void displaylist(struct Node* head){
	if (head == NULL) {
        cout<<"List is empty.\n";
        return;
    }

    struct Node* temp = head;
    printf("List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to %d)\n", head->data);
}

void insert_begin(Node** head,int data){
	Node* newNode = createNode(data);
	
	if (*head == NULL){
		*head = newNode;
		newNode->next = *head;
		return;
	}
	
	Node* temp = *head;
	
	while(temp->next != *head){
		temp = temp->next;
	}
	
	newNode->next = *head;
	temp->next = newNode;
	*head = newNode;
}

void insertAtEnd(Node** head,int data){
	Node* newNode = createNode(data);
	
	if (*head == NULL){
		*head = newNode;
		newNode->next = *head;
		return;
	}
	
	Node* temp = *head;
	
	while(temp->next != *head){
		temp = temp->next;
	}
	
	temp->next = newNode;
	newNode->next = *head;
}

void delete_value(Node** head,int value){
	if(*head == NULL){
		cout<<"list is empty";
		return;
	}
	
	Node* temp = *head;
	
	//if the to delete is head node
	if (temp->data == value){
		while(temp->next != *head){ //traverse to the last node
			temp = temp->next;
		}
		
		if (*head == (*head)->next){ //if there is only one node in the list
			free(*head);
			*head = NULL;
		}else{
			Node* toDelete = *head;
			temp->next = (*head)->next;
			*head = (*head)->next;
			free(toDelete);
		}
		return;
	}
	//for nodes other than head
	temp = *head;
	while(temp->next != *head && temp -> next ->data != value){
		temp = temp->next;
	}
	//if node with the value is found 
	if (temp->next->data == value){
		Node* toDelete = temp->next;
		temp->next = temp->next->next;
		free(toDelete);
	}else{
		cout<<"not found"<<value;
	}
}

void freeList(struct Node** head) {
    if (*head == NULL) return;

    struct Node* temp = *head;
    struct Node* nextNode;

    // Traverse the list to free each node
    do {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    } while (temp != *head);

    *head = NULL;
}


int main(){
	 struct Node* head = NULL;

    // Insert elements into the circular linked list
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    delete_value(&head,30);
	displaylist(head);
	
	
	return 0;
}
