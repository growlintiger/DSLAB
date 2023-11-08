//Example of input restricted dequeue
#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
}*START=NULL;
void insert(struct node *,struct node *,struct node *);
void delete(struct node *,struct node *,struct node *);
void delf(struct node *,struct node *,struct node *);
void delr(struct node *,struct node *,struct node *);
void trav(struct node *);
void main()
{
    int num;
    struct node *p,*tem,*front,*rear;
    printf("enter negative to terminate\n");
    printf("enter data\n");
    scanf("%d",&num);
    while(num>=0)
    {
        p=malloc(sizeof(struct node));
        if(START==NULL)
        {
            START=p;
            p->data=num;
            p->next=NULL;
            p->prev=NULL;
            front=START;
        }
        else
        {
            tem=START;
            while(tem->next!=NULL)
            tem=tem->next;
            p->data=num;
            p->next=NULL;
            p->prev=tem;
            tem->next=p;
        }
        printf("enter data\n");
        scanf("%d",&num);
    }
    rear=p;
    char ch;
    printf("enter 1 for insert\n2 for delete\n3 for trav\n");
    scanf(" %c",&ch);
    switch(ch)
    {
        case '1':insert(START,front,rear);
        break;
        case '2':delete(START,front,rear);
        break;
        case '3':trav(START);
    }
}
void insert(struct node *head,struct node *f,struct node *r)
{
    struct node *new;
    new=malloc(sizeof(struct node));
    printf("enter data\n");
    scanf("%d",&new->data);
    r->next=new;
    new->prev=r;
    new->next=NULL;
    trav(head);
}
void delete(struct node *head,struct node *f,struct node *r)
{
    printf("from which end you want to delete\n1 for front\n2 for end\n");
    char ch;
    scanf(" %c",&ch);
    switch(ch)
    {
        case '1': delf(head,f,r);
        break;
        case '2':delr(head,f,r);
    }
}
void delf(struct node *head,struct node *f,struct node *r)
{
    struct node *del;
    head=head->next;
    del=f;
    f=f->next;
    f->prev=NULL;
    free(del);
    trav(head);
}
void delr(struct node *head,struct node *f,struct node *r)
{
    struct node *del;
    del=r;
    r=r->prev;
    r->next=NULL;
    free(del);
    trav(head);
}
void trav(struct node *head)
{
    while(head)
    {
        printf("%d ",head->data);
        head=head->next;
    }
}