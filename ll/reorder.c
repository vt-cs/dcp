#include <stdio.h>

/*
NULL
"Empty list"

1->NULL
1->NULL

1->2->NULL
1->2->NULL

1->2->3->NULL
1->3->2->NULL

1->2->3->4->NULL
1->4->2->3->NULL

1->2->3->4->5->NULL
1->5->2->4->3->NULL

step 1: find the middle of the linked list
step 2: split the linked list into two halves - now we have 2 linked lists of almost same size
step 3: reverse the second half of linked list
step 4: merge the 2 linked list one element at a time from both linked list
*/

struct node
{
    int data;
    struct node *next;
};

void reverse(struct node **header)
{
    struct node *prev = NULL;
    struct node *curr = NULL;
    struct node *next = NULL;

    if (header == NULL)
    {
        return;
    }
    prev = NULL;
    curr = *header;
    while (curr != NULL)
    {
        next = curr->next;
	curr->next = prev;
	prev = curr;
	curr = next;
    }
    *header = prev;
}

void split(struct node **header, struct node **part1, struct node **part2)
{
    struct node *slow = NULL;
    struct node *fast = NULL;
    if (header == NULL || part_1 == NULL || part_2 == NULL)
    {
        return;
    }
    *part_1 = *header;
    slow = *header;
    fast = *header;

    while (fast != NULL || fast->next != NULL)
    {
        slow = slow->next;
	fast = fast->next->next;
    }
    *part2 = slow->next;
    slow->next = NULL;
}

void reorder(struct node **list_1, struct node **list_2)
{
    struct node *ptr1;
    struct node *ptr2;
    if (list_1 == NULL || list_2 == NULL)
    {
        return;
    }

    ptr1 = *list_1;
    ptr2 = *list_2;

    while (list_1 != NULL)
    {
    }
}

int main()
{

    return 0;
}
