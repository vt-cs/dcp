// given head of SLL
// reversed SLL
// header-> 1<-2->3->NULL
// header-> 3->2->1->NULL
//
#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};

struct node* rec_reverse(struct node **header, struct node *temp)
{
    // base condn
    if(temp == NULL || temp->next == NULL)
    {
        *header = temp;
        return temp;
    }
    struct node *n_next = rec_reverse(header, temp->next);
    n_next->next = temp;
    return temp;
}

void reverse(struct node **header)
{
    struct node *temp;
    temp = *header;
    struct node *n = rec_reverse(header, temp);
    n->next = NULL;
}

void print (struct node *head)
{
    if(head == NULL)
    {
        printf ("List is empty\n");
	return;
    }
    else
    {
        while(head!=NULL)
	{
            printf ("%d ", head->data);
	    head = head->next;
	}
	printf ("\n");
    }
}

int main(int argc, char **argv)
{
//a1 -> a2 -> a3 -> NULL
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

    printf ("before:\n");
    print (head);
    reverse(&head);
    printf ("after:\n");
    print (head);

    return 0;
}
