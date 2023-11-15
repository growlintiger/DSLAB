#include<stdio.h>
#include<stdlib.h>
 struct node 
 {
    int data;
    struct node* left;
    struct node* right;
 };

 struct node* newnode(int x)
 {
    struct node *ptr=(struct node*)malloc(sizeof(struct node));

    ptr->data=x;
    ptr->left=NULL;
    ptr->right=NULL;

    return ptr;
 }

 struct node* insert(int x,struct node* temp)
 {
    if(temp==NULL)
    {
        return newnode(x);
        printf("Element Inserted\n");
    }
    else if(temp->data>x)
    {
        temp->left=insert(x,temp->left);
    }
    else
    {
        temp->right=insert(x,temp->right);
    }

 }

 struct node* search(int x,struct node* temp)
 {
    if(temp->data==x  || temp==NULL)
        return temp;
    else if(temp->data>x)
        search(x,temp->left);
    else
        search(x,temp->right);
 }

 void inorder(struct node* temp)
 {
    if(temp!=NULL)
    {
        inorder(temp->left);
        printf("%d ",temp->data);
        inorder(temp->right);
    }
 }

  void preorder(struct node* temp)
 {
    if(temp!=NULL)
    {
        printf("%d ",temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
 }
  void postorder(struct node* temp)
 {
    if(temp!=NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d ",temp->data);
    }
 }


 void main()
 {
    int x,ch;
    struct node* root=NULL;
    printf("Enter 1 to insert\n");
    printf("Enter 2 to delete\n");
    printf("Enter 3 to search\n");
    printf("Enter 4 to print in-order\n");
    printf("Enter 5 to print pre-order\n");
    printf("Enter 6 to print post-order\n");
    printf("Enter 7 to exit\n");
    while(1)
    {
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                if(root==NULL)
                {
                    printf("Enter the root of the tree : ");
                    scanf("%d",&x);
                    root=insert(x,root);
                }
                else
                {
                    printf("Enter the value of the node tree : ");
                    scanf("%d",&x);
                    insert(x,root);
                }
                break;
            case 2:
                break;
            case 3:
                printf("Enter the value of the node to be searched : ");
                scanf("%d",&x);
                if(search(x,root)==NULL)
                    printf("Element not found\n");
                else
                    printf("Element found\n");
                break;
            case 4:
                inorder(root);
                break;
            case 5:
                preorder(root);
                break;
            case 6:
                postorder(root);
                break;
            case 7:
                exit(1);
                break;
            default:
            printf("Invalid choice, try again\n");
        }
    }
 }
