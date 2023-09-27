// page 1 question 4

#include <stdio.h>
#include <stdlib.h>

struct sparse
{
    int row;
    int col;
    int val;
};

void input(struct sparse *s)
{
    printf("Enter the row: ");
    scanf("%d", &s->row);
    printf("Enter the col: ");
    scanf("%d", &s->col);
    printf("Enter the val: ");
    scanf("%d", &s->val);
}

void display(struct sparse *s)
{
    printf("The row is: %d\n", s->row);
    printf("The col is: %d\n", s->col);
    printf("The val is: %d\n", s->val);
}

void inputMatrix(struct sparse *s, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("Enter the %d sparse matrix: \n", i + 1);
        input(&s[i]);
    }
}

void displayMatrix(struct sparse *s, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("The %d sparse matrix is: \n", i + 1);
        display(&s[i]);
    }
}

void add(struct sparse *s1, struct sparse *s2, struct sparse *s3)
{
    if (s1->row == s2->row && s1->col == s2->col)
    {
        s3->row = s1->row;
        s3->col = s1->col;
        s3->val = s1->val + s2->val;
    }
    else
    {
        printf("The addition is not possible\n");
        exit(0);
    }
}

void multiply(struct sparse *s1, struct sparse *s2, struct sparse *s3)
{
    if (s1->col == s2->row)
    {
        s3->row = s1->row;
        s3->col = s2->col;
        s3->val = s1->val * s2->val;
    }
    else
    {
        printf("The multiplication is not possible\n");
        exit(0);
    }
}

int main()
{
    struct sparse s1, s2, s3;
    printf("Enter the 1st sparse matrix: \n");
    input(&s1);
    printf("Enter the 2nd sparse matrix: \n");
    input(&s2);

    add(&s1, &s2, &s3);
    printf("The addition of the sparse matrix is: \n");
    display(&s3);

    multiply(&s1, &s2, &s3);
    printf("The multiplication of the sparse matrix is: \n");
    display(&s3);

    return 0;
}

