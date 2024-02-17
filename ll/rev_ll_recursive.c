#include <stdio.h>

/*
(*header) -> 1 -> 2 -> 3 -> NULL

(*header) -> 3 -> 2 -> 1 -> NULL
*/

struct node
{
    int data;
    struct node *next;
};

void print (struct node *hdr)
{
    if (hdr == NULL)
    {
        printf ("empty\n");
    }
    else
    {
        while (hdr != NULL)
	{
            printf ("%d -> ", hdr->data);
	    hdr = hdr->next;
	}
	printf ("NULL\n");
    }
}


struct node* rec_update (struct node **head, struct node *tmp)
{
    if (tmp == NULL || tmp->next == NULL)
    {
        *head = tmp;
    }
    else
    {
        struct node *r_node = rec_update (head, tmp->next);
	r_node->next = tmp;
    }
    return tmp;
}

void reverse_linked_list (struct node **head)
{
    if (head == NULL || *head == NULL || (*head)->next == NULL)
    {
        return;
    }
    struct node *tmp = *(head);
    struct node *l_node = rec_update (head, tmp);
    l_node->next = NULL;
}

int main (int argc, char **argv)
{
    struct node a1;
    struct node a2;
    struct node a3;

    a1.data = 1;
    a1.next = &a2;

    a2.data = 2;
    a2.next = &a3;

    a3.data = 3;
    a3.next = NULL;

    struct node *head = &a1;

    print (head);
    reverse_linked_list (&head);
    print (head);


    return 0;
}
