#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};

void reverse_ll(struct node **header)
{
    if (header == NULL)
    {
        printf ("List is NULL\n");
        return;
    }
    if (*header == NULL)
    {
        printf ("List is Empty\n");
        return;
    }
    if ((*header)->next == NULL)
    {
        printf ("List contain just one element - reversing will not change anything\n");
	return;
    }

    struct node *prev = NULL;
    struct node *curr = *header;
    struct node *nxt;

    while (curr != NULL)
    {
        nxt = curr->next;
        curr->next = prev;
	prev = curr;
	curr = nxt;
    }
    *header = prev;
}

void print (struct node *head)
{
    if (head == NULL)
    {
        printf ("Linked list is NULL\n");
	return;
    }
    while (head != NULL)
    {
        printf ("%d ", head->data);
	head = head->next;
    }
    printf ("\n");
}

int main(int argc, char **argv)
{
    struct node *header = NULL;

    struct node a1;
    struct node a2;
    struct node a3;

    a1.data = 1;
    a1.next = &a2;

    a2.data = 2;
    a2.next = &a3;

    a3.data = 3;
    a3.next = NULL;

    header = &a1;

    print (header);
    reverse_ll (&header);
    print (header);

    return 0;
}
