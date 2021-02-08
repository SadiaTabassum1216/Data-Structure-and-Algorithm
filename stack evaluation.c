#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int top=-1,value;
char stack[100],infix[100],postfix[100];
int stack2[100];

//for push in string
void push(char a)
{
    top++;
    stack[top]=a;
}

//for pop in string
char pop()
{
    char a;

    a=stack[top];
    top--;

    return a;
}

//precedence
int precedence(char sign)
{
	if(sign == '^') return 3;
    else if(sign == '*' || sign == '/') return 2;
    else if(sign == '+' || sign == '-') return 1;
    else return 0;
}

//to convert the code from infix to postfix
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

				}push(infix[i]);
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

int top_int=-1;

//for push in int array
void push_int(int a)
{
    top_int++;
    stack2[top_int]=a;
}

//for pop in int array
int pop_int()
{
    int a;

    a=stack2[top_int];
    top_int--;

    return a;
}

//to evaluate the value of a postfix expression
void evaluation()
{
int i,j,x,a,b;
char temp[5];

    for(i=0;i<strlen(postfix);i++){
        if(postfix[i]>='0' && postfix[i]<='9'){
            j=0;
            while(postfix[i]!=' '){

                temp[j]=postfix[i];
                j++;
                i++;
            }
            temp[j]='\0';
            x=atoi(temp);//string to int
            push_int(x);//pushing to stack
            //continue;

        }
        else if(postfix[i]==' ');

        else if(postfix[i]=='+'||postfix[i]=='-'||postfix[i]=='*'||postfix[i]=='/'||postfix[i]=='^'){

                a=pop_int();
                b=pop_int();

                    if(postfix[i]=='+') x=a+b;
                    else if(postfix[i]=='-') x=b-a;
                    else if(postfix[i]=='*') x=a*b;
                    else if(postfix[i]=='/') x=b/a;
                    else if(postfix[i]=='^') x=pow(b,a);

                    push_int(x);
        }

    }
    value=stack2[top_int];

}

int main()
{

     printf("Enter the infix expression: ");
     gets(infix);

     conversion();
     evaluation();

     printf("Postfix expression: %s",postfix);
     printf("\nValue: %d",value);

return 0;
}
