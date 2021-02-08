#include<stdio.h>

void HeapSort(int A[],int n);
void BuildMaxHeap(int A[],int n);
void MaxHeapify(int A[],int n,int i);

int main()
{
    int n,i;

    printf("How many elements do you want to input?  ");
    scanf("%d",&n);

    int A[n];
    printf("Enter the elements:\n");
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }

    HeapSort(A,n);

    printf("The sorted array:\n");
    for(i=0;i<n;i++){
        printf("%8d ",A[i]);
    }
    printf("\n");

 return 0;
}

void HeapSort(int A[],int n)
{
    int i,temp;
    BuildMaxHeap(A,n);

    for(i=n-1;i>0;i--){
        //swap(A[i],A[0])
         temp=A[i];
         A[i]=A[0];
         A[0]=temp;

        MaxHeapify(A,i,0);
    }
}

void MaxHeapify(int A[],int n,int i)
{
    int l,r,largest,temp;
    largest=i;
    l=2*i+1;
    r=2*i+2;

    while(l<n && A[l]>A[largest]){
        largest=l;
    }

    while(r<n && A[r]>A[largest]){
        largest=r;
    }

    if(largest!=i){
        //swap(A[largest],A[i])
        temp=A[largest];
        A[largest]=A[i];
        A[i]=temp;
        MaxHeapify(A,n,largest);
    }
}

void BuildMaxHeap(int A[],int n)
{
    int i;

    for(i=n/2-1;i>=0;i--){
        MaxHeapify(A,n,i);
    }
}
