# LeetCode 498 - Diagonal Traverse
## Gustavo Schmitz Bergmann

> [!IMPORTANT]
> Código feito inteiramente em aula.

> [!NOTE]
> A única alteração no código feito em aula foram os comentários para melhor compreensão do mesmo, e no main, o qual não interfere no que foi testado no LeetCode.

### Descrição do Problema:
Dada uma matriz `m x n` `(mat)`, retorne um vetor contendo todos os elementos da matriz em ordem diagonal.

![Demonstração de como a matriz deve ser percorrida](https://github.com/GustavoSBergmann/AED1/blob/master/Trabalho%20Pratico%201/Matriz.png)

### Código feito em aula:
```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int *findDiagonalOrder(int **mat, int matSize, int *matColSize, int *returnSize)
{
    int m = matSize;
    int n = *matColSize;

    int *order = (int *)malloc(m * n * sizeof(int));

    int i = 0, j = 0, k = 0;

    // Percorre o vetor order preenchendo-o
    while (k < m * n)
    {
        // Sobe diagonalmente
        while (i >= 0 && j < n)
        {
            order[k++] = mat[i][j];
            i--;
            j++;
        }

        // Se j passou do limite a direita e i do limite superior
        if (j == n)
        {
            i += 2;
            j = n - 1;
        }
        // Se apenas i passou do limite superior
        else
        {
            i = 0;
        }

        // Se já passou do limite do vetor, então para de percorrer
        if (k >= m * n)
        {
            break;
        }

        // Desce diagonalmente
        while (i < m && j >= 0)
        {
            order[k++] = mat[i][j];
            i++;
            j--;
        }

        // Se i passou do limite inferior e j do limite a esquerda
        if (i == m)
        {
            j += 2;
            i = m - 1;
        }
        // Se apenas j passou do limite a esquerda
        else
        {
            j = 0;
        }
    }

    // Retorna o vetor e o seu tamanho
    *returnSize = m * n;
    return order;
}
```

### Submit no LeetCode:
![Teste do código no LeetCode](https://github.com/GustavoSBergmann/AED1/blob/master/Trabalho%20Pratico%201/Submit%20LeetCode.png)

### Explicação:
De início, tive dificuldades para entender como percorrer a matriz diagonalmente. Depois de algum tempo tentando identificar um padrão e testando algumas formas de percurso, cheguei à conclusão de que o padrão para as subidas diagonais era `i--` e `j++`, enquanto o padrão para as descidas diagonais era `i++` e `j--`.

A partir desse ponto, demorei bastante até conseguir encontrar uma forma de tratar os casos em que `i` e `j` ultrapassavam os limites da matriz. Após muitos desenhos mentais de matrizes e movimentações de índices, consegui chegar aos condicionais que tratam esses casos, localizados entre `while (i >= 0 && j < n)` e `while (i < m && j >= 0)`, além do trecho posterior a este último.

Todos os casos de teste funcionaram para o código.