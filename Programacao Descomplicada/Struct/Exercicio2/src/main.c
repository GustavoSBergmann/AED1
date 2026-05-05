#include <stdio.h>

typedef struct
{
    char rua[50];
    int numero;
} Endereco;

typedef struct
{
    char nome[100];
    int idade;
    Endereco end;
} Pessoa;

Pessoa armazenar(char *n, int i, Endereco e);
void imprimir(Pessoa p);

int main()
{
    Pessoa p1;

    char nome[100];
    int idade;
    Endereco endereco;

    printf("Insira o nome: ");
    scanf(" %s", nome);

    printf("Insira a idade: ");
    scanf(" %d", &idade);

    printf("Insira a rua: ");
    scanf(" %s", endereco.rua);

    printf("Insira o numero: ");
    scanf(" %d", &endereco.numero);

    p1 = armazenar(nome, idade, endereco);

    imprimir(p1);

    return 0;
}

Pessoa armazenar(char *n, int i, Endereco e)
{
    Pessoa p;

    strcpy(p.nome, n);
    p.idade = i;
    p.end = e;

    return p;
}

void imprimir(Pessoa p)
{
    printf("\n Pessoa: \n");
    printf("Nome: %s \n", p.nome);
    printf("Idade: %d \n", p.idade);
    printf("Endereco: %s, %d \n", p.end.rua, p.end.numero);
}