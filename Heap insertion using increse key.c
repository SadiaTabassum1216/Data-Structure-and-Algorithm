#include<stdio.h>

void HeapIncreaseKey(int A[],int i,int key);
void HeapInsert(int A[],int n,int key);

int main()
{
    int n=0,i,A[100],x;

        for(i=1;;i++){
        printf("Insert element: ");
        //scanf("%d",&x);
        if(scanf("%d",&x)==EOF) break;
        n++;

        HeapInsert(A,n,x);
    }


    printf("The min heap:\n");
    for(i=1;i<=n;i++){
        printf("%8d ",A[i]);
    }
    printf("\n");

 return 0;
}

void HeapIncreaseKey(int A[],int i,int key)
{
    int temp;
    if(key>A[i]);//New key is larger than current key

    A[i]=key;

     while(A[i]<A[(i)/2] && i>1){
        temp=A[(i)/2];
        A[(i)/2]=A[i];
        A[i]=temp;
        i=(i)/2;
       }

}

void HeapInsert(int A[],int n,int key)
{
     A[n]=100000;
     HeapIncreaseKey(A,n,key);
}
