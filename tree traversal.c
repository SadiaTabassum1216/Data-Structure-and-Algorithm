#include<stdio.h>
#include<math.h>

void preorder(int index, int tree[],int pre[],int size);
void postorder(int index, int tree[],int post[],int size);
void inorder(int index, int tree[],int in[],int size);

int main()
{
int i,count=1,size,n,len;

printf("Level of the tree: ");
scanf("%d",&len);

printf("How many elements do you want as input? ");
scanf("%d",&n);

size=pow(2,len+1)-1;

int tree[size],pre[n],in[n],post[n];

for(i=1;i<size;i++){
    tree[i]=0;
    }

//creating a binary tree
printf("Enter the root: ");
scanf("%d",&tree[0]);
for(i=0;;i++){
        if(count==n)
        break;
    else{
    printf("Left child (Enter 0 to keep blank):  ");
    scanf("%d",&tree[2*i+1]);
        if(tree[2*i+1]!=0)
            count++;

    printf("Right child (Enter 0 to keep blank):  ");
    scanf("%d",&tree[2*i+2]);
        if(tree[2*i+2]!=0)
            count++;
    }
}

printf("\nThe array representation of the binary tree is: ");
for(i=0;i<size;i++){
    if(tree[i]==0)
        printf("_ ");
    else
        printf("%d ",tree[i]);
    }

//Output
preorder(0,tree,pre,size);//for preorder
printf("\n\nPre order: ");
for(i=0;i<n;i++){
    printf("%d ",pre[i]);
    }

postorder(0,tree,post,size);//for postorder
printf("\n\nPost order: ");
for(i=0;i<n;i++){
    printf("%d ",post[i]);
    }

inorder(0,tree,in,size);//for inorder
printf("\n\nIn order: ");
for(i=0;i<n;i++){
    printf("%d ",in[i]);
    }
printf("\n\n");


return 0;
}

//preorder
int temp1=0;
void preorder(int index, int tree[],int pre[],int size){


    if(index>=0 && index<size && tree[index]!=0){

        pre[temp1]=tree[index];
        temp1++;
        preorder(index*2+1,tree,pre,size);
        preorder(index*2+2,tree,pre,size);
        }
}


//postorder
int temp2=0;
void postorder(int index, int tree[],int post[],int size){


    if(index>=0 && index<size && tree[index]!=0){

        postorder(index*2+1,tree,post,size);
        postorder(index*2+2,tree,post,size);
        post[temp2]=tree[index];
        temp2++;

        }
}

//inorder
int temp3=0;
void inorder(int index, int tree[],int in[],int size){


    if(index>=0 && index<size && tree[index]!=0){

        inorder(index*2+1,tree,in,size);
        in[temp3]=tree[index];
        temp3++;
        inorder(index*2+2,tree,in,size);


        }
}


