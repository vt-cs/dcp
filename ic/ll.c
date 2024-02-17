rwx
2

pthread_create ();

void fun
{
    static int var;
}


stack



heap

data segment
code segment


#include <stdio.h>

struct node
{
   int data;
   struct node *next;
};

1->2->3 2 5

1->2->5->3


struct node *insert_node(struct node *head, int pos, int data)
{
    struct node *tmp = head;
    while (--pos)
    {
	tmp = tmp->next;
    }
    struct node *new_node = (struct node*) malloc(sizeof (struct node));
    new_node->data = data;
    new_node->next = tmp->next;
    tmp->next = new_node;

    return head;
}
