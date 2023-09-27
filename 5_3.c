#include<stdio.h>
#include<stdlib.h>

struct node{
    int rows;
    int cols;
    int value;
    int data;
    struct node* next;
};

static int row;
static int col;

void traverse(struct node* temp){
    while(temp != NULL){
        printf("%d",temp->rows);
        printf("%d",temp->cols);
        printf("%d",temp->value);
        printf("\n");
        temp = temp -> next;
    }
}

void tuple_rep(int arr[row][col] , int non_zero){
    int tuple[non_zero+1][3];

    struct node* temp , *head , *current;
    temp = (struct node*)malloc(sizeof(struct node));
    temp -> rows = row;
    temp -> cols = col;
    temp -> value = non_zero;
    temp-> next = NULL;
    head = temp;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if(arr[i][j] != 0){
                current = (struct node*)malloc(sizeof(struct node));
                current -> rows = i;
                current -> cols = j;
                current -> value = arr[i][j];
                current -> next =  NULL;

                temp -> next = current;
                temp = current;
            }
        }
    }
    // to print the linkedlist 
    traverse(head);
}

void main(){
    int non_zero;

    printf("Enter the rows of the original matrix : \n");
    scanf("%d",&row);
    printf("Enter the number of columns in the original matrix : \n");
    scanf("%d",&col);
    printf("Enter the number of non zero values : \n");
    scanf("%d",&non_zero);

    int arr[row][col];

    printf("Enter the elements of the array : \n");

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    printf("\n");
    tuple_rep(arr,non_zero);
}
