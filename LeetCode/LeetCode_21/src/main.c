#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode *list3;
    struct ListNode aux;

    // aux.next = list1;
    list3 = &aux;
    aux.next = NULL;

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val < list2->val)
        {
            list3->next = list1;
            list1 = list1->next;
        }
        else
        {
            list3->next = list2;
            list2 = list2->next;
        }
        list3 = list3->next;
    }
    if (list1 == NULL)
    {
        while (list2 != NULL)
        {
            list3->next = list2;
            list2 = list2->next;
            list3 = list3->next;
        }
    }
    else if (list2 == NULL)
    {
        while (list1 != NULL)
        {
            list3->next = list1;
            list1 = list1->next;
            list3 = list3->next;
        }
    }

    list3 = aux.next;
    return list3;
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
    // Lista 1: 1 -> 2 -> 4
    struct ListNode *a1 = malloc(sizeof(struct ListNode));
    struct ListNode *a2 = malloc(sizeof(struct ListNode));
    struct ListNode *a3 = malloc(sizeof(struct ListNode));

    a1->val = 1;
    a2->val = 2;
    a3->val = 4;

    a1->next = a2;
    a2->next = a3;
    a3->next = NULL;

    // Lista 2: 1 -> 3 -> 4
    struct ListNode *b1 = malloc(sizeof(struct ListNode));
    struct ListNode *b2 = malloc(sizeof(struct ListNode));
    struct ListNode *b3 = malloc(sizeof(struct ListNode));

    b1->val = 1;
    b2->val = 3;
    b3->val = 4;

    b1->next = b2;
    b2->next = b3;
    b3->next = NULL;

    printf("Lista 1:\n");
    printList(a1);

    printf("\nLista 2:\n");
    printList(b1);

    struct ListNode *merged = mergeTwoLists(a1, b1);

    printf("\nLista mesclada:\n");
    printList(merged);

    // Liberando memória
    while (merged != NULL)
    {
        struct ListNode *temp = merged;
        merged = merged->next;
        free(temp);
    }

    return 0;
}
