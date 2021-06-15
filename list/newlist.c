
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
struct node {
    int data;
    struct node *next;
 }; 

struct stack{
    int64_t * array[100];
    uint top;
};

int arr[] = {1,2,100,8,3,7,4,6,5,0};
int arr1[] = {9,7,5,3,1};
int arr2[] = {12,10,8,6,4,2,0};

struct node * global;

struct node ** reverse ( struct node *head, struct node **rev, int count)
{
        struct node **tail; 
                                                                   
        if (head->next == NULL|| count == 2)
        {
            *rev = head;
            return (&head->next);
        }
        else
        {
            struct node *tmp; 
             tail =  reverse (head->next,rev,++count);
            tmp = *tail;
            *tail = head;
             head->next = tmp;
             return (&head->next);
         }
}
            

void print_middle (struct node *head)
{
    struct node *fast,*slow;
    int count = 0;
    fast = head;
    slow = head;
    // empty
    if (fast ==NULL)
    {
        printf ("Empty list\n");
        return;
    }
     do
    {
        if (count != 0 && count %2 == 0)
            slow = slow->next;
        count++;
        fast = fast->next;
        
    }while (fast != NULL);

    printf ("The middle of the list has value %d\n", slow->data);
}


        

int delete_node(struct node **head, int value)
{
    struct node *current,*prev;
    int found = -1;
    if (head == NULL)
        return found;
    prev = *head;
    current = *head;

    if (current->data == value)
    {
        *head = current->next;
        return 0;
    }

    while (current != NULL)
    {
        if (current->data == value)
        {
            prev->next = current->next;
            found = 0;
        }
        prev = current;
        current = current->next;
    }
    return found;
}



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

struct node * bubble_sort (struct node * head)
{

    struct node *last = NULL;
    struct node *newhead = head;
    struct node *current,*prev;

    prev = newhead;
while (newhead->next != last)
{
    current = newhead;
   while (current->next != last)
    {
        if (current->data > current->next->data)
        {
            struct node * nextnode,*tmp;
            if (current == newhead)
            {
                printf ("head changing\n");
                getchar();
                 nextnode = current ->next;
                 newhead = nextnode;
                current->next = nextnode->next;
                nextnode->next = current;
                prev = nextnode;
            }
            else
            {
                printf ("Swapping\n");
                nextnode = current ->next;
                tmp =  nextnode->next;
                nextnode->next = current;
                current->next = tmp;
                prev->next = nextnode;
                prev = nextnode;
                read_list (newhead);
            }
        }
       else
        {
            prev = current;
            current = current->next;
            
        }
    }
    last = current;
    printf ("last node data %d\n",last->data);
    getchar();
}
    printf ("Returning\n");
    return newhead;
}


void partition_list (struct node *head, struct node **left, struct node ** right)
{
    struct node *fast, *slow;
    fast = head;
    slow = head;
    unsigned int counter = 0;

    if (fast == NULL || fast->next == NULL)
    {
        printf ("Asked to partition a  list with 0/1 member\n");
        read_list(head);
        exit(1);
    }

    while ( fast->next != NULL)
    {
        counter++;
        fast = fast->next;
        if (!(counter & 0x01))
            slow = slow->next;
    }

    *left = head;
    *right = slow->next;
    // break the chain
    slow->next  = NULL;
}

struct node * merge (struct node * left, struct node * right)
{
    struct node *head, *tail, *tmp;
    int first = 0;
    head = NULL;
    tail = NULL;
    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            tmp = left;
            left = left->next;
        }
        else
        {
            tmp = right;
            right = right->next;
        }
        tmp->next = NULL;
        if (!first)
        {
            head = tmp;
            tail = tmp;
            first++;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }

   if (left!= NULL)
        tail->next = left;

   if (right!= NULL)
        tail->next = right;

    return head;
}        

struct node *mergesort (struct node *head)
{
    struct node *leftlist,*rightlist;
    if (head->next == NULL)
    {
        return head;
    }
     else
    {
        partition_list (head, &leftlist, &rightlist);
        return (merge (mergesort (leftlist), mergesort(rightlist)));
     }
}


int main()
{
    int i;
    struct node *head = NULL;
    struct node *rev = NULL;
    struct node *last = NULL;
    struct node *curr = NULL;
    struct node *tail = NULL;
    int value;
    int n = sizeof(arr)/sizeof(int);
    int num;
    for (i =0 ; i < n; i++)
        head = insert (head,arr[i]);
    read_list (head);

    n = sizeof(arr1)/sizeof(int);
    for (i =0 ; i < n; i++)
         curr = insert (curr,arr1[i]);
    read_list (curr);

    n = sizeof(arr2)/sizeof(int);
    for (i =0 ; i < n; i++)
        tail = insert (tail,arr2[i]);
    read_list (tail);


    last = merge (curr,tail);
    read_list (last);

    


   curr = mergesort(head);

    read_list (curr);
    //read_list (tail);

/*
    print_middle (head);
   tail =  reverse (head,&rev,1);
  
    read_list (rev);
    head = bubble_sort(rev);
    read_list (head);
   

    while (TRUE)
    {
        //fflush (STDIN);
        printf ("Provide a key to delete:");
        scanf ("%d",&value);
        if (delete_node (&head, value) < 0)
            printf ("Node not found\n");
        else
        {
            read_list (head);
            print_middle(head);
        }
    }
*/
}


