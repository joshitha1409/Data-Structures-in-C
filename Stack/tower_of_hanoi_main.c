struct StackNode
{	int disk;
	int source;
	int auxiliary;
	int destination;
int step;
	struct StackNode *next;
};

// custom stack
struct MyStack
{	struct StackNode *top;
	int size;
};

struct MyStack *newStack()
{	//Make a stack
	struct MyStack *stack = (struct MyStack *) malloc(sizeof(struct MyStack));
	if (stack != NULL)
	{	stack->top = NULL;
		stack->size = 0;
		return stack;
	}
	else{
		printf("Stack overflow\n");
		return 0;
	}
}

int isEmpty(struct MyStack *stack){
	if (stack->size > 0 && stack->top != NULL){
		return 0;
	}
	else{
		return 1;
	}
}

// return top element of stack
struct StackNode *peek(struct MyStack *stack){
	if(isEmpty(stack)) return NULL;
	return stack->top;
}

//Create a new node of stack
struct StackNode *newNode(int disk, int source, int destination, int auxiliary,int step){
	struct StackNode *node=(struct StackNode*)malloc(sizeof(struct StackNode));
	node->disk=disk;
	node->source=source;
	node->destination=destination;
	node->auxiliary=auxiliary;
	node->step=step;
	node->next=NULL;
	return node;
}

// add node at the top of stack
void push(struct MyStack *stack, struct StackNode *node){
	node->next=stack->top;
	stack->top=node;
	stack->size++;
}

// Remove top element of stack
void pop(struct MyStack *stack){
	if(isEmpty(stack)) return;
	struct StackNode *temp=stack->top;
	stack->top=stack->top->next;
	free(temp);
	stack->size--;
}

// Displaying the movement of current disk 
void printResult(struct StackNode *node){
	printf("Move disk %d from tower [%c] to [%c]\n", node->disk, node->source, node->destination);
}

// Iterative tower of hanoi implementation
void towerOfHanoi(int total_disk){
	struct MyStack *stack=newStack();
	push(stack, newNode(total_disk,'A','C','B',0));
	while(!isEmpty(stack)){
		struct StackNode*curr=peek(stack);
		int disk=curr->disk;
		if(disk==1)
		{
			printResult(curr);
			pop(stack);
		}else if(curr->step==0)
		{
			curr->step++;
			push(stack,newNode(disk-1,curr->source,curr->auxiliary,curr->destination,0));
		}else if(curr->step==1){
			printResult(curr);
			curr->step++;
		}else if(curr->step==2){
			curr->step++;
			push(stack, newNode(disk-1,curr->auxiliary,curr->destination,curr->source,0));
		}else pop(stack);
	}
	free(stack);
}
