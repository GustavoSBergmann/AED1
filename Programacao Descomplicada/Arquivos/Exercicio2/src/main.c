#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char caminho[100];
    char ch;
    int qtdLinhas = 0, temConteudo = 0;

    printf("Insira o nome do arquivo que deseja contar as linhas: ");
    scanf("%s", caminho);

    if ((fp = fopen(caminho, "r")) == NULL)
    {
        printf("Nao foi possivel abrir o arquivo!!!");
        exit(1);
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        temConteudo = 1;

        if (ch == '\n')
        {
            qtdLinhas++;
        }
    }
    if (temConteudo)
    {
        qtdLinhas++;
    }

    fclose(fp);

    printf("Quantidade de linhas do arquivo: %d", qtdLinhas);

    return 0;
}
