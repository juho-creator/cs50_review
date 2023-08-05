#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//  node(element) of linked list
typedef struct node{
    int number;
    struct node *next;
    struct node *prev;
}node;


node *create(int number); // Creates first element of doubly linked list
bool find(node *head, int number); // check if number exists in doubly linked list
node *insert(node *head, int number); // prepend number into doubly linked list
void print_link(node *head); // print doubly linked list
void destroy(node *head); // clear memory of doubly linked list
void destroy_recursive(node *head); // clear memory of doubly linked list with recursive function
void delete(node *target); // deleting a node from a doubly linked list


int main(int argc, char *argv[])
{
    // Creating new element of doubly linked list
    node *list = create(0);

    // Prepending new elements into doubly linked list
    for (int i = 1; i <= 10; i++)
    {
        list = insert(list, i);
    }

    // Print all of doubly linked list
    print_link(list);

    // Check if number exists in doubly linked list
    bool exists = find(list ,8);

    // Destroy everything in doubly linked list
    delete(list->next->next);

    // Print all of doubly linked list
    print_link(list);

    // Check if number exists in doubly linked list
    exists = find(list ,8);

    // Clearing every memory in a doubly doubly linked list
    destroy(list);
}



node *create(int number)
{
    // Dynamically allocate memory
    node *n = malloc(sizeof(node));

    // check if we ran out of memory
    if (n == NULL)
    {
        printf("Ran out of memory\n");
        return NULL;
    }

    // initialize number and linking address
    n->number = number;
    n->next = NULL;

    // return newly created element of doubly linked list
    return n;
}


bool find(node *head, int number)
{
    // Initiate the following until end of doubly linked list
    while (head != NULL)
    {
        // return true if number was found in doubly linked list
        if (head->number == number)
        {
            printf("'%i' found\n",number);
            return true;
        }

        // move to next element if number not found
        head= head->next;
    }

    // print the following and return false if number was not found in doubly linked list
    printf("'%i' not found\n",number);
    return false;
}



node *insert(node *head, int number)
{
    // Dynamically allocate memory
    node *n = malloc(sizeof(node));

    // check if we ran out of memory
    if (n == NULL)
    {
        printf("Ran out of memory\n");
        return NULL;
    }

    // Populate and prepend node
    n->number = number;
    n->next = head;

    // move previous pointer to new pointer
    head->prev = n;
    head = n;


    // Return doubly linked list with prepended node
    return head;
}


void print_link(node *head)
{
    // Print entire element of list
    printf("doubly linked list : ");
    while (head != NULL)
    {
        printf("%i -> ",head->number);
        head = head->next;
    }
    printf("NULL\n");
}


void destroy_recursive(node *head)
{
    // Stop if null pointer was reached
    if (head == NULL)
    {
        return;
    }

    destroy(head->next);     // recall function until null pointer is reached
    free(head);    // free in stack

}

void destroy(node *head)
{
    while (head != NULL)
    {
        node *next = head->next;    // keep track of next element
        free(head);     // free current element
        head = next;    // move to next element
    }
}


void delete(node *target)
{
    // fix pointers of the surrounding nodes to "skip over" target
    (target->prev)->next = target->next;
    (target->next)->prev = target->prev;

    // free target
    free(target);
}
