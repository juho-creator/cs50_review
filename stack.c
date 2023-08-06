/*
Review on stack in linked list
Disclaimer : may not have comments on redundant codes to other code files
*/

#include <stdio.h>
#include <stdlib.h>

// Node structure with number and pointer
typedef struct node{
    int number;
    struct node* next;
}node;


node *create(int number); // Creates initial node
node *push(node *list, int number); // Prepends node, forming linked list
void pop(node **list); // Removes the most recently added node
void print_link(node *list); // Prints every node in linked list

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
    // Create a pointer for keeping track of second node
    node *trav = (*list)->next;
    
    // Clear the first node
    free(*list);

    // Move the head pointer to second node
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
