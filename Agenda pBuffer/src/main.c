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
void adicionar(void **pBufferParametro);
void remover(void **pBufferParametro);
void buscar(void *pBuffer);
void listar(void *pBuffer);

// Busca próxima pessoa
void proximaPessoa(char **pPessoaAtual);

int main()
{
    void *pBuffer;
    iniciaBuffer(&pBuffer);

    while (1)
    {
        menu(pBuffer);
        switch (*MENU(pBuffer))
        {
        case 1:
            adicionar(&pBuffer);
            break;

        case 2:
            remover(&pBuffer);
            break;

        case 3:
            buscar(pBuffer);
            break;

        case 4:
            listar(pBuffer);
            break;

        case 5:
            printf("----------- Saindo... -----------\n");
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

void adicionar(void **pBufferParametro)
{
    void *pBuffer = *pBufferParametro;
    void *bufferAux = NULL;

    printf("----------- Adicionar -----------\n");
    printf("Insira o nome: ");
    scanf(" %49[^\n]", TEMP_NOME(pBuffer));
    printf("Insira o email: ");
    scanf(" %49[^\n]", TEMP_EMAIL(pBuffer));
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

void remover(void **pBufferParametro)
{
    void *pBuffer = *pBufferParametro;
    void *bufferAux = NULL;

    if (*QTD_PESSOAS(pBuffer) == 0)
    {
        printf("A agenda está vazia\n");
        return;
    }

    printf("----------- Remover -----------\n");
    printf("Insira o nome da pessoa: ");
    scanf(" %49[^\n]", TEMP_NOME(pBuffer));

    char *pLeitura = (char *)pBuffer + INICIO_AREA_DADOS; // Ponteiro para percorrer a agenda
    char *pRemover = NULL;                                // Ponteiro para a pessoa removida
    char *pProx = NULL;                                   // Ponteiro para a próxima pessoa após a removida

    for (*CONTADOR(pBuffer) = 0; *CONTADOR(pBuffer) < *QTD_PESSOAS(pBuffer); (*CONTADOR(pBuffer))++)
    {
        if (pRemover != NULL && pProx == NULL)
        {
            pProx = pLeitura;
            break;
        }
        if (pRemover == NULL && strcmp(pLeitura, TEMP_NOME(pBuffer)) == 0)
        {
            pRemover = pLeitura;

            char *pNome = pLeitura;
            char *pEmail = pNome + strlen(pNome) + 1;

            *TAM_PESSOA(pBuffer) = (strlen(pNome) + 1) + (strlen(pEmail) + 1) + TAM_IDADE;
        }

        proximaPessoa(&pLeitura);
    }

    if (pRemover == NULL)
    {
        printf("ERRO: %s nao encontrada\n", TEMP_NOME(pBuffer));
        return;
    }

    if (pProx != NULL)
    {
        char *pFinal = (char *)pBuffer + *DADOS_USADOS(pBuffer);

        memmove(pRemover, pProx, pFinal - pProx);
    }

    *DADOS_USADOS(pBuffer) -= *TAM_PESSOA(pBuffer);
    (*QTD_PESSOAS(pBuffer))--;

    bufferAux = realloc(pBuffer, *DADOS_USADOS(pBuffer));

    if (bufferAux == NULL)
    {
        printf("Erro de realocação!!!\n");
        exit(1);
    }
    else
    {
        pBuffer = bufferAux;
    }

    printf("SUCESSO: %s removida da agenda\n", TEMP_NOME(pBuffer));
}

void buscar(void *pBuffer)
{
    if (*QTD_PESSOAS(pBuffer) == 0)
    {
        printf("A agenda está vazia\n");
        return;
    }

    printf("----------- Buscar -----------\n");
    printf("Insira o nome da pessoa a ser buscada: ");
    scanf(" %49[^\n]", TEMP_NOME(pBuffer));

    char *pLeitura = (char *)pBuffer + INICIO_AREA_DADOS;
    for (*CONTADOR(pBuffer) = 0; *CONTADOR(pBuffer) < *QTD_PESSOAS(pBuffer); (*CONTADOR(pBuffer))++)
    {
        if (strcmp(pLeitura, TEMP_NOME(pBuffer)) == 0)
        {
            char *pNome = pLeitura;
            char *pEmail = pNome + strlen(pNome) + 1;
            int *pIdade = (int *)(pEmail + strlen(pEmail) + 1);
            printf("Pessoa encontrada:\n");
            printf("Nome: %s\n", pNome);
            printf("Email: %s\n", pEmail);
            printf("Idade: %d\n\n", *pIdade);
            return;
        }
        proximaPessoa(&pLeitura);
    }

    printf("ERRO: %s nao encontrado", TEMP_NOME(pBuffer));
}

void listar(void *pBuffer)
{
    if (*QTD_PESSOAS(pBuffer) == 0)
    {
        printf("A agenda está vazia\n");
        return;
    }

    char *pLeitura = (char *)pBuffer + INICIO_AREA_DADOS;
    char *pNome = NULL;
    char *pEmail = NULL;
    int *pIdade = NULL;

    printf("----------- Listar -----------\n");
    for (*CONTADOR(pBuffer) = 0; *CONTADOR(pBuffer) < *QTD_PESSOAS(pBuffer); (*CONTADOR(pBuffer))++)
    {
        pNome = pLeitura;
        pEmail = pNome + strlen(pNome) + 1;
        pIdade = (int *)(pEmail + strlen(pEmail) + 1);

        printf("------ Pessoa %d ------\n", (*CONTADOR(pBuffer)) + 1);
        printf("Nome: %s\n", pNome);
        printf("Email: %s\n", pEmail);
        printf("Idade: %d\n\n", *pIdade);

        proximaPessoa(&pLeitura);
    }
}

void proximaPessoa(char **pPessoaAtual)
{
    char *pPessoa = *pPessoaAtual;

    pPessoa += strlen(pPessoa) + 1;
    pPessoa += strlen(pPessoa) + 1;
    pPessoa += TAM_IDADE;

    // NOTA: TESTAR SE ISSO É REALMENTE NECESSÁRIO
    *pPessoaAtual = pPessoa;
}