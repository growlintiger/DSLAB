#include<stdio.h>
void insert(int *p,int);
void delete(int *p,int);
void trav();
void main()
{
    int stk1[20],n;
    printf("enter limit<20\n");
    scanf("%d",&n);
    for(int top=0;top<n;top++)
    {
        printf("enter data\n");
        scanf("%d",&stk1[top]);
    }
    char ch;
    printf("enter 1 for insertion\n2 for deletion\n");
    scanf(" %c",&ch);
    switch(ch)
    {
        case '1':insert(stk1,n);
        break;
        case '2':delete(stk1,n);
    }
}
void insert(int *stk1,int n)
{
    int new;
    printf("enter newly inserted data\n");
    scanf("%d",&new);
    stk1[n]=new;
    trav(stk1,n+1);
}
void delete(int *stk1,int n)
{
    int stk2[20],top2,m,top1;
    m=n;
    for(top2=0;top2<n;top2++)
    {
        stk2[top2]=stk1[--m];
    }
    int l;
    l=n-1;
    for(top1=0;top1<n-1;top1++)
    {
        stk1[top1]=stk2[--l];
    }
    trav(stk1,n-1);
}
void trav(int *p,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",p[i]);
    }
}