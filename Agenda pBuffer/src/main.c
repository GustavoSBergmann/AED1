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

// Protótipos das funções
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
    // Ponteiro para facilitar a manipulação da memória
    void *pBuffer = *pBufferParametro;
    // Buffer auxiliar para efetuar o realloc()
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

    // Realoca espaço no buffer somando os dados já usados com o tamanho da nova pessoa
    bufferAux = realloc(pBuffer, (*DADOS_USADOS(pBuffer) + *TAM_PESSOA(pBuffer)));

    // Verifica se foi alocado corretamente
    if (bufferAux == NULL)
    {
        printf("Erro de realocação!!!\n");
        exit(1);
    }
    else
    {
        // Atualiza o ponteiro original e o local
        *pBufferParametro = bufferAux;
        pBuffer = bufferAux;
    }

    // Copia do endereço do nome temporário para o endereço livre após os dados usados
    memcpy(((char *)pBuffer + *DADOS_USADOS(pBuffer)), TEMP_NOME(pBuffer), strlen(TEMP_NOME(pBuffer)) + 1);
    // Atualiza a quantidade de dados usados
    *DADOS_USADOS(pBuffer) += strlen(TEMP_NOME(pBuffer)) + 1;

    // Copia do endereço do email temporário para o endereço livre após os dados usados
    memcpy(((char *)pBuffer + *DADOS_USADOS(pBuffer)), TEMP_EMAIL(pBuffer), strlen(TEMP_EMAIL(pBuffer)) + 1);
    // Atualiza a quantidade de dados usados
    *DADOS_USADOS(pBuffer) += strlen(TEMP_EMAIL(pBuffer)) + 1;

    // Copia do endereço da idade temporária para o endereço livre após os dados usados
    memcpy(((char *)pBuffer + *DADOS_USADOS(pBuffer)), TEMP_IDADE(pBuffer), TAM_IDADE);
    // Atualiza a quantidade de dados usados
    *DADOS_USADOS(pBuffer) += TAM_IDADE;

    // Incrementa a quantidade de pessoas
    (*QTD_PESSOAS(pBuffer))++;
}

void remover(void **pBufferParametro)
{
    // Ponteiro para facilitar a manipulação da memória
    void *pBuffer = *pBufferParametro;
    // Buffer auxiliar para efetuar o realloc()
    void *bufferAux = NULL;

    // Verifica se a agenda está vazia
    if (*QTD_PESSOAS(pBuffer) == 0)
    {
        printf("A agenda está vazia\n");
        return;
    }

    printf("----------- Remover -----------\n");
    printf("Insira o nome da pessoa: ");
    scanf(" %49[^\n]", TEMP_NOME(pBuffer));

    // Move o "cursor" de leitura para o início da área de dados
    char *pLeitura = (char *)pBuffer + INICIO_AREA_DADOS; // Ponteiro para percorrer a agenda
    char *pRemover = NULL;                                // Ponteiro para a pessoa removida
    char *pProx = NULL;                                   // Ponteiro para a próxima pessoa após a removida

    // Lê uma pessoa de cada vez
    for (*CONTADOR(pBuffer) = 0; *CONTADOR(pBuffer) < *QTD_PESSOAS(pBuffer); (*CONTADOR(pBuffer))++)
    {
        // Se a pessoa a ser removida for encontrada
        if (pRemover != NULL && pProx == NULL)
        {
            // Aponta para a pessoa após a pessoa removida
            pProx = pLeitura;
            break;
        }
        // Se a pessoa a ser removida for encontrada
        if (pRemover == NULL && strcmp(pLeitura, TEMP_NOME(pBuffer)) == 0)
        {
            // Aponta para a pessoa a ser removida
            pRemover = pLeitura;

            // Ponteiros para o nome e email da pessoa a ser removida
            char *pNome = pLeitura;
            char *pEmail = pNome + strlen(pNome) + 1;

            // Calcula o tamanho da pessoa a ser removida
            *TAM_PESSOA(pBuffer) = (strlen(pNome) + 1) + (strlen(pEmail) + 1) + TAM_IDADE;
        }

        proximaPessoa(&pLeitura);
    }

    // Se a pessoa não for encontrada
    if (pRemover == NULL)
    {
        printf("ERRO: %s nao encontrada\n", TEMP_NOME(pBuffer));
        return;
    }

    // Se a pessoa removida NÃO for a última da agenda
    if (pProx != NULL)
    {
        // Ponteiro para o final dos dados usados
        char *pFinal = (char *)pBuffer + *DADOS_USADOS(pBuffer);

        // Move a memória da próxima pessoa até o final dos dados usados para o endereço da pessoa removida
        // É usado memmove pois há sobreposição de memória
        memmove(pRemover, pProx, pFinal - pProx);
    }

    // Decrementa dos dados usados o tamanho da pessoa removida
    *DADOS_USADOS(pBuffer) -= *TAM_PESSOA(pBuffer);
    // Decrementa a quantidade de pessoas
    (*QTD_PESSOAS(pBuffer))--;

    // Realoca espaço no buffer com a quantidade necessária, agora sem a pessoa removida
    bufferAux = realloc(pBuffer, *DADOS_USADOS(pBuffer));

    // Verifica se foi alocado corretamente
    if (bufferAux == NULL)
    {
        printf("Erro de realocação!!!\n");
        exit(1);
    }
    else
    {
        // Atualiza o ponteiro original e o local
        *pBufferParametro = bufferAux;
        pBuffer = bufferAux;
    }

    printf("SUCESSO: %s removido da agenda\n", TEMP_NOME(pBuffer));
}

