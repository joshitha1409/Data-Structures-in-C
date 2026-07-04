#include <stdio.h>
#include <stdlib.h>

#define MAX_DEGREE 100

// Define the structure for a polynomial node
typedef struct Node {
    int coefficient;
    int degree;
    struct Node* next;
} Node;

// Function to create a new node
struct Node* createNode(int coefficient, int degree) {
	struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->coefficient=coefficient;
	newNode->degree=degree;
	newNode->next=NULL;
	return newNode;
}
// Function to insert a node at the end of the polynomial
void insertNode(Node** head, int coefficient, int degree) {
	struct Node *newNode=createNode(coefficient,degree);
	if(*head==NULL)
		*head=newNode;
	else {
		struct Node *temp=*head;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=newNode;
	}

}
// Function to display the polynomial
void displayPolynomial(struct Node* poly) {
	struct Node *temp=poly;
	while(temp!=NULL){
		printf("%dx^%d",temp->coefficient,temp->degree);
		temp=temp->next;
		if(temp!=NULL)
			printf(" + ");
	}
	printf("\n");


}
// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, Node* poly2) {
	struct Node *result=NULL;
	while(poly1!=NULL && poly2!=NULL){
		if(poly1->degree > poly2->degree){
			insertNode(&result,poly1->coefficient,poly1->degree);
			poly1=poly1->next;
		}else{
			int sum= poly1->coefficient+poly2->coefficient;
			if(sum!=0)
				insertNode(&result, sum,poly1->degree);
			poly1=poly1->next;
			poly2=poly2->next;
		}
		
	}
	while(poly1!=NULL){
		insertNode(&result,poly1->coefficient,poly1->degree);
		poly1=poly1->next;
	}while(poly2!=NULL){
		insertNode(&result,poly2->coefficient,poly2->degree);
		poly2=poly2->next;
	}
	return result;

}

int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;
    int numTerms1, numTerms2;
    scanf("%d", &numTerms1);
    for (int i = 0; i < numTerms1; i++) {
        int coefficient, degree;
        scanf("%d %d", &coefficient, &degree);
        insertNode(&head1, coefficient, degree);
    }
    scanf("%d", &numTerms2);
    for (int i = 0; i < numTerms2; i++) {
        int coefficient, degree;
        scanf("%d %d", &coefficient, &degree);
        insertNode(&head2, coefficient, degree);
    }
    displayPolynomial(head1);
    displayPolynomial(head2);
    Node* result = addPolynomials(head1, head2);
    displayPolynomial(result);
    return 0;
}
