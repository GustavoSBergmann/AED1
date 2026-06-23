#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *removeElements(struct ListNode *head, int val)
{
    struct ListNode *pAnterior, *pAtual, *pRemove, ghost;
    ghost.next = head;
    pAnterior = &ghost;
    pAtual = ghost.next;

    while (pAtual != NULL)
    {
        pRemove = pAtual;
        if (pRemove->val == val)
        {
            pAnterior->next = pRemove->next;
            pAtual = pAtual->next;
            free(pRemove);
        }
        else
        {
            pAnterior = pAtual;
            pAtual = pAtual->next;
        }
    }

    return ghost.next;
}

int main()
{
    struct ListNode *n1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *n2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *n3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *n4 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *n5 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *n6 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *n7 = (struct ListNode *)malloc(sizeof(struct ListNode));

    n1->val = 1;
    n2->val = 2;
    n3->val = 6;
    n4->val = 3;
    n5->val = 4;
    n6->val = 5;
    n7->val = 6;

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = NULL;

    struct ListNode *head = n1;

    struct ListNode *p = head;

    printf("\nAntes:\n");
    while (p != NULL)
    {
        printf("Valor: %d\n", p->val);
        p = p->next;
    }

    struct ListNode *newHead = removeElements(head, 6);

    p = newHead;
    printf("\nDepois:\n");
    while (p != NULL)
    {
        printf("Valor: %d\n", p->val);
        p = p->next;
    }

    return 0;
}
