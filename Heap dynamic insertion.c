#include<stdio.h>

void HeapInsertion(int A[],int n,int value);
void BuildMinHeap(int A[],int n);
void MinHeapify(int A[],int n,int i);

int main()
{
    int n=0,i,A[100],x;

        for(i=0;;i++){
        printf("Insert element: ");
        scanf("%d",&x);
        if(x==-1) break;
        n++;

        HeapInsertion(A,n,x);
    }


    printf("The min heap:\n");
    for(i=0;i<n;i++){
        printf("%8d ",A[i]);
    }
    printf("\n");

 return 0;
}


void MinHeapify(int A[],int n,int i)
{
    int l,r,smallest,temp;
    smallest=i;
    l=2*i+1;
    r=2*i+2;

    while(l<n && A[l]<A[smallest]){
        smallest=l;
    }

    while(r<n && A[r]<A[smallest]){
        smallest=r;
    }

    if(smallest!=i){
        //swap(A[smallest],A[i])
        temp=A[smallest];
        A[smallest]=A[i];
        A[i]=temp;
        MinHeapify(A,n,smallest);
    }
}

void BuildMinHeap(int A[],int n)
{
    int i;

    for(i=n/2-1;i>=0;i--){
        MinHeapify(A,n,i);
    }
}


void HeapInsertion(int A[],int n,int value)
{
    A[n-1]=value;
    BuildMinHeap(A,n);
}
