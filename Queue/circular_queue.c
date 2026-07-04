#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Define the maximum size of the Circular Queue

typedef struct {
    char data[MAX];
    int front, rear, size;
} CircularQueue;

void initializeQueue(CircularQueue *q) {
    q->front=-1;
	q->rear=-1;
	q->size=MAX;
}

int isFull(CircularQueue *q) {
  if(q->front==(q->rear+1)%q->size)
	  return 1;
	else
	  return 0;
}

int isEmpty(CircularQueue *q) {
   if(q->front==-1)
	   return 1;
	else
	   return 0;
}

void insertElement(CircularQueue *q, char element) {
   if(isFull(q)==1){
	   printf("Queue Overflow\n");
	   return;
   }
	else{
		if(q->front==-1)
			q->front=0;
		q->rear=(q->rear+1)%q->size;
		q->data[q->rear]=element;
		printf("Inserted element '%c'\n",element);
	}
}

void deleteElement(CircularQueue *q) {
    if(isEmpty(q)==1){
		printf("Queue Underflow\n");
		return;
	}
	else{
		printf("Deleted element '%c'\n",q->data[q->front]);
		if(q->front==q->rear){
			q->front=-1;
			q->rear=-1;
	}
	else{
		q->front=(q->front+1)%q->size;
	}
}
}

void displayStatus(CircularQueue *q) {
    if(isEmpty(q)==1){
		printf("Queue is empty\n");
		return;
	}else{
		int i=(q->front);
		while(i!=(q->rear)){
			printf("%c ",q->data[i]);
			i=(i+1)%q->size;
		}
		printf("%c \n",q->data[q->rear]);
	}
}

int main() {
    int choice=0;
	char element;
	CircularQueue q;
	initializeQueue(&q);
    
    do {
        printf("Circular Queue Menu:\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Display Queue Status\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the character to insert: ");
                scanf(" %c", &element);
                insertElement(&q, element);
                break;
            case 2:
                deleteElement(&q);
                break;
            case 3:
                displayStatus(&q);
                break;
            case 4:
                printf("Exit\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
