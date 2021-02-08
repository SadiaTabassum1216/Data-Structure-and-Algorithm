#include<stdio.h>

void HeapInsertion(int A[],int n,int value);
void BuildMinHeap(int A[],int n);
void MinHeapify(int A[],int n,int i);

int main()
{
    int n,i,A[100],x;

    printf("How many elements do you want to input? ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }

    BuildMinHeap(A,n);

    for(i=0;i<n;i++){
        printf("%d ",A[i]);
    }

    printf("\nInsert element: ");
    scanf("%d",&x);
    n++;

    HeapInsertion(A,n,x);

    for(i=0;i<n;i++){
        printf("%d ",A[i]);
    }


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
    //n++;
    A[n-1]=value;
    BuildMinHeap(A,n);

    //return n;
}
