#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a student node
typedef struct Node {
    char USN[10];
    char Name[20];
    char Branch[10];
    int Sem;
    char PhNo[10];
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode() {
   Node* head=(Node*)malloc(sizeof(Node));
	scanf("%s %s %s %d %s",head->USN,head->Name,head->Branch,&head->Sem,head->PhNo);
	head->next=NULL;
	return head;
}

// Function to insert a node at the front of the list
void insertAtFront(Node** head) {
   Node*newNode=createNode();
	newNode->next=*head;
	*head=newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(Node** head) {
   Node*newNode=createNode();
	if(*head==NULL){
		*head=newNode;
		return;
	}
	Node*t=*head;
	while(t->next!=NULL)
		t=t->next;
	t->next=newNode;
}

// Function to delete a node from the front of the list
void deleteAtFront(Node** head) {
  Node*t=*head;
	*head=(*head)->next;
	free(t);
}

// Function to delete a node from the end of the list
void deleteAtEnd(Node** head) {
    if(*head==NULL) return;
	Node*t=*head;
	if(t->next==NULL)
	{
		*head=NULL;
		return;
	}
	Node*p=NULL;
	while(t->next!=NULL)
	{
		p=t;
		t=t->next;
		free(t);
	}
p->next=NULL;
}

// Function to display the list and count the number of nodes
void displayList(Node* head) {
    int count=0;
	Node*t=head;
	while(t!=NULL)
	{
		printf("%s ",t->Name);
		t=t->next;
		count++;
	}
	printf("\nNumber of nodes: %d\n",count);
}

int main() {
    Node* head = NULL;
    int choice,n;
    while (1) {
        printf("Menu:\n");
        printf("1. Create SLL of N Students Data\n");
        printf("2. Display and count the number of nodes\n");
        printf("3. Perform Insertion at End of SLL\n");
        printf("4. Perform Insertion at Front of SLL\n");
        printf("5. Perform Deletion at End of SLL\n");
        printf("6. Perform Deletion at Front of SLL\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    insertAtFront(&head);
                }
                break;
            case 2:
                displayList(head);
                break;
            case 3:
                insertAtEnd(&head);
                break;
            case 4:
                insertAtFront(&head);
                break;
            case 5:
                deleteAtEnd(&head);
                break;
            case 6:
                deleteAtFront(&head);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
