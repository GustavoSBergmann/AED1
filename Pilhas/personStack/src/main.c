#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
    char name[30];
    int age;
} Person;

typedef struct
{
    Person *persons;
    Person *top;
    Person *base;
    int limit;
} Stack;

void menu(int *m);
void reset(Stack *s);
bool empty(Stack *s);
bool push(Stack *s, Person *p);
bool pop(Stack *s, Person *p);
bool popByName(Stack *s, char *name, Person *p);
void list(Stack *s);
void clear(Stack *s);

int main()
{
    Stack pilha;
    int opcao;
    Person deleted;
    Person temp;

    reset(&pilha);

    while (true)
    {
        menu(&opcao);
        switch (opcao)
        {
        case 0:
            printf("\n ------ Insere ------\n");
            printf("Insira o nome: ");
            scanf(" %29[^\n]", temp.name);
            printf("Insira a idade: ");
            scanf(" %d", &temp.age);

            if (push(&pilha, &temp))
            {
                printf("A pessoa \"%s\" foi inserida\n", temp.name);
            }
            else
            {
                printf("A pessoa \"%s\" NAO foi inserida\n", temp.name);
            }
            break;

        case 1:
            printf("\n ------ Deleta do Topo ------\n");

            if (pop(&pilha, &deleted))
            {
                printf("A pessoa \"%s\" foi deletada\n", deleted.name);
            }
            else
            {
                printf("A pessoa \"%s\" NAO foi deletada\n", deleted.name);
            }
            break;

        case 2:
            printf("\n ------ Deleta por Nome ------\n");
            printf("Insira o nome: ");
            scanf(" %29[^\n]", temp.name);

            popByName(&pilha, temp.name, &deleted);
            break;

        case 3:
            printf("\n ------ Limpa ------\n");
            clear(&pilha);
            break;

        case 4:
            printf("\n ------ Lista ------\n");
            list(&pilha);
            break;

        case 5:
            printf("\n ------ Sair ------\n");
            clear(&pilha);
            return 0;
            break;

        default:
            break;
        }
    }
}

void menu(int *m)
{
    do
    {
        printf("\n------ Menu ------\n");
        printf("0 - Insere Pessoa\n");
        printf("1 - Deleta pessoa do topo\n");
        printf("2 - Deleta pessoa por nome\n");
        printf("3 - Limpa a pilha\n");
        printf("4 - Lista na tela as pessoas\n");
        printf("5 - Sair do programa\n");
        printf("Insira uma opcao do menu: ");
        scanf(" %d", m);
    } while (*m < 0 || *m > 5);
}

void reset(Stack *s)
{
    s->persons = NULL;
    s->top = NULL;
    s->base = NULL;
    s->limit = 0;
}

bool empty(Stack *s)
{
    return (s->limit == 0);
}

bool push(Stack *s, Person *p)
{
    // Cria uma pessoa temporária para o realloc
    Person *temp;

    // Incrementa o limite
    s->limit++;
    // Realoca espaço com o novo limite
    temp = realloc(s->persons, sizeof(Person) * s->limit);

    // Verifica se o realloc() foi bem sucedido
    if (temp == NULL)
    {
        printf("Erro de alocacao!!!\n");
        s->limit--;
        return false;
    }

    s->persons = temp;                  // Atribui o novo espaço para as pessoas
    s->persons[s->limit - 1] = *p;      // Adiciona a nova pessoa no topo
    s->top = &s->persons[s->limit - 1]; // Atualiza o endereço do topo
    s->base = s->persons;               // Atualiza o endereço da base

    return true;
}

bool pop(Stack *s, Person *p)
{
    if (empty(s))
    {
        printf("A pilha esta vazia\n");
        return false;
    }
    Person *person;

    *p = *s->top;
    s->limit--;

    if (s->limit == 0)
    {
        free(s->persons);
        reset(s);
        return true;
    }

    person = realloc(s->persons, sizeof(Person) * s->limit);

    if (person == NULL)
    {
        printf("Erro de alocacao!!!\n");
        s->limit++;
        return false;
    }

    s->persons = person;                // Atribui o novo espaço para as pessoas
    s->top = &s->persons[s->limit - 1]; // Atualiza o endereço do topo
    s->base = s->persons;               // Atualiza o endereço da base

    return true;
}

bool popByName(Stack *s, char *name, Person *p)
{
    Stack backup;
    Person temp;
    bool found = false;

    reset(&backup);

    while (!empty(s))
    {
        if (strcmp(s->top->name, name) == 0)
        {
            pop(s, p);
            found = true;
            break;
        }

        pop(s, &temp);
        push(&backup, &temp);
    }

    while (!empty(&backup))
    {
        pop(&backup, &temp);
        push(s, &temp);
    }

    if (found)
    {
        printf("A pessoa \"%s\" foi deletada\n", name);
        return true;
    }
    else
    {
        printf("A pessoa \"%s\" nao foi encontrada\n", name);
        return false;
    }
}

void list(Stack *s)
{
    if (empty(s))
    {
        printf("A pilha esta vazia\n");
        return;
    }

    for (int i = s->limit - 1; i >= 0; i--)
    {
        printf("Nome %d: %s\n", i, s->persons[i].name);
        printf("Idade %d: %d\n\n", i, s->persons[i].age);
    }
}

void clear(Stack *s)
{
    free(s->persons);
    reset(s);
}