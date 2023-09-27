#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node {
    int info;
    struct node* next;
};

void display(struct node* temp){
    struct node* head = temp;
    do{
        printf("%d ", temp -> info);
        temp = temp -> next;
    }while(temp != head);
}

void main(){
    struct node *temp , *current , *head;
    int n;

    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter the information of the first node : \n");
    scanf("%d",&(temp->info));
    head = temp;
    temp -> next = head;
    printf("Enter 1 if you have more nodes to be added otherwise enter 2 \n");
    scanf("%d",&n);
    while(n != 2){
        current = (struct node*)malloc(sizeof(struct node));
        printf("Enter the value of the node : \n");
        scanf("%d",&(current -> info));
        current -> next = head;
        temp -> next = current;
        temp = current;

        printf("Enter 1 if you have more nodes to be added otherwise enter 2 \n");
        scanf("%d",&n);
    }

    display(head);
}
