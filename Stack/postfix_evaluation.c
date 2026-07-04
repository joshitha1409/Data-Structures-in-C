#include<stdio.h>
#include<ctype.h>

int top=-1,stack[10],n=10;

void push(int x){
	if(top==n-1){
		printf("Stack overflow\n");
	} else{
		stack[++top]=x;
	}
}

int pop(){
	if(top==-1){
		printf("Stack underflow\n");
		return 0;
	} else{
		return stack[top--];
	}
}

void main(){
	int a,b,i;
	char exp[100];
	int error=0;

	printf("Postfix expression: ");
	scanf("%s",exp);

	for(i=0;exp[i]!='\0';i++){
		if(isdigit(exp[i])){
			push(exp[i]-'0');
		}
		else if(exp[i]=='+' || exp[i]=='*' || exp[i]=='-' || exp[i]=='/'){
			if(top<1){
				printf("Invalid postfix expression\n");
				error=1;
				break;
			}
			a=pop();
			b=pop();
			switch(exp[i]){
				case '*':push(b*a);break;
				case '-':push(b-a);break;
				case '+':push(b+a);break;
				case '/':
				if(a==0){
					printf("Division by zero error!\n");
					error=1;
				}else{
					push(b/a);
				}
				break;
				default:printf("Invalid operator:%c\n",exp[i]);
			}
		}
	}
	if(!error){
		if(top!=0){
			printf("Invalid postfix expression\n");
		}else{
			printf("Evaluated expression: %d\n",pop());
		}
	}
}