void buscar(void *pBuffer)
{
    // Verifica se a agenda está vazia
    if (*QTD_PESSOAS(pBuffer) == 0)
    {
        printf("A agenda está vazia\n");
        return;
    }

    printf("----------- Buscar -----------\n");
    printf("Insira o nome da pessoa a ser buscada: ");
    scanf(" %49[^\n]", TEMP_NOME(pBuffer));

    // Move o "cursor" de leitura para o início da área de dados
    char *pLeitura = (char *)pBuffer + INICIO_AREA_DADOS;

    // Lê uma pessoa de cada vez
    for (*CONTADOR(pBuffer) = 0; *CONTADOR(pBuffer) < *QTD_PESSOAS(pBuffer); (*CONTADOR(pBuffer))++)
    {
        // Se o nome da pessoa buscada for igual ao da pessoa atual
        if (strcmp(pLeitura, TEMP_NOME(pBuffer)) == 0)
        {
            // Ponteiros para cada dado da pessoa
            char *pNome = pLeitura;
            char *pEmail = pNome + strlen(pNome) + 1;
            int *pIdade = (int *)(pEmail + strlen(pEmail) + 1);

            // Imprime os dados da pessoa buscada
            printf("Pessoa encontrada:\n");
            printf("Nome: %s\n", pNome);
            printf("Email: %s\n", pEmail);
            printf("Idade: %d\n\n", *pIdade);
            return;
        }
        proximaPessoa(&pLeitura);
    }

    // Caso a pessoa não seja encontrada na agenda
    printf("ERRO: %s nao encontrado", TEMP_NOME(pBuffer));
}

void listar(void *pBuffer)
{
    // Verifica se a agenda está vazia
    if (*QTD_PESSOAS(pBuffer) == 0)
    {
        printf("A agenda está vazia\n");
        return;
    }

    // Inicia os ponteiros de leitura e de dados das pessoas
    char *pLeitura = (char *)pBuffer + INICIO_AREA_DADOS;
    char *pNome = NULL;
    char *pEmail = NULL;
    int *pIdade = NULL;

    printf("----------- Listar -----------\n");
    // Lê uma pessoa de cada vez
    for (*CONTADOR(pBuffer) = 0; *CONTADOR(pBuffer) < *QTD_PESSOAS(pBuffer); (*CONTADOR(pBuffer))++)
    {
        // Para onde cada ponteiro deve apontar
        pNome = pLeitura;
        pEmail = pNome + strlen(pNome) + 1;
        pIdade = (int *)(pEmail + strlen(pEmail) + 1);

        // Imprime os dados da pessoa
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

    // Passa pelo nome (string + '\0')
    pPessoa += strlen(pPessoa) + 1;

    // Passa pelo Email (string + '\0')
    pPessoa += strlen(pPessoa) + 1;

    // Passa pela idade (int)
    pPessoa += TAM_IDADE;

    // Atualiza o ponteiro original
    *pPessoaAtual = pPessoa;
}