#include <stdio.h>
#include <stdlib.h>

// Define the structure for an employee node
typedef struct Node {
char SSN[20];
char Name[20];
char Dept[20];
char Designation[20];
float Sal;
char PhNo[15];
struct Node* prev;
struct Node* next;
} Node;

// Function to create a new node
Node* createNode() {
	Node* newNode=(Node*)malloc(sizeof(Node));
	if(newNode==NULL){
		printf("Memory allocation failed\n");
		exit(1);
	}
	scanf("%s %s %s %s %f %s",newNode->SSN,newNode->Name,newNode->Dept,newNode->Designation,&newNode->Sal,newNode->PhNo);
	newNode->prev=NULL;
	newNode->next=NULL;
		return newNode;
   
}

// Function to insert a node at the end of the DLL
void insertAtEnd(Node** head, Node** tail) {
	Node* newNode=createNode();
	if(*head==NULL){
		*head=newNode;
		*tail=newNode;
		return;
	}
	(*tail)->next=newNode;
	newNode->prev=*tail;
	*tail=newNode;
}

// Function to display the DLL and count the number of nodes
void displayDLL(Node* head) {
	if(head==NULL){
		printf("Number of nodes: 0\n");
		return;
	}
	Node* temp=head;
	int count=0;
	while(temp!=NULL){
		printf("Name: %s ",temp->Name);
		count++;
		temp=temp->next;
		if(temp!=NULL){
			printf("");
		}
	}
	printf("Number of nodes: %d\n",count);
   
}

// Function to insert a node at the front of the DLL
void insertAtFront(Node** head, Node** tail) {
	Node* newNode=createNode();
	if(*head==NULL){
		*head=newNode;
		*tail=newNode;
		return;
	}
	newNode->next=*head;
	(*head)->prev=newNode;
	*head=newNode;
}

// Function to delete a node from the end of the DLL
void deleteAtEnd(Node** head, Node** tail) {
	if(*head==NULL){
		return;
	}
	if(*head==*tail){
		free(*head);
		*head=NULL;
		*tail=NULL;
		return;
	}
	Node* temp=*tail;
	*tail=(*tail)->prev;
	(*tail)->next=NULL;
	free(temp);
}

// Function to delete a node from the front of the DLL
void deleteAtFront(Node** head, Node** tail) {
	if(*head==NULL){
		return;
	}
	if(*head==*tail){
		free(*head);
		*head=NULL;
		*tail=NULL;
		return;
	}
	Node* temp=*head;
	*head=(*head)->next;
	(*head)->prev=NULL;
	free(temp);
}

// DEQ Operations

// Enqueue Front
void enqueueFront(Node** head, Node** tail) {
	insertAtEnd(head,tail);
}

// Enqueue Back
void enqueueBack(Node** head, Node** tail) {
	insertAtEnd(head,tail);
}

// Dequeue Front
void dequeueFront(Node** head, Node** tail) {
	deleteAtFront(head,tail);
}

// Dequeue Back
void dequeueBack(Node** head, Node** tail) {
	deleteAtEnd(head,tail);
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int choice,n;
    while (1) {
        printf("Menu:\n");
        printf("1. Create DLL of N Employees Data\n");
        printf("2. Display the status of DLL and count the number of nodes\n");
        printf("3. Perform Insertion at End of DLL\n");
        printf("4. Perform Insertion at Front of DLL\n");
        printf("5. Perform Deletion at End of DLL\n");
        printf("6. Perform Deletion at Front of DLL\n");
        printf("7. Enqueue Front (DEQ)\n");
        printf("8. Enqueue Back (DEQ)\n");
        printf("9. Dequeue Front (DEQ)\n");
        printf("10. Dequeue Back (DEQ)\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                
                printf("Enter the number of employees: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    insertAtEnd(&head, &tail);
                }
                break;
            case 2:
                displayDLL(head);
                break;
            case 3:
                insertAtEnd(&head, &tail);
                break;
            case 4:
                insertAtFront(&head, &tail);
                break;
            case 5:
                deleteAtEnd(&head, &tail);
                break;
            case 6:
                deleteAtFront(&head, &tail);
                break;
            case 7:
                enqueueFront(&head, &tail);
                break;
            case 8:
                enqueueBack(&head, &tail);
                break;
            case 9:
                dequeueFront(&head, &tail);
                break;
            case 10:
                dequeueBack(&head, &tail);
                break;
            case 11:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
