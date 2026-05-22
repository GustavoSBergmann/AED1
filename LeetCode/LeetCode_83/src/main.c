#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

struct ListNode *deleteDuplicates(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct ListNode *pAtual, *pProx, *pRemove;
    pAtual = head;
    pProx = head->next;

    while (pProx != NULL)
    {
        if (pAtual->val != pProx->val)
        {
            pAtual->next = pProx;
            pAtual = pProx;
            pProx = pProx->next;
        }
        else
        {
            pRemove = pProx;
            pProx = pProx->next;
            free(pRemove);
            pAtual->next = pProx;
        }
    }

    return head;
}

int main()
{
    /*
    Lista:
    1 -> 1 -> 2 -> 3 -> 3
    */

    struct ListNode *n1 = (ListNode *)malloc(sizeof(ListNode));
    struct ListNode *n2 = (ListNode *)malloc(sizeof(ListNode));
    struct ListNode *n3 = (ListNode *)malloc(sizeof(ListNode));
    struct ListNode *n4 = (ListNode *)malloc(sizeof(ListNode));
    struct ListNode *n5 = (ListNode *)malloc(sizeof(ListNode));

    n1->val = 1;
    n2->val = 1;
    n3->val = 2;
    n4->val = 3;
    n5->val = 3;

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;

    struct ListNode *head = n1;

    printf("Antes:\n");

    ListNode *p = head;

    while (p != NULL)
    {
        printf("%d ", p->val);
        p = p->next;
    }

    printf("\n");

    /* chama sua função */
    head = deleteDuplicates(head);

    printf("\nDepois:\n");

    p = head;

    while (p != NULL)
    {
        printf("%d ", p->val);
        p = p->next;
    }

    printf("\n");

    return 0;
}
