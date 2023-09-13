#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

struct node *start=NULL;

void create()
{
    int x;
    struct node *temp;
    printf(" enter the elements to be inserted:");
    scanf("%d", &x);

    struct node * ptr= (struct node *)malloc (sizeof (struct node));

    ptr->data=x;
    ptr->next=NULL;
    
    if (start==NULL)
        start=ptr; 
    else
    { 
        temp=start;
           while(temp->next!=NULL)
               temp=temp->next;
            temp->next=ptr;
    }
}

void traversal()
{
    
    struct node * temp;
    if (start==NULL)
    printf("list is empty");
    
    else {
    
        temp=start;
        while(temp!=NULL)
        {  printf("%d\t", temp->data);
             if(temp->next!=NULL)
              printf("->");
          
           temp=temp->next;
        }
    }
    
}


void insertAtbeg()
{
    
    int x;
    struct node *temp;
    printf(" enter the elements to be inserted:");
    scanf("%d", &x);

    struct node * ptr= (struct node *)malloc (sizeof (struct node));

    ptr->data=x;
    
    ptr->next=start;
    start=ptr;
    
}

void  insertAtPosition()
{
     int x,pos,i,c=0;
    struct node *temp;
    printf(" enter the elements to be inserted:");
    scanf("%d", &x);
       
    struct node * ptr= (struct node *)malloc (sizeof (struct node));

    ptr->data=x;
    ptr->next=NULL;
    
    temp=start;
    while(temp!=NULL)
       { c++;
        temp=temp->next;}
        
    printf("total no of nodes in list is %d\n", c);
     printf(" enter the position in between 0 to %d:", c-1);
        scanf("%d", &pos);
    
    
     if(start==NULL && pos!=0)
     printf("insertion can not possible");
     
     else{ if (pos==0)
              { 
                ptr->next=start;
                start=ptr;
              }
              else
              {  
                temp=start;
                for(i=0;i<pos-1;i++)
                   temp=temp->next;
                ptr->next=temp->next;
                temp->next=ptr;
              }
                
                
         
     }
}  

void  insertAfterElement()
{
    int ele1,ele2;
    struct node *temp;
    struct node ptr = (struct node)malloc(sizeof(struct node));
    printf("Enter the element after which you want to insert\n");
    scanf("%d",&ele1);
    printf("Enter the element you want to insert\n");
    scanf("%d",&ele2);

    ptr->data=ele2;
    ptr->next=NULL;

    temp=start;
    if(start==NULL)
        printf("List is empty");
    else
    {
        while(temp->data!=ele1)
            temp=temp->next;
        if(temp==NULL)
            printf("Element not found");
        else
        {
            ptr->next=temp->next;
            temp->next=ptr;
        }
    }
}

int main()
{   
    printf("\n 1  create the list\n 2  For insertion at starting\n 3  For insertion at end\n 4  For insertion at any position \n 5 Traversal \n6 Insert after element\n");
    printf(" 7 To exit\n");
    int choice;
    while (1) 
    {
        printf("\nEnter Choice :\n");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                create();
                break;
            case 2:
                insertAtbeg();
                break;
            case 3:
            create(); //insert at end
                break;
            case 4:
                insertAtPosition();
                break;
            case 5:
                traversal();
                break;
            case 6:
                insertAfterElement();
                break;
            case 7:
                exit(1);
            default:
                printf("Incorrect Choice\n");
        }
    }
  
        return 0;
}
