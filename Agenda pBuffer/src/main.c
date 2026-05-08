#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MENU (sizeof(int))
#define QTD_PESSOAS (MENU + sizeof(int))
#define CONTADOR (QTD_PESSOAS + sizeof(int))
#define DESLOCAMENTO (CONTADOR + sizeof(int))
#define INICIO_AGENDA (DESLOCAMENTO + sizeof(char))
#define TAM_NOME 100
#define TAM_EMAIL 100
#define TAM_PESSOA ((TAM_NOME * sizeof(char)) + sizeof(int) + (TAM_EMAIL * sizeof(char)))

void add(void **pBuffer, void **pAux);

int main()
{
    void *pBuffer = malloc(2 * sizeof(int));
    void *pAux = NULL;
    *(int *)(pBuffer + QTD_PESSOAS) = 0;
    *(int *)(pBuffer + DESLOCAMENTO) = 0;

    do
    {
        printf("*********** Selecione uma opcao do menu: ***********\n");
        printf("1 - Adicionar Pessoa (Nome, Idade, Email)\n");
        printf("2 - Remover Pessoa\n");
        printf("3 - Buscar pessoa\n");
        printf("4 - Listar todos\n");
        printf("5 - Sair\n");
        printf("Insira uma opcao do menu: ");
        scanf(" %d", (int *)(pBuffer + MENU));

        switch (*(int *)(pBuffer + MENU))
        {
        case 1:
            printf("Adicionar pessoa (Nome, Idade, Email)\n");
            add(&pBuffer, &pAux);
            /*
            for (int i = 0; i < *(int *)(pBuffer + QTD_PESSOAS); i++)
            {
                printf("Nome: %s\n", );
            }
            */
            printf("Nome: %s\n", (char *)(pBuffer + INICIO_AGENDA));
            break;

        case 2:
            printf("Remover pessoa\n");
            break;

        case 3:
            printf("Buscar pessoa\n");
            break;

        case 4:
            printf("Listar todos\n");
            break;

        case 5:
            printf("Sair\n");
            exit(0);
            break;

        default:
            break;
        }
    } while (*(int *)(pBuffer + CONTADOR) != 5);

    free(pBuffer);
    free(pAux);
    return 0;
}

void add(void **pBuffer, void **pAux)
{
    void *p = NULL;

    p = (char *)malloc(TAM_NOME * sizeof(char));
    printf("Insira o nome da pessoa: ");
    scanf(" %99s", (char *)p);
    *pAux = realloc(*pBuffer, sizeof(*pBuffer) + (sizeof(char) * strlen((char *)p)));

    // Verifica se a memória foi alocada
    if (*pAux == NULL)
    {
        printf("Erro ao alocar!!!\n");
        exit(1);
    }
    else
    {
        *pBuffer = *pAux;
        *(int *)(*pBuffer + DESLOCAMENTO) += strlen((char *)p);
        memcpy((char *)(*pBuffer + INICIO_AGENDA + *(int *)(*pBuffer + DESLOCAMENTO)),
               (char *)p,
               (sizeof(char) * strlen((char *)p)) + 1);
        free(p);
    }

    p = (int *)malloc(sizeof(int));
    printf("Insira a idade da pessoa: ");
    scanf(" %d", (int *)p);
    *pAux = realloc(*pBuffer, sizeof(*pBuffer) + sizeof(int));

    // Verifica se a memória foi alocada
    if (*pAux == NULL)
    {
        printf("Erro ao alocar!!!\n");
        exit(1);
    }
    else
    {
        *pBuffer = *pAux;
        *(int *)(*pBuffer + DESLOCAMENTO) += sizeof(int);
        memcpy((char *)(*pBuffer + INICIO_AGENDA + *(int *)(*pBuffer + DESLOCAMENTO)),
               (int *)p,
               sizeof(int));
        free(p);
    }

    p = (char *)malloc(TAM_EMAIL * sizeof(char));
    printf("Insira o email da pessoa: ");
    scanf(" %99s", (char *)p);
    *pAux = realloc(*pBuffer, sizeof(*pBuffer) + (sizeof(char) * strlen((char *)p)));

    // Verifica se a memória foi alocada
    if (*pAux == NULL)
    {
        printf("Erro ao alocar!!!\n");
        exit(1);
    }
    else
    {
        *pBuffer = *pAux;
        *(int *)(*pBuffer + DESLOCAMENTO) += strlen((char *)p);
        memcpy((char *)(*pBuffer + INICIO_AGENDA + *(int *)(*pBuffer + DESLOCAMENTO)),
               (char *)p,
               (sizeof(char) * strlen((char *)p)) + 1);
        free(p);
    }

    *(int *)(*pBuffer + QTD_PESSOAS) += 1;
}