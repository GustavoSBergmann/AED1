#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    struct ListNode *pDepois, *pAntes, *pRemover;
    struct ListNode ghost;

    ghost.next = head;
    pAntes = &ghost;
    pDepois = &ghost;

    for (int nPos = 0; pDepois != NULL; nPos++)
    {
        if (nPos <= n)
        {
            pDepois = pDepois->next;
        }
        else
        {
            pAntes = pAntes->next;
            pDepois = pDepois->next;
        }
    }
    pRemover = pAntes->next;
    pAntes->next = pRemover->next;
    free(pRemover);

    return ghost.next;
}

void printList(struct ListNode *head)
{
    while (head != NULL)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    // Criando a lista:
    // 1 -> 2 -> 3 -> 4 -> 5

    struct ListNode *n1 = malloc(sizeof(struct ListNode));
    struct ListNode *n2 = malloc(sizeof(struct ListNode));
    struct ListNode *n3 = malloc(sizeof(struct ListNode));
    struct ListNode *n4 = malloc(sizeof(struct ListNode));
    struct ListNode *n5 = malloc(sizeof(struct ListNode));

    n1->val = 1;
    n2->val = 2;
    n3->val = 3;
    n4->val = 4;
    n5->val = 5;

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;

    struct ListNode *head = n1;

    printf("Lista original:\n");
    printList(head);

    // Remove o 2º nó a partir do final
    head = removeNthFromEnd(head, 2);

    printf("\nLista apos remover o 2o do final:\n");
    printList(head);

    // Liberando memória restante
    while (head != NULL)
    {
        struct ListNode *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
