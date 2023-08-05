#include <stdio.h>
#include <stdlib.h>



typedef struct node{
    int number;
    struct node *prev;
    struct node *next;
}node;


node *create(int number);
node *enqueue(node *tail, int number);
node *dequeue(node *head);

void print_linked(node *n);

int main()
{
    // Create initial node
    node *head = create(0);
    node *tail = create(0);



    // Enqueue node
    for (int i = 1; i <= 10; i++)
    {

        tail = enqueue(tail, i);
        if (i == 1)
        {
            head->next = tail;
        }
    }


    // Print node
    print_linked(head);

    for (int i = 0 ; i < 3; i++)
    {
        // Dequeue node
        head = dequeue(head);
    }

    // Print node
    print_linked(head);

}


node *create(int number)
{
    node *n = malloc(sizeof(node));
    n->number = number;
    n->next = NULL;

    return n;
}


node *enqueue(node *tail, int number)
{
    // create a node
    node *n = malloc(sizeof(node));

    // set its next to NULL and prev to tail
    n->next = NULL;
    n->prev = tail;
    n->number = number;

    // set tail next to new node
    tail->next = n;

    // set tail as new node
    tail = n;

    // return new tail
    return tail;
}


void print_linked(node *n)
{
    while (n != NULL)
    {

        printf("%i->", n->number);
        n = n->next;
    }

    if (n == NULL)
    {
        printf("NULL\n");
    }
    else
    {
        printf("%i\n", n->number);
    }
}



node *dequeue(node *head)
{
    if (head == NULL || head->next == NULL) {
        return NULL;
    }

    // traverse the linked list to its second element (if it exists)
    node *next = head->next;

    // free the head of the list
    free(head);

    // move the head pointer to the former second element
    head = next;

    // make that node's prev pointer point to NULL
    head->prev = NULL;

    return head;
}
