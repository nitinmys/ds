
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
 }; 

int arr[] = {1,2,3,4,5,6,7,10,-4,23,12,4,6};

struct node *
insert (struct node *head, int data)
{
    struct node *tmp;
    tmp = (struct node *) malloc (sizeof (struct node));
    if (NULL == tmp)
    {
        printf ("No memory exiting\n");
        exit(0);
    }

    tmp->data = data;
    tmp->next = NULL;
    if (head == NULL)
        head = tmp;
    else
    {
        tmp->next = head;
        head = tmp;
    }
  return head;
}

struct node * rev_n (struct node *head, int n, struct node **cur )
{
    int i;
    struct node *newlist = NULL;
    struct node * tail;
    tail = newlist;
    struct node *next_link;
    for (i = 0; i < n; i++)
    {
        if (head->next == NULL)
            break;
        next_link = head->next;
        head->next = newlist;
        newlist = head;
        head = next_link;
        if (i == 0)
            tail = newlist;
    }
    tail->next = head;
    *cur = head;
    return newlist;
} 

void read_list(struct node *head)
{
    while (head != NULL)
    {
        printf ("%d\t",head->data);
        head = head->next;

    }
}

struct node *
reverse (struct node *head, struct node *rev, struct node **last)
{
    struct node *tmp;
    if (head->next == NULL)
    {
        rev = head;
        rev->next = NULL;
        *last = rev;
        return rev;
    }
    rev = reverse (head->next, rev, last);
    head->next = NULL;
    rev->next = head;
    return head;
}

int main()
{
    int i;
    struct node *head = NULL;
    struct node *rev = NULL;
    struct node *last = NULL;
    struct node *curr = NULL;
    int n = sizeof(arr)/sizeof(int);
    for (i =0 ; i < n; i++)
        head = insert (head,arr[i]);

    
    read_list (head);
    do{
            curr = NULL;
            last = rev_n (head, 5, &curr);
            head = curr;
    }while (curr !=NULL);
    printf ("\n");
    read_list (last);
    printf ("\n");
}
