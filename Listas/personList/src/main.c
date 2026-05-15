#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
    char name[30];
    int age;
} Person;

typedef struct Node
{
    Person p;
    struct Node *pNext;
} Node;

typedef struct
{
    Node *pFirst;
    int qtdNodes;
} List;

void menu(int *m);
void reset(List *pList);
void clear(List *pList);
bool push(List *pList, Node *pNode, unsigned int nIndex);
bool pop(List *pList, Node *pNode, unsigned int nIndex);
void list(List *pList);

int main()
{
    List lista;
    int opcao, index;
    Node *nodo = NULL;

    reset(&lista);
    while (true)
    {
        menu(&opcao);
        switch (opcao)
        {
        case 0:
            nodo = (Node *)malloc(sizeof(Node));
            printf("\n ------ Insere ------\n");
            printf("Insira o nome: ");
            scanf(" %29[^\n]", nodo->p.name);
            printf("Insira a idade: ");
            scanf(" %d", &nodo->p.age);
            printf("Insira a posicao: ");
            scanf(" %d", &index);
            push(&lista, nodo, index);
            break;

        case 1:
            printf("\n ------ Deleta a Ultima ------\n");
            break;

        case 2:
            nodo = (Node *)malloc(sizeof(Node));
            printf("\n ------ Deleta por Endereco ------\n");
            printf("Insira a posicao: ");
            scanf(" %d", &index);
            pop(&lista, nodo, index);
            printf("Pessoa deletada: %s\n", nodo->p.name);
            break;

        case 3:
            printf("\n ------ Limpa ------\n");
            clear(&lista);
            break;

        case 4:
            printf("\n ------ Lista ------\n");
            list(&lista);
            break;

        case 5:
            printf("\n ------ Sair ------\n");
            clear(&lista);
            return 0;
            break;

        default:
            break;
        }
    }

    return 0;
}

void menu(int *m)
{
    do
    {
        printf("\n------ Menu ------\n");
        printf("0 - Insere Pessoa\n");
        printf("1 - Deleta a ultima pessoa\n");
        printf("2 - Deleta pessoa por endereco\n");
        printf("3 - Limpa a lista\n");
        printf("4 - Lista na tela as pessoas\n");
        printf("5 - Sair do programa\n");
        printf("Insira uma opcao do menu: ");
        scanf(" %d", m);
    } while (*m < 0 || *m > 5);
}

void reset(List *pList)
{
    pList->pFirst = NULL;
    pList->qtdNodes = 0;
}

void clear(List *pList)
{
    Node *aux = pList->pFirst;
    Node *temp;

    while (aux != NULL)
    {
        temp = aux->pNext;
        free(aux);
        aux = temp;
    }

    pList->pFirst = NULL;
    pList->qtdNodes = 0;
}

bool push(List *pList, Node *pNode, unsigned int nIndex)
{
    Node *pAtual, *pAnterior;

    if (nIndex > pList->qtdNodes)
    {
        free(pNode);
        return false;
    }

    if (pList->pFirst == NULL && nIndex != 0)
    {
        free(pNode);
        return false;
    }
    else if (pList->pFirst == NULL && nIndex == 0)
    {
        pList->pFirst = pNode;
        pList->pFirst->pNext = NULL;
        pList->qtdNodes++;
        return true;
    }
    else if (nIndex == 0)
    {
        pNode->pNext = pList->pFirst;
        pList->pFirst = pNode;
        pList->qtdNodes++;
        return true;
    }

    pAtual = pList->pFirst;
    for (int nPos = 0; nPos < nIndex && pAtual != NULL; nPos++)
    {
        pAnterior = pAtual;
        pAtual = pAtual->pNext;
    }

    pNode->pNext = pAtual;
    pAnterior->pNext = pNode;
    pList->qtdNodes++;
    return true;
}

bool pop(List *pList, Node *pNode, unsigned int nIndex)
{
    Node *pAtual, *pAnterior;

    if (pList->pFirst == NULL)
    {
        return false;
    }
    if (nIndex == 0)
    {
        *pNode = *pList->pFirst;
        pList->pFirst = pList->pFirst->pNext;
        pList->qtdNodes--;
        free(pNode);
        return true;
    }

    pAtual = pList->pFirst;
    for (int nPos = 0; nPos < nIndex && pAtual != NULL; nPos++)
    {
        pAnterior = pAtual;
        pAtual = pAtual->pNext;
    }

    if (pAtual == NULL)
    {
        return false;
    }
    pAnterior->pNext = pAtual->pNext;
    *pNode = *pAtual;
    pList->qtdNodes--;
    free(pAtual);

    return true;
}

void list(List *pList)
{
    Node *pAtual;
    pAtual = pList->pFirst;

    while (pAtual != NULL)
    {
        printf("Nome: %s\n", pAtual->p.name);
        printf("Idade: %d\n\n", pAtual->p.age);

        pAtual = pAtual->pNext;
    }
}