# Agenda pBuffer
## Gustavo Schmitz Bergmann - Turma M1

> [!IMPORTANT]
> Código feito inteiramente em aula.

> [!NOTE]
> A única alteração no código feito em aula foram os comentários para melhor compreensão do mesmo, e no main, o qual não interfere no que foi testado no LeetCode.

### Descrição do Trabalho:
Faça uma agenda com o seguinte menu:
1. Adicionar Pessoa (Nome, Idade, email)
2. Remover Pessoa
3. Buscar Pessoa
4. Listar todos
5. Sair
 
O desafio é não poder criar variáveis e sim um buffer de memória (void *pBuffer). Nisso vocês terão que fazer o trabalho que o Sistema Operacional faz para vocês ao organizar a memória.
 
Regras:
1. Nenhuma variável pode ser declarada em todo o programa, somente ponteiros. Todos os dados do programa devem ser guardados dentro do pBuffer.

    1.1. Nem mesmo como parâmetro de função. Só ponteiros que apontam para dentro do pBuffer. 
    - Exemplo: `int *ptr = (int *)pBuffer.`

    1.2. Exemplo do que não pode: `int c;`, `char a;`, `int v[10];`, `void Funcao(int parametro)`.

    1.3. Todas as strings que ficarem dentro do pBuffer deve ter somente o tamanho necessário, somente um buffer para receber o que o usuário digita no scanf pode ter um tamanho fixo.

2. Não pode usar struct em todo o programa.


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