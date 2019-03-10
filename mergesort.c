#include <stdio.h>
void merge(int A[],int l[], int nl, int r[], int nr);
void mergesort(int A[], int n);
int main()
{
	int A[100],i,n;
	printf("Enter the no. of elements in the array.\n");
	scanf("%d",&n);
	printf("Enter the elements of the array.\n");
    for(i=0;i<n;i++)
       scanf("%d",&A[i]);
    mergesort(A,n);
    for(i=0;i<n;i++)
    	printf("%d ",A[i]); printf("\n");
	return 0;
}

void merge(int A[],int l[], int nl, int r[], int nr)
{
	int i,j,k;
	i=j=k=0;
    while((i<nl) && (j<nr)) 
    {
       if(l[i]<r[j]) 
          A[k]=l[i++];  
       else 
          A[k]=r[j++];
       k++;
    }
    while(i<nl) 
       A[k++]=l[i++];
    while(j<nr)
       A[k++]=r[j++];
}

void mergesort(int A[], int n)
{
	int nl,nr,i,j,mid;
	if(n<2) return;
	mid=n/2; nl=mid;  nr=n-mid;
	int l[nl],r[nr];
	for(i=0;i<mid;i++)
	   l[i]=A[i];  
	for((j=mid,i=0);j<n;(j++,i++))
	   r[i]=A[j];   
	mergesort(l,nl);
    mergesort(r,nr);
    merge(A,l,nl,r,nr);
}