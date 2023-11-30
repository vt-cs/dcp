#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};

struct node* rec_rev(struct node **head, struct node *temp)
{
    if (temp == NULL || temp->next == NULL)
    {
        *head = temp;
	return temp;
    }
    else
    {
        struct node *n_next = rec_rev(head, temp->next);
	n_next->next = temp;
	return temp;
    }
}

void reverse(struct node **head)
{
    struct node *temp;
    temp = *head;

    struct node *l_next = rec_rev(head, temp);
    l_next->next = NULL;
}

void print(struct node *head)
{
    if (head == NULL)
    {
        printf ("list is empty\n");
    }
    else
    {
        while(head != NULL)
	{
            printf ("%d ", head->data);
	    head = head->next;
	}
	printf ("\n");
    }
}

int main(int argc, char **argv)
{
    struct node *head = NULL;
    struct node a1;
    struct node a2;
    struct node a3;

    a1.data = 1;
    a1.next = &a2;

    a2.data = 2;
    a2.next = &a3;

    a3.data = 3;
    a3.next = NULL;

    head = &a1;

    printf ("before reverse::\n");
    print (head);
    printf ("reversing ll::\n");
    reverse(&head);
    printf ("after reverse::\n");
    print (head);


    return 0;
}
