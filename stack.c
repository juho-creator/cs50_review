#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int number;
    struct node* next;
}node;


node *create(int number);
node *push(node *list, int number);
void pop(node **list);
void print_link(node *list);

int main()
{
    // Create new node
    node *list = create(11);


    // print node
    print_link(list);

    // Prepend nodes to create linked list
    for(int i = 10; i >0; i--)
    {
        list = push(list, i);
    }


    // print node
    print_link(list);

    // Remove the most recently added node from linked list
    pop(&list);


    // print node
    print_link(list);
}


node *create(int number)
{
    node *n = malloc(sizeof(node));

    n->number = number;
    n->next = NULL;

    return n;
}


node *push(node *list, int number)
{
    node *n = malloc(sizeof(node));
    n->number = number;
    n->next = list;
    list = n;

    return list;
}


void pop(node **list)
{
    node *trav = (*list)->next;
    free(*list);
    *list = trav;
}


void print_link(node *list)
{
    while (list != NULL)
    {
        printf("%i->", list->number);
        list = list->next;
    }

    if (list == NULL)
    {
        printf("NULL\n");
    }
}