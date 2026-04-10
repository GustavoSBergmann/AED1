#include <stdio.h>
#include <string.h>

int main()
{
    char menu, c1, c2;
    char s1[20], s2[20];
    int qtd, pos, tam;

    while (1)
    {
        printf("(a) Ler uma string S1 (tamanho maximo 20 caracteres)\n");
        printf("(b) Imprimir o tamanho da string S1\n");
        printf("(c) Comparar a string S1 com uma nova string S2 fornecida pelo usuario e imprimir o resultado da comparacao\n");
        printf("(d) Concatenar a string S1 com uma nova string S2 e imprimir na tela o resultado da concatenacao\n");
        printf("(e) Imprimir a string S1 de forma reversa\n");
        printf("(f) Contar quantas vezes um dado caractere aparece na string S1. Esse caractere deve ser informado pelo usuario\n");
        printf("(g) Substituir a primeira ocorrencia do caractere C1 da string S1 pelo caractere C2. Os caracteres C1 e C2 serao lidos pelo usuario\n");
        printf("(h) Verificar se uma string S2 eh substring de S1. A string S2 deve ser informada pelo usuario\n");
        printf("(i) Retornar uma substring da string S1. Para isso o usuario deve informar a partir de qual posicao deve ser criada a substring e qual eh o tamanho da substring\n");
        printf("(j) Terminar programa\n");
        printf("Selecione a opcao do menu: ");
        scanf(" %c", &menu);

        switch (menu)
        {
        case 'a':
            printf("Insira uma string S1: ");
            scanf("%s", s1);
            printf("\n");
            break;

        case 'b':
            printf("Tamanho da string S1: %d\n\n", strlen(s1));
            break;

        case 'c':
            printf("Insira uma string S2: ");
            scanf("%s", s2);

            printf("O resultado da comparacao entre S1 e S2: %d\n\n", strcmp(s1, s2));
            break;

        case 'd':
            printf("Insira uma string S2: ");
            scanf("%s", s2);

            printf("O resultado da concatenacao entre S1 e S2: %s\n\n", strcat(s1, s2));
            break;

        case 'e':
            printf("String S1 reversa: ");
            for (int i = strlen(s1); i >= 0; i--)
            {
                printf("%c", s1[i]);
            }
            printf("\n\n");
            break;

        case 'f':
            qtd = 0;
            printf("Informe um carctere para ser buscado em S1: ");
            scanf(" %c", &c1);

            for (int i = 0; s1[i] != '\0'; i++)
            {
                if (s1[i] == c1)
                {
                    qtd++;
                }
            }
            printf("Foram encontradas %d ocorrencias do caractere %c\n\n", qtd, c1);
            break;

        case 'g':
            printf("Informe um carctere para ser substituido em S1: ");
            scanf(" %c", &c1);
            printf("Informe o caractere substituto: ");
            scanf(" %c", &c2);

            for (int i = 0; s1[i] != '\0'; i++)
            {
                if (s1[i] == c1)
                {
                    s1[i] = c2;
                    break;
                }
            }
            printf("String com caractere substituido: %s\n\n", s1);
            break;

        case 'h':
            printf("Insira uma string S2: ");
            scanf("%s", s2);

            if (strstr(s1, s2) != NULL)
            {
                printf("S2 eh substring de S1\n\n");
            }
            else
            {
                printf("S2 NAO eh substring de S1\n\n");
            }
            break;

        case 'i':
            printf("Posicao onde deve comecar a substring: ");
            scanf("%d", &pos);

            printf("Tamanho da substring: ");
            scanf("%d", &tam);

            printf("Substring: ");
            for (int i = 0; i < tam; i++)
            {
                printf("%c", s1[pos + i]);
            }
            printf("\n\n");
            break;

        case 'j':
            exit(0);
            break;

        default:
            printf("Opcao invalida, escolha novamente!");
            break;
        }
    }

    return 0;
}