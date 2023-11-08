#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*START=NULL;
void enqueue(struct node *,struct node *,struct node *);
void dequeue(struct node *,struct node *,struct node *);
void trav(struct node *);
void main()
{
    int num;
    struct node *p,*rear,*front,*temp;
    printf("enter any negative to terminate\nhigher value low priority and viceversa\n");
    printf("enter data\n");
    scanf("%d",&num);
    while(num>=0)
    {
        p=malloc(sizeof(struct node));
        if(START==NULL)
        {
            START=p;
            front=START;
            p->data=num;
            p->next=NULL;
        }
        else
        {
            temp=START;
            while(temp->next!=NULL)
            temp=temp->next;
            temp->next=p;
            p->data=num;
            p->next=NULL;
        }
        printf("enter data\n");
        scanf("%d",&num);
    }
    rear=p;
    char ch;
    printf("enter 1 for insertion\n2 for deletion\n3 for traversal\n");
    scanf(" %c",&ch);
    switch(ch)
    {
        case '1':enqueue(START,rear,front);
        break;
        case '2':dequeue(START,rear,front);
        break;
        case '3':trav(START);
    }
}
void enqueue(struct node *head,struct node *r,struct node *f)
{
    struct node *p;
    p=malloc(sizeof(struct node));
    printf("enter new data according to priority\n");
    scanf("%d",&p->data);
    p->next=NULL;
    r->next=p;
    r=r->next;
    trav(head);
}
void dequeue(struct node *head,struct node *r,struct node *f)
{
    head=head->next;
    struct node *del;
    del=f;
    f=f->next;
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