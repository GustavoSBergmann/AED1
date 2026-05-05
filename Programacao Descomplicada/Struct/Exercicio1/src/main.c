#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int hora;
    int minutos;
    int segundos;
} Horario;

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct
{
    Data d;
    Horario h;
    char texto[100];
} Compromisso;

Compromisso *marcar(Data d, Horario h, char *texto);
void imprimir(Compromisso *c);

int main()
{
    Data data;
    Horario horario;
    char texto[100];
    Compromisso *c1;

    printf("Digite a data (dia mes ano): ");
    scanf(" %d/%d/%d", &data.dia, &data.mes, &data.ano);

    printf("Digite o horario (hora minuto segundo): ");
    scanf(" %d:%d:%d", &horario.hora, &horario.minutos, &horario.segundos);

    printf("Digite o compromisso: ");
    scanf(" %[^\n]s", texto);

    c1 = marcar(data, horario, texto);

    printf("\n--- Compromisso ---\n");
    imprimir(c1);

    free(c1);

    return 0;
}

Compromisso *marcar(Data d, Horario h, char *texto)
{
    Compromisso *c = (Compromisso *)malloc(sizeof(Compromisso));

    c->d = d;
    c->h = h;
    strcpy(c->texto, texto);

    return c;
}

void imprimir(Compromisso *c)
{
    printf("Compromisso: %s \n", c->texto);
    printf("Data: %02d/%02d/%04d \n", c->d.dia, c->d.mes, c->d.ano);
    printf("Horario: %02d:%02d:%02d \n", c->h.hora, c->h.minutos, c->h.segundos);
}