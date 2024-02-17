#include <stdio.h>

/*
 * head -> 1 -> 2 -> 3 -> NULL
 * rev(head);
 * head -> 3 -> 2 -> 1 -> NULL
 */

struct node
{
    int data;
    struct node *next;
};

struct node* rec_rev (struct node **head, struct node *curr)
{
    if (curr == NULL || curr->next == NULL)
    {
        *head = curr;
        return curr;
    }
    else
    {
        struct node *r_node = rec_rev (head, curr->next);
	r_node->next = curr;
	return curr;
    }
}

void reverse (struct node **head)
{
    if (head == NULL || *head == NULL || (*head)->next == NULL)
    {
        return;
    }
    else
    {
        struct node *tmp = *head;
        struct node *l_node = rec_rev (head, tmp);
	l_node->next = NULL;
    }
}

void print (struct node *head)
{
    if (head == NULL)
    {
        printf ("list is empty\n");
    }
    else
    {
        while (head)
	{
            printf ("%d -> ", head->data);
	    head = head->next;
	}
	printf (" NULL\n");
    }
}

int main (int argc, char **argv)
{
    struct node a;
    struct node b;
    struct node c;

    a.data = 1;
    a.next = &b;

    b.data = 2;
    b.next = &c;

    c.data = 3;
    c.next = NULL;

    struct node *head = &a;

    print (head);
    reverse (&head);
    print (head);

    return 0;
}
