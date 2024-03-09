#include <stdio.h>
#include <stdlib.h>
struct LinkedList
{
    int val;
    struct LinkedList *next;
};

struct LinkedList *head;

void createLinkedList()
{
    int n;
    printf("\nEnter the size of Linked list:- \n");
    scanf("%d", &n);
    struct LinkedList *T, *N;
    head = NULL;
    for (int i = 1; i <= n; i++)
    {
        T = (struct LinkedList *)malloc(sizeof(struct LinkedList));
        printf("\nEnter the value of %d node:- \n", i);
        scanf("%d", &T->val);
        T->next = NULL;
        if (head == NULL)
        {
            head = T;
        }
        else
        {
            N = head;
            while (N->next != NULL)
            {
                N = N->next;
            }
            N->next = T;
        }
    }
}

void display()
{
    struct LinkedList *N;
    N = head;
    while (N != NULL)
    {
        printf("\n%d", N->val);
        N = N->next;
    }
    printf("\n");
}

void insLast()
{
    struct LinkedList *T, *N;
    T = (struct LinkedList *)malloc(sizeof(struct LinkedList));
    printf("\nEnter the value of new node:- \n");
    scanf("%d", &T->val);
    T->next = NULL;
    N = head;
    while (N->next != NULL)
    {
        N = N->next;
    }
    N->next = T;
    printf("\nNew node inserted at last\n");
}

void insBeg()
{
    struct LinkedList *T;
    T = (struct LinkedList *)malloc(sizeof(struct LinkedList));
    printf("\nEnter the value of new node:- \n");
    scanf("%d", &T->val);
    T->next = head;
    head = T;
    printf("\nNew node inserted at beginning\n");
}

void insAfter()
{
    int n;
    struct LinkedList *T, *N, *N_next;
    printf("\nEnter the value of the node after you want to insert a new node:- \n");
    scanf("%d", &n);
    N = head;
    N_next = N->next;
    while (N->val != n)
    {
        N = N->next;
        N_next = N_next->next;
    }
    T = (struct LinkedList *)malloc(sizeof(struct LinkedList));
    printf("\nEnter the value of new node:- \n");
    scanf("%d", &T->val);
    N->next = T;
    T->next = N_next;
    printf("\nNew node inserted after the provided node value\n");
}

void insBefore()
{
    int n;
    struct LinkedList *T, *N, *N_prev;
    printf("\nEnter the value of the node before you want to insert a node:- \n");
    scanf("%d", &n);
    N = head;
    while (N != NULL && N->val != n)
    {
        N_prev = N;
        N_prev = N;
        N = N->next;
    }

    T = (struct LinkedList *)malloc(sizeof(struct LinkedList));
    printf("\nEnter the value of new node:- \n");
    scanf("%d", &T->val);

    if (N == head)
    {
        T->next = head;
        head = T;
    }
    else
    {
        N_prev->next = T;
        T->next = N;
    }
    printf("\nNew node inserted before the provided node value\n");
}

void delLast()
{
    if (head->next == NULL)
    {
        head = NULL;
        printf("\nLast node deleted !\n");
        return;
    }

    struct LinkedList *N, *N_prev;
    N = head;
    while (N->next != NULL)
    {
        N_prev = N;
        N = N->next;
    }
    N_prev->next = NULL;
    printf("\nLast node deleted !\n");
}

void delBeg()
{
    if (head->next == NULL)
    {
        head = NULL;
        printf("\nBeginning node deleted !\n");
        return;
    }

    head = head->next;
    printf("\nBeginning node deleted !\n");
}

void delAfter()
{
    if (head->next == NULL)
    {
        printf("\nNothing to delete after this node\n");
        return;
    }

    int n;
    struct LinkedList *N;
    printf("\nEnter the value after you want to insert a node:- \n");
    scanf("%d", &n);
    N = head;
    while (N->next != NULL && N->val != n)
    {
        N = N->next;
    }
    if (N->next == NULL)
    {
        printf("\nNothing to delete after this node\n");
        return;
    }
    else
    {
        N->next = N->next->next;
    }
    printf("\nNode deleted after the provided node value\n");
}

void delBefore()
{
    int n;
    printf("\nEnter the value before you want to insert a node:- \n");
    scanf("%d", &n);
    if (head->next == NULL || head->val == n)
    {
        printf("\nNothing to delete before this node\n");
        return;
    }
    else if (head->next->val == n)
    {
        head = head->next;
        printf("\nNode deleted before the provided node value\n");
        return;
    }
    else
    {
        struct LinkedList *N, *N_next, *N_next_next;
        N = head;
        N_next = N->next;
        N_next_next = N_next->next;
        while (N_next_next->val != n)
        {
            N = N->next;
            N_next = N_next->next;
            N_next_next = N_next_next->next;
        }
        N->next = N_next_next;
        printf("\nNode deleted before the provided node value\n");
    }
}

int main()
{
    while (1)
    {
        int x;
        printf("\n-----------------------------------------------------------\n");
        printf("\nPress 1 to create a new Linked List\n");
        printf("\nPress 2 to display created Linked List\n");
        printf("\nPress 3 to insert at last of the Linked List\n");
        printf("\nPress 4 to insert at beginning of the Linked List\n");
        printf("\nPress 5 to insert at after a node in Linked List\n");
        printf("\nPress 6 to insert at before a node in Linked List\n");
        printf("\nPress 7 to delete at last of the Linked List\n");
        printf("\nPress 8 to delete at beginning of the Linked List\n");
        printf("\nPress 9 to delete at after a node in Linked List\n");
        printf("\nPress 10 to delete at before a node in Linked List\n");
        printf("\n-----------------------------------------------------------\n");
        printf("\n\nEnter your option:- \n");
        scanf("%d", &x);
        switch (x)
        {
        case 0:
            return 0;

        case 1:
            createLinkedList();
            break;

        case 2:
            display();
            break;

        case 3:
            insLast();
            break;

        case 4:
            insBeg();
            break;

        case 5:
            insAfter();
            break;

        case 6:
            insBefore();
            break;

        case 7:
            delLast();
            break;

        case 8:
            delBeg();
            break;

        case 9:
            delAfter();
            break;

        case 10:
            delBefore();
            break;

        default:
            break;
        }
    }
}