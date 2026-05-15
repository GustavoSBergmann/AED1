#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *swapPairs(struct ListNode *head)
{
    struct ListNode *list, *temp1, *temp2, aux;

    list = &aux;
    aux.next = NULL;
    while (head != NULL && head->next != NULL)
    {
        temp1 = head;
        temp2 = head->next;
        temp1->next = temp2->next;
        temp2->next = temp1;

        list->next = temp2;
        list = list->next;

        list->next = temp1;
        list = list->next;

        head = temp1->next;
    }
    if (head != NULL)
    {
        list->next = head;
    }
    return aux.next;
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
    // 1 -> 2 -> 3 -> 4

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

    head = swapPairs(head);

    printf("\nLista apos swap em pares:\n");
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
