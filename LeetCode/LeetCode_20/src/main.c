#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isValid(char *s)
{
    int size = strlen(s);
    char *pilha = (char *)malloc(size * sizeof(char));
    int topo = 0;

    for (int i = 0; i < size; i++)
    {
        if ((s[i] == '(') || (s[i] == '{') || (s[i] == '['))
        {
            pilha[topo] = s[i];
            topo++;
        }
        else if (topo > 0)
        {
            if (((pilha[topo - 1] == '(') && (s[i] == ')')) ||
                ((pilha[topo - 1] == '{') && (s[i] == '}')) ||
                ((pilha[topo - 1] == '[') && (s[i] == ']')))
            {
                topo--;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }

    free(pilha);
    return (topo == 0);
}

int main()
{
    bool valid;

    valid = isValid("(({[[[]{}()]]()}))");

    valid ? printf("\n****** VALIDO ******\n") : printf("\n______ INVALIDO ______\n");

    return 0;
}
