#include <stdio.h>
#include <stdlib.h>

// Structure for BST node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

typedef struct TreeNode* BSTNODE;

// Function to create a new node
BSTNODE createNode(int data) {
BSTNODE newNode=(BSTNODE)malloc(sizeof(struct TreeNode));
	if(newNode!=NULL){
		newNode->val=data;
		newNode->left=NULL;
		newNode->right=NULL;
	}
	return newNode;
}

// Function to insert a node into BST (duplicates go to the right)
BSTNODE insertNode(BSTNODE root, int data) {
	if(root==NULL){
		return createNode(data);
	}
	if(data<root->val){
		root->left=insertNode(root->left,data);
	}
	else{
		root->right=insertNode(root->right,data);
	}
	return root;
}

// In-order Traversal
void inorderTraversal(BSTNODE root) {
	if(root!=NULL){
		inorderTraversal(root->left);
		printf("%d ",root->val);
		inorderTraversal(root->right);
	}
}

// Pre-order Traversal
void preorderTraversal(BSTNODE root) {
	if(root!=NULL){
		printf("%d ",root->val);
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
}

// Post-order Traversal
void postorderTraversal(BSTNODE root) {
	if(root!=NULL){
		postorderTraversal(root->left);
		postorderTraversal(root->right);
		printf("%d ",root->val);
	}
}

// Search in BST
BSTNODE searchNodeInBST(BSTNODE root, int ele) {
	if(root==NULL|| root->val==ele){
		return root;
	}
	if(ele<root->val){
		return
			searchNodeInBST(root->left,ele);
	}else{
		return
			searchNodeInBST(root->right,ele);
	}
}
void freeTree(BSTNODE root){
	if(root!=NULL){
		freeTree(root->left);
		freeTree(root->right);
		free(root);
	}
}

int main() {
    BSTNODE root = NULL;
    int choice, data;

    while (1) {
        printf("1. Insert Node\n");
        printf("2. In-order Traversal\n");
        printf("3. Pre-order Traversal\n");
        printf("4. Post-order Traversal\n");
        printf("5. Search an element\n");
        printf("6. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Data: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;
            case 2:
                if (root == NULL)
                    printf("The tree is empty\n");
                else {
                    inorderTraversal(root);
                    printf("\n");
                }
                break;
            case 3:
                if (root == NULL)
                    printf("The tree is empty\n");
                else {
                    preorderTraversal(root);
                    printf("\n");
                }
                break;
            case 4:
                if (root == NULL)
                    printf("The tree is empty\n");
                else {
                    postorderTraversal(root);
                    printf("\n");
                }
                break;
            case 5:
                printf("Data: ");
                scanf("%d", &data);
                if (searchNodeInBST(root, data) == NULL)
                    printf("Element not found in the BST\n");
                else
                    printf("Element found in the BST\n");
                break;
            case 6:
                freeTree(root);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
