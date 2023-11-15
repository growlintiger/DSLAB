 #include<stdio.h>

#include<stdlib.h>

struct bstnode

{

    int data;

    struct bstnode *left;

    struct bstnode *right;

};

struct bstnode *insert(struct bstnode *, int);

void inorder(struct bstnode *);

struct bstnode *delete(struct bstnode *, int);

struct bstnode *findmin(struct bstnode *);

int main()

{

    int num,key;

    struct bstnode *root=NULL;

    printf("enter negative number to terminate\n");

    printf("enter data\n");

    scanf("%d",&num);

    while(num>=0)

    {

        root=insert(root,num);

        printf("enter data\n");

        scanf("%d",&num);

    }

    printf("enter a key for deletion\n");

    scanf("%d",&key);

    root=delete(root,key);

    printf("modified BST inorder\n");

    inorder(root);

    return 0;

}

struct bstnode *insert(struct bstnode *root,int val)

{

    if(root==NULL)

    {

        struct bstnode *new=malloc(sizeof(struct bstnode));

        new->data=val;

        new->left=new->right=NULL;

        return new;

    }

    if(val<=root->data)

    {

        root->left=insert(root->left,val);

    }

    else

    {

        root->right=insert(root->right,val);

    }

    return root;

}

void inorder(struct bstnode *root)

{

    if(root!=NULL)

    {

    inorder(root->left);

    printf("%d ",root->data);

    inorder(root->right);

    }

}

struct bstnode *delete(struct bstnode *root,int key)

{

    if(key<root->data)

    {

        root->left=delete(root->left,key);

    }

    else if(key>root->data)

    {

        root->right=delete(root->right,key);

    }

    else

    {

        if(root->left==NULL)

        {

            struct bstnode *temp=root->right;

            free(root);

            return temp;

        }

        else if(root->right==NULL)

        {

            struct bstnode *temp=root->left;

            free(root);

            return temp;

        }

        else if(root->left==NULL&&root->right==NULL)

        {

            free(root);

        }

        else

        {

            struct bstnode *temp=findmin(root);

            root->data=temp->data;

            root->right=delete(root->right,temp->data);

        }

    }

    return root;

}

struct bstnode *findmin(struct bstnode *root)

{

    while(root->left!=NULL)

    {

        root=root->left;

    }

    return root;

}

