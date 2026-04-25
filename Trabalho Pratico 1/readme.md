# LeetCode 498 - Diagonal Traverse
## Gustavo Schmitz Bergmann

### Descrição do Problema:
Dada uma matriz `m x n` `(mat)`, retorne um vetor contendo todos os elementos da matriz em ordem diagonal.

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

### Submit no LeetCode
![Teste do código de aula no LeetCode](https://github.com/GustavoSBergmann/AED1/blob/master/Trabalho Pratico 1/Submit LeetCode.png)

Não funcionaram muitos casos no código feito em aula, pois ficou incompleto, visto que eu não estava conseguindo chegar em uma solução que resolvesse todos os casos.

Consegui desenvolver a solução para o troco de `$10`, onde eu percorria o vetor para trás para achar um `$5`, se achasse, substituia-o por `0`, senão retornava `false`. 

Quanto ao caso do troco de `$20`, não consegui desenvolver em razão da possibilidade de se usar `$10 + $5` ou `$5 + $5 + $5` para o troco. Logo, o código não tem solução para este caso.

### Código feito em casa:
```
bool lemonadeChange(int *bills, int billsSize)
{
    int five = 0, ten = 0;
    for (int cliente = 0; cliente < billsSize; cliente++)
    {
        if (bills[cliente] == 5)
        {
            five++;
        }
        if (bills[cliente] == 10)
        {
            if (five > 0)
            {
                ten++;
                five--;
            }
            else
            {
                return false;
            }
        }
        if (bills[cliente] == 20)
        {
            if (five > 0 && ten > 0)
            {
                ten--;
                five--;
            }
            else if (five > 2)
            {
                five -= 3;
            }
            else
            {
                return false;
            }
        }
    }
    if (five >= 0 && ten >= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
```
![Teste do código de casa no LeetCode](https://github.com/GustavoSBergmann/AED1/blob/master/LeetCode/LeetCode_860/CodigoCasa.png)

No código feito em casa percebi que não havia necessidade de percorrer o vetor para frente e depois comparar o valor atual com os anteriores. Apenas precisava armazenar a quantidade de `$5`'s e `$10`'s, já que `$20` não é usado para troco. Então organizei da seguinte maneira:

- Para cada `$5` a variável `five` é incrementada;

- Para cada `$10` a variável `ten` é incrementada e `five` é decrementada se houver alguma nota de `$5` em `bill`. Senão a função retorna `false`;

- Para cada `$20` as variáveis `five` e `ten` são decrementadas se existirem notas de `$10` e `$5` em `bill`, senão `five` é decrementada três vezes se houver três `$5` em `bill`. Senão a função retorna `false`.

Portanto, o código feito em aula funciona completamente para todos os casos.