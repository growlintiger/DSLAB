#include <stdio.h>
#include<stdlib.h>

struct poly
    {
    int coeff,ex;
    struct poly *next;
     }*start=NULL;

void create()
{
    int c,e;
    struct poly *p,*temp;
    printf(" Enter the coefficient:");
    scanf("%d", &c);
    printf(" Enter the exponent:");
    scanf("%d", &e);
    

    p=(struct poly*)malloc(sizeof(struct poly));

    p->coeff=c;
    p->ex=e;
    p->next=NULL;
    
    if (start==NULL)
        start=p; 
    else
    { 
    temp=start;
    while(temp->next!=NULL)
        temp=temp->next;
        temp->next=p;
    }
}

void traverse()
{
    printf("\nThe polynomial:\n");
    struct poly * temp;
    if (start==NULL)
    printf("list is empty");
    
    else 
        {
        temp=start;
        while(temp!=NULL)
            {
            if(temp->ex!=0)
                printf("%dx^%d", temp->coeff,temp->ex);
            else
                printf("%d", temp->coeff);
            if(temp->next!=NULL)
                printf("+");
                
          
            temp=temp->next;
            }
        }
    
}

void main() 
    {
    printf("\n1 Create the Polynomial\n2 Traverse the polynomial\n");
    printf("3 To exit\n");
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
                traverse();
                break;
            case 3:
                exit(1);
                break;
            default:
                printf("Incorrect Choice\n");
        }
    }
    }
