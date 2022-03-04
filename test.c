#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
    int data;
    struct s_node *next;
} Node;

void push(Node** head_ref, int new_data)
{
    Node* new_node = (Node*) malloc(sizeof(Node));

    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}

void printList( Node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

void swap( Node **first, Node **second )
{
     Node *tmp = *first;
    *first = *second;
    *second = tmp;
}

void swapNodes(Node **headr, int key1, int key2 )
{
    if ( key1 == key2 )
        return;

    Node **first = headr;

    while ( *first && ( *first )->data != key1 ) 
            first = &( *first )->next;

    if ( *first == NULL ) 
        return;

   Node **second = headr;

    while ( *second && ( *second )->data != key2 ) 
        second = &( *second )->next;

    if ( *second == NULL ) return;

    swap( first, second );
    swap( &( *first )->next, &( *second )->next );
}

int main( void ) 
{
    Node *start = NULL;

    push(&start, 7);
    push(&start, 6);
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 1);
    push(&start, 2);

    printf("\n Linked list before calling swapNodes() ");
    printList(start);

    swapNodes(&start, 4, 2);

    printf("\n Linked list after  calling swapNodes() ");
    printList(start);

    return 0;
}