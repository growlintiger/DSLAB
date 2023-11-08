include<stdio.h>

#include<stdlib.h>

int r=-1,f=-1;

void insert(int ar[],int s)

{

int ele;

if((r+1)%s == f)

printf("Queue Overflow\n");

else

{

printf("Enter the element : ");

scanf("%d",&ele);

if(r==-1 || f==-1)

{

f=0;

r=0;

ar[f]=ele;

}

else

{

r=(r+1)%s;

ar[r]=ele;

}

printf("Element Inserted\n");

}

}

void delete(int s)

{

if(f==-1 || r==-1)

printf("Queue Underflow\n");

else

{

if(f==r)

{

f=-1;

r=-1;

}

else

f=(f+1)%s;

printf("Element deleted\n");

}

}

void traverse(int ar[],int s)

{

int i=f;

if(r==-1 || f==-1)

printf("Empty Queue\n");

else

{

printf("The queue is : \n");

while(i!=r)

{

printf("%d ",ar[i]);

i=(i+1)%s;

}
}
}
void main()

{

int s,ch;

printf("%d\n",ar[i]);
printf("Enter the size of the Queue\n");

scanf("%d",&s);

int ar[s];

printf("Enter 1 to insert an element\n");

printf("Enter 2 to delete an element\n");

printf("Enter 3 to traverse the queue\n");

printf("Enter 4 to exit\n");

while(1)

{

printf("\nEnter your choice\n");

scanf("%d",&ch);

switch(ch)

{

case 1: insert(ar,s);

break;

case 2: delete(s);

break;

case 3: traverse(ar,s);

break;

case 4: printf("Exitted\n");

exit(1);

default: printf("Invalid choice, try again\n");
}
}
}
