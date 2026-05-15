#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct
{
    int *nums;
    int topo;
    int base;
    int limite;
} Pilha;

void reset(Pilha *pilha);
bool empty(Pilha *pilha);
bool push(Pilha *pilha, int num);
bool pop(Pilha *pilha, int *i);
void list(Pilha *pilha);

int main()
{
    Pilha p;
    ;
    int deleted;

    reset(&p);

    push(&p, 5);
    push(&p, 6);
    push(&p, 7);
    list(&p);

    pop(&p, &deleted);
    push(&p, 10);

    list(&p);
    printf("Deletado: %d\n", deleted);

    free(p.nums);
    return 0;
}

void reset(Pilha *pilha)
{
    pilha->nums = NULL;
    pilha->topo = 0;
    pilha->base = 0;
    pilha->limite = 0;
}

bool empty(Pilha *pilha)
{
    return (pilha->topo == 0);
}

bool push(Pilha *pilha, int num)
{
    int *temp = realloc(pilha->nums, ++(pilha->limite) * sizeof(int));
    if (temp == NULL)
    {
        printf("Erro de alocacao!!!\n");
        return false;
    }
    pilha->nums = temp;

    pilha->nums[pilha->topo] = num;
    (pilha->topo)++;

    return true;
}

bool pop(Pilha *pilha, int *i)
{
    if (empty(pilha))
    {
        return false;
    }
    (pilha->topo)--;

    *i = pilha->nums[pilha->topo];

    if (pilha->topo == 0)
    {
        free(pilha->nums);
        pilha->nums = NULL;
    }
    else
    {
        int *temp = realloc(pilha->nums, --(pilha->limite) * sizeof(int));
        if (temp == NULL)
        {
            printf("Erro de alocacao!!!\n");
            return false;
        }
        pilha->nums = temp;
    }
    return true;
}

void list(Pilha *pilha)
{
    if (empty(pilha))
    {
        printf("A pilha esta vazia\n");
        return;
    }
    printf("\n###### Listando ######\n");
    for (int i = pilha->topo - 1; i >= 0; i--)
    {
        printf("Elemento %d: %d\n", i, pilha->nums[i]);
    }
}