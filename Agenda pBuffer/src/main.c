#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tamanhos para cada informação
#define TAM_NOME 50
#define TAM_EMAIL 50
#define TAM_IDADE sizeof(int)

// Espaços para as variáveis inteiras de controle
#define MENU(pBuffer) ((int *)pBuffer)
#define QTD_PESSOAS(pBuffer) ((int *)pBuffer + 1)
#define CONTADOR(pBuffer) ((int *)pBuffer + 2)
#define DADOS_USADOS(pBuffer) ((int *)pBuffer + 3)
#define TAM_PESSOA(pBuffer) ((int *)pBuffer + 4)

// Tamanho do espaço para as variáveis de controle
#define TAM_CONTROLE 5
#define AREA_CONTROLE (sizeof(int) * TAM_CONTROLE)

// Espaços para os buffers temporários (Nome, Email e Idade)
#define TEMP_INICIO(pBuffer) ((void *)((int *)pBuffer + TAM_CONTROLE))
#define TEMP_NOME(pBuffer) ((char *)TEMP_INICIO(pBuffer))
#define TEMP_EMAIL(pBuffer) (TEMP_NOME(pBuffer) + TAM_NOME)
#define TEMP_IDADE(pBuffer) ((int *)(TEMP_EMAIL(pBuffer) + TAM_EMAIL))

// Tamanho do espaço para as variáveis temporárias
#define TAM_AREA_TEMP (TAM_NOME + TAM_EMAIL + TAM_IDADE)

// Começo da área de dados
#define INICIO_AREA_DADOS (AREA_CONTROLE + TAM_AREA_TEMP)

void iniciaBuffer(void **pBufferParametro);
void menu(void *pBuffer);
void add(void **pBufferParametro);

int main()
{
    void *pBuffer;
    iniciaBuffer(&pBuffer);
    menu(pBuffer);

    while (1)
    {
        switch (*MENU(pBuffer))
        {
        case 1:
            printf("Adicionar pessoa (Nome, Idade, Email)\n");
            add(&pBuffer);
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
            free(pBuffer);
            return 0;
            break;

        default:
            break;
        }
    }
}

void iniciaBuffer(void **pBufferParametro)
{
    // Inicia a área de variáveis de controle e o buffer temporário com 0
    *pBufferParametro = calloc(1, INICIO_AREA_DADOS);

    // Verifica se o ponteiro foi alocado
    if (*pBufferParametro == NULL)
    {
        printf("Erro ao alocar!!!\n");
        exit(1);
    }

    // Local onde começa a área de dados
    *DADOS_USADOS(*pBufferParametro) = INICIO_AREA_DADOS;
}

void menu(void *pBuffer)
{
    do
    {
        printf("*********** Selecione uma opcao do menu: ***********\n");
        printf("1 - Adicionar Pessoa (Nome, Idade, Email)\n");
        printf("2 - Remover Pessoa\n");
        printf("3 - Buscar pessoa\n");
        printf("4 - Listar todos\n");
        printf("5 - Sair\n");
        printf("Insira uma opcao do menu: ");
        scanf(" %d", MENU(pBuffer));
    } while (*MENU(pBuffer) < 1 || *MENU(pBuffer) > 5);
}

void add(void **pBufferParametro)
{
    void *pBuffer = *pBufferParametro;
    void *bufferAux;

    printf("----------- Adicionar pessoa -----------\n");
    printf("Insira o nome: ");
    scanf(" %49[^\n]s", TEMP_NOME(pBuffer));
    printf("Insira o email: ");
    scanf(" %49[^\n]s", TEMP_EMAIL(pBuffer));
    printf("Insira a idade: ");
    scanf(" %d", TEMP_IDADE(pBuffer));

    // Cálculo do tamanho necessário para alocar essa nova pessoa:
    // Tamanho do nome + \0 + Tamanho do Email + \0 + Tamanho da Idade(int)
    *TAM_PESSOA(pBuffer) = ((strlen(TEMP_NOME(pBuffer)) + 1) + (strlen(TEMP_EMAIL(pBuffer)) + 1) + TAM_IDADE);

    bufferAux = realloc(pBuffer, (*DADOS_USADOS(pBuffer) + *TAM_PESSOA(pBuffer)));

    if (bufferAux == NULL)
    {
        printf("Erro de realocação!!!\n");
        exit(1);
    }
    else
    {
        pBuffer = bufferAux;
    }

    memcpy(((char *)pBuffer + *DADOS_USADOS(pBuffer)), TEMP_NOME(pBuffer), strlen(TEMP_NOME(pBuffer)) + 1);
    *DADOS_USADOS(pBuffer) += strlen(TEMP_NOME(pBuffer)) + 1;

    memcpy(((char *)pBuffer + *DADOS_USADOS(pBuffer)), TEMP_EMAIL(pBuffer), strlen(TEMP_EMAIL(pBuffer)) + 1);
    *DADOS_USADOS(pBuffer) += strlen(TEMP_EMAIL(pBuffer)) + 1;

    memcpy(((char *)pBuffer + *DADOS_USADOS(pBuffer)), TEMP_IDADE(pBuffer), TAM_IDADE);
    *DADOS_USADOS(pBuffer) += TAM_IDADE;

    (*QTD_PESSOAS(pBuffer))++;
}