#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define STACK_MAX_SIZE 20
char stack[STACK_MAX_SIZE];
int top = -1;

// Return 1 if stack is empty, else return 0.
int isEmpty(){
	if(top==-1) 
		return 1;
	else return 0;
}

// Push the character into stack
void push(char x){
	stack[++top]=x;
}

// Pop a character from stack
char pop(){
	if(!isEmpty()) return stack[top--];
	else return '\0';
}
int priority(char x){
	if(x=='^') return 2;
	else if(x=='*'||x=='/'||x=='%') return 2;
	else if(x=='+'||x=='-') return 1;
	return 0;
}
void convertInfix(char * s){
	int len=strlen(s);
	char res[len+1];
	int j=0;
	for(int i=0;i<len;i++){
		if(isalnum(s[i])) res[j++]=s[i];
else if(s[i]=='(') push(s[i]);
		else if(s[i]==')'){
			while(!isEmpty() && stack[top]!='('){
				res[j++]=pop();
			}
			if(!isEmpty())pop();
			else{
			printf("Invalid infix expression: unbalaced paranthesis \n");
return;
			}
		}else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '%' || s[i] == '^'){
			while(!isEmpty() && priority(s[i]) <= priority(stack[top]))res[j++] = pop();
			push(s[i]);
		}else {
			printf("Invalid symbols used");
			return;
		}
	}
	while(!isEmpty()){
		if(stack[top]=='('){
			printf("Invalid infix expression\n");
			return;
		}
		res[j++] = pop();
	}
	res[j] = '\0';
	printf("Postfix expression: %s\n",res);
}

int main() {
    char exp[20];
    char *e;
    
    printf("Enter the expression: ");
    scanf("%s", exp);
    
    e = exp;
    convertInfix(e);

    return 0;  // Return gracefully from main
}
