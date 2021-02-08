#include<stdio.h>
#include<string.h>

int top=-1;
char stack[100], infix[100], postfix[100];

void push(char a)
{
    top++;
    stack[top]=a;
}

char pop()
{
    char a;

    a=stack[top];
    top--;

    return a;
}

int precedence(char sign)
{
	if(sign == '^') return 3;
    else if(sign == '*' || sign == '/') return 2;
    else if(sign == '+' || sign == '-') return 1;
    else if(sign=='(') return 0;
	else return -1;

}

void conversion(){
int i,k=0;

    for(i=0;i<strlen(infix);i++){

        if(infix[i]>='0' && infix[i]<='9'){
            postfix[k]=infix[i];
            k++;
        }
        else if(infix[i]=='^'||infix[i]=='*'||infix[i]=='/'||infix[i]=='+'||infix[i]=='-'){
            postfix[k]=' ';
            k++;

            if(top==-1)
                push(infix[i]);


            else{
               while(precedence(stack[top])>= precedence(infix[i]))
                {
				postfix[k] = pop();
				k++;
				postfix[k]=' ';
				k++;

                }
                push(infix[i]);
            }

        }
        else if(infix[i]=='('){
            push(infix[i]);
        }

        else if(infix[i]==')'){
            for(;stack[top]!='(';){
                postfix[k]=' ';
				k++;
                postfix[k]=pop();
                k++;
            }
            pop();
        }

    }
    while(top!=-1){
        postfix[k]=' ';
        k++;
        postfix[k]=pop();
        k++;
    }
        postfix[k]='\0';

}
int main()
{
     printf("Enter the infix expression: ");
     gets(infix);

     conversion();

     printf("Postfix expression: %s",postfix);

return 0;
}

