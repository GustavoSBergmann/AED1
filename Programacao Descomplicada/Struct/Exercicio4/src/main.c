#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QTD_ALUNOS 5

typedef struct
{
    char nome[100];
    int matricula;
    float nota1;
    float nota2;
    float nota3;
    float media;

} Aluno;

void inserir(Aluno a[]);
void maiorNotaP1(Aluno a[]);
void maiorMedia(Aluno a[]);
void menorMedia(Aluno a[]);
void aprovacao(Aluno a[]);

int main()
{
    Aluno alunos[QTD_ALUNOS];

    inserir(alunos);
    maiorNotaP1(alunos);
    maiorMedia(alunos);
    menorMedia(alunos);
    aprovacao(alunos);

    return 0;
}

void inserir(Aluno a[])
{
    for (int i = 0; i < QTD_ALUNOS; i++)
    {
        printf("Nome do aluno %d: ", i + 1);
        scanf(" %[^\n]s", a[i].nome);

        printf("Matricula do aluno %d: ", i + 1);
        scanf(" %d", &a[i].matricula);

        printf("Nota 1 aluno %d: ", i + 1);
        scanf(" %f", &a[i].nota1);

        printf("Nota 2 aluno %d: ", i + 1);
        scanf(" %f", &a[i].nota2);

        printf("Nota 3 aluno %d: ", i + 1);
        scanf(" %f", &a[i].nota3);

        a[i].media = (a[i].nota1 + a[i].nota2 + a[i].nota3) / 3;

        printf("\n");
    }
}

void maiorNotaP1(Aluno a[])
{
    int maior = 0;

    for (int i = 1; i < QTD_ALUNOS; i++)
    {
        if (a[maior].nota1 < a[i].nota1)
        {
            maior = i;
        }
    }

    printf("Aluno com maior nota na prova 1: %s \n", a[maior].nome);
}

void maiorMedia(Aluno a[])
{
    int maior = 0;

    for (int i = 1; i < QTD_ALUNOS; i++)
    {
        if (a[maior].media < a[i].media)
        {
            maior = i;
        }
    }

    printf("Aluno com maior media geral: %s \n", a[maior].nome);
}

void menorMedia(Aluno a[])
{
    int menor = 0;

    for (int i = 1; i < QTD_ALUNOS; i++)
    {
        if (a[menor].media > a[i].media)
        {
            menor = i;
        }
    }

    printf("Aluno com menor media geral: %s \n", a[menor].nome);
}

void aprovacao(Aluno a[])
{
    for (int i = 0; i < QTD_ALUNOS; i++)
    {
        if (a[i].media >= 6)
        {
            printf("Aluno Aprovado!\n");
        }
        else
        {
            printf("Aluno Reprovado!\n");
        }
    }
}