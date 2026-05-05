#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;

    char *caminho = "arquivo.txt";

    char ch;

    if ((fp = fopen(caminho, "w")) == NULL)
    {
        printf("Nao foi possivel criar/abrir o arquivo!!!");
        exit(1);
    }

    do
    {
        printf("Insira um caractere: ");
        scanf(" %c", &ch);
        if (ch != '0')
        {
            fputc(ch, fp);
        }
    } while (ch != '0');
    fclose(fp);

    if ((fp = fopen(caminho, "r")) == NULL)
    {
        printf("Nao foi possivel abrir o arquivo");
        exit(1);
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        printf("%c\n", ch);
    }
    fclose(fp);

    return 0;
}
