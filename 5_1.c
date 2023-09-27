#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int info;
    struct node* next;
    struct node* prev;
};

void insert(struct node* temp , int pos){
    
    int count = 0;
    
    struct node* new = (struct node*)malloc(sizeof(struct node));
    printf("Enter the information of the new node : \n");
    scanf("%d",&(new->info));
    new -> prev = NULL;
    new -> next = NULL;
    
    while(temp != NULL){
        count++;
        if(count == pos-1){
            new -> next = temp -> next;
            (temp -> next) -> prev = new; 
            new -> prev = temp;
            temp -> next =  new;
        }
        temp = temp -> next;
    }
}

void delete(struct node* temp , int pos){
    int count = 0;
    while(temp != NULL){
        count++;
        if(count == pos-1){
            temp -> next = (temp -> next) -> next; 
            (temp -> next) -> prev = temp;
        }
        temp = temp -> next;
    }
}

void traverse(struct node* temp){
    while(temp != NULL){
        printf("%d ",temp -> info);
        temp = temp -> next;
    }
    printf("\n");
}

void previous(struct node* temp , int position){
    int count = 0;
    while(temp != NULL){
        count++;
        if(count == position){
            printf("%d ",(temp -> prev) -> info );
        }
        temp = temp -> next;
    }
}

void main(){
    struct node* temp , *current , *head;
    int choice;
    int position;
    int option;

    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter the information for the first node : \n");
    scanf("%d",&(temp -> info)); 
    temp -> prev = NULL;
    temp -> next = NULL;
    head = temp;

    printf("Enter 1 if you want to add more elements otherwise enter 2 : \n");
    scanf("%d",&choice);
    while(choice != 2){
        current = (struct node*)malloc(sizeof(struct node));
        printf("Enter the information of the new node : \n");
        scanf("%d",&(current-> info));
        temp -> next = current;
        current -> prev = temp;
        current -> next = NULL;

        temp = current;

        printf("Enter 1 if you want to add more elements otherwise enter 2 : \n");
        scanf("%d",&choice);
    }
    


    while(true){
        printf("Enter 1 to insert an element : \n");
        printf("Enter 2 to delete an element : \n");
        printf("Enter 3 to traverse through the list : \n");
        printf("Enter 4 to exit out of the menu : \n");
        scanf("%d",&option);

        switch(option){
            case 1 : 
                printf("Enter the position where you want to insert the element : \n");
                scanf("%d",&position);
                insert(head,position);
                break;
            case 2 : 
                printf("Enter the position from where you want to delete the element : \n");
                scanf("%d",&position);
                delete(head,position);
                break;
            case 3 : 
                printf("The traversed array is : \n");
                traverse(head);
                break;
            case 4 :
                printf("Exiting..."); 
                break;
        }
        if(option == 4){
            break;
        }
    }
}
