#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *lptr;
    struct node *rptr;
 };

int arr[] = {1, 9, 4, 7, 6, 2, 3, 11, 88, 34, 66, 74};

struct node * insert_bst(struct node **, int);
void print_preorder (struct node *);
void pd (struct node *);
int print_levelorder(struct node *head, int n);

int main()
{
    int n = sizeof(arr)/sizeof(int);
    int i,j=1;
    struct node *root = NULL;
    for (i =0; i < n; i++)
        root = insert_bst (&root,arr[i]);
/*
    printf ("**************Preorder******************\n");
    print_preorder(root);
    printf ("\n");
    printf ("digraph graphName{\n");
    pd(root);
    printf ("}\n");
*/
   do{
    i =print_levelorder (root, j++);
    printf ("\n");
    }while (i);
}

int print_levelorder (struct node *head, int n)
{
    int x, y;
    if (head == NULL)
        return 0;
    if (n == 1)
    {
        printf ("%d\t",head->data);
        return 1;
    }
    x = print_levelorder (head->lptr, n-1);
    y = print_levelorder (head->rptr, n-1);
    return (x || y);
}  

void pd (struct node *root)
{
    if (root == NULL)
        return;

    if (root->lptr == NULL && root->rptr == NULL)
    {
        //printf ("%d->%s\n",root->data,"LEND");
        //printf ("%d->%s\n",root->data,"REND");
    }

    if (root->lptr)
    {
        printf ("%d->%d\n",root->data,root->lptr->data);
  
        pd(root->lptr);
    }

     if (root->rptr)
    {

        printf ("%d->%d\n",root->data,root->rptr->data);
        pd(root->rptr);
    }
}



void print_preorder (struct node *head)
{
    if (head == NULL)
        return;
     print_preorder(head->lptr);
     printf ("%d \t",head->data);
    print_preorder(head->rptr);
}


struct node *
insert_bst(struct node ** root, int data)
{
     struct node *head;
     head = *root;
     struct node *tmp = NULL;
    tmp = (struct node *) malloc(sizeof(struct node));
    if (tmp == NULL)
    {
        printf ("No memory exiting\n");
        exit(0);
     }

    tmp->data = data;
    tmp->lptr = NULL;
    tmp->rptr = NULL;

    if (head == NULL)
        return tmp;

    if (data <= head->data)
        head->lptr = insert_bst(&head->lptr, data);

    else if ( data > head->data)
        head->rptr = insert_bst (&head->rptr, data);

    else
        printf ("found duplicate value = %d omitting..\n",data);

    //return head; 
}

