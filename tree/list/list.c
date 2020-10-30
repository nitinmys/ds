
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
 }; 

int arr[] = {1,2,3,5,7,10,-4,23,12,4,6};

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


void read_list(struct node *head)
{
    while (head != NULL)
    {
        printf ("%d\t",head->data);
        head = head->next;

    }
    printf ("\n");
}

int delete_elem (struct node **head,int value)
{
    struct node *current = *head;
    struct node *prev = NULL;
    
    if (*head == NULL)
        return 1;
    if (current->data == value)
    {
        printf ("\n found at head deleting \n");
        *head = current->next;
        current = current->next;
    }
    while (current != NULL)
    {
        if (current->data == value)
        {
            printf ("\n found deleting \n");
            prev->next = current->next;
            free(current);
        }
        else
        {
            prev = current;
            current = current->next;
        }

    }
    return 1;
}

int bubble_sort (struct node **head)
{
    struct node *current = *head;
    struct node *prev = NULL;
    struct node *tmp_swap;
    struct node *loop_end=NULL;
    int did_swap = 1;
    // if empty list or only one node 
    // we are already sorted.
    if (current == NULL || current->next == NULL)
        return 0;

    // pass to shift the largest element to the end

    // if the first element needs to be swapped
    // head changes, handle the case.

    while (current->next != loop_end && did_swap)
    {
        did_swap = 0;
        prev = NULL;
        current = *head;

        while (current != NULL && current->next != NULL)
        {

            if (current->data > current->next->data)
            {

                did_swap = 1;

                if (current == *head)
                {
                    *head = current->next;
                    prev = current;
                    current = current->next;
                    prev->next = current->next;
                    current->next = prev;
                    tmp_swap = prev;
                    prev = current;
                    current = tmp_swap;
                    read_list (*head);

                }
                else
                {
                    prev->next = current->next;
                    tmp_swap = current->next->next;
                    current->next->next = current;
                    current->next = tmp_swap;
                    prev = prev->next;
                    loop_end = prev;
                    read_list (*head);
                }
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }
    }
}

/*
int insertion_sort(struct node **head)
{
    struct node *sorted_head = *head;
    struct node *sorted_tail = *head;
    struct node *tmp = NULL;
    struct node *current = *head;
    int min;
    struct node *saved_prev = NULL;
    struct node *min_node = NULL;
    struct node *prev = NULL;

    // List is already sorted if null or one elment
    if (sorted_head == NULL || sorted_head->next == NULL)
        return 0;

    min = sorted_list->data;
    current = current->next;
    while (current != NULL)
    {
        if (current->data < min)
        {
            min_node = current;
            min = current->data;
            saved_prev = prev;
        }
        prev = current;
        current = current->next;
    }
    if (min_node != sorted_head)
    {
        min_node->next = sorted_head;
        sorted_head = min_node;
        prev->next = prev->next->next;
    }

    *head = sorted_head;
}
*/

void insert_one_node(struct node **head,struct node *datanode)
{
    struct node *current = *head;
    struct node *prev = NULL;
    struct node *tmp = NULL;
    if (*head == NULL)
    {
        *head = datanode;
        datanode->next = NULL;
        return;
    }
    if (current->next == NULL)
    {
        if (current->data > datanode->data)
        {
            *head = datanode;
            datanode->next = current;

        }
        else
        {
            current->next = datanode;
            datanode->next = NULL;
        }
        return;
    }
    while (current != NULL)
    {
        if (current->data > datanode->data)
        {
            if (current == *head)
            {
                *head = datanode;
                datanode->next = current;
                return;

            }
            else
            {
                prev->next = datanode;
                tmp = datanode->next;
                datanode->next = current;
                current->next = tmp;
                return;
            }
        }
        else if (current->next == NULL)
        {
            //insert_last
            current->next = datanode;
            datanode->next = NULL;
            return;
        }
        else if (current->data< datanode->data && 
                 current->next->data > datanode->data)
        {
            tmp = current->next;
            current->next= datanode;
            datanode->next = tmp;
            return;

        }
        else
        {
            prev = current;
            current = current->next;
            //just move current and prev
        }
    }

}

int main()
{
    int i;
    struct node *head = NULL;
    struct node *rev = NULL;
    struct node *last = NULL;
    struct node *curr = NULL;
    int n = sizeof(arr)/sizeof(int);
    int num;
    for (i =0 ; i < n; i++)
        head = insert (head,arr[i]);

    
    read_list (head);
    if (delete_elem (&head, 50) != 0)
    {
        printf ("\ncould not find element\n");
    }
    read_list (head);
    printf ("------------bubble sort----------------\n");
    bubble_sort (&head);
    read_list (last);
    printf ("------------insertion sort----------------\n");
    curr = head;
    while (curr!=NULL)
    {
        rev = curr;
        curr = curr->next;
        insert_one_node(&last,rev);
        read_list (last);
    }

}


