Swap(*a, *b]){
  int temp;
  temp = a;
  a=b;
  b=temp;
}

Heapify( int A[] , int i , int n){
 int l = 2i+1;
int r= 2i+2;
largest= i;
if(A[largest]<A[l] && l<n)
largest = l ;
if(A[largest]<A[r] && r<n)
largest = r ;

if(largest != i)
{
   Swap(&A[largest], &A[i]);
    Heapify( A , largest, n);
    return ;
}
}


Create_heaptree( int A[] , int n)
{ int i ;
For(i=(n-1)/2;i>=0;i--)
Heapify( A , i , n);
}

//Now create the main function and input elements of tree in a array

//Heapsort process steps
/*
1. Swap A[n-1] and A[0]
2. Delete the last element
3. Heapify to root 
*/
