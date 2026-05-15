#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *rotateRight(struct ListNode *head, int k)
{
    if (head == NULL)
    {
        return head;
    }

    struct ListNode *pAntes, *pDepois;
    int size = 1, nPos;

    pAntes = head;
    pDepois = head;

    while (pDepois->next != NULL)
    {
        pDepois = pDepois->next;
        size++;
    }
    pDepois->next = head;
    pDepois = pDepois->next;

    nPos = (k % size);
    for (int i = 0; i < nPos; i++)
    {
        pDepois = pDepois->next;
    }

    while (pDepois->next != head)
    {
        pAntes = pAntes->next;
        pDepois = pDepois->next;
    }

    head = pAntes->next;
    pAntes->next = NULL;

    return head;
}

// Função para imprimir lista
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
    // Criando lista:
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

    int k = 7;

    printf("Lista original:\n");
    printList(head);

    printf("\nRotacionando %d vezes para a direita...\n", k);

    head = rotateRight(head, k);

    printf("\nLista apos rotacao:\n");
    printList(head);

    // Liberando memória
    while (head != NULL)
    {
        struct ListNode *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}