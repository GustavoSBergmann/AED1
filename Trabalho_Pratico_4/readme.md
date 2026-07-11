# LeetCode 18 - 4Sum
## Gustavo Schmitz Bergmann

> [!IMPORTANT]
> Código finalizado em casa.

### Descrição do Problema:
Dado um array `nums` de `n` inteiros, retorne um array com todas as quadruplas ÚNICAS `[nums[a], nums[b], nums[c], nums[d]]` tais que:

- `0 <= a, b, c, d < n`

- `a, b, c e d sao distintos`

- `nums[a] + nums[b] + nums[c] + nums[d] == target`

Você pode retornar a resposta em qualquer ordem.

### Código feito em aula:
```
void insertionSort(int *array, int size)
{
	int i, j, temp;

	for (i = 1; i < size; i++)
	{
		j = i - 1;
		temp = array[i];
		while ((j >= 0) && (temp < array[j]))
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = temp;
	}
}

int **fourSum(int *nums, int numsSize, int target,
			  int *returnSize, int **returnColumnSizes)
{

	// IMPLEMENTAR ESSA FUNCAO
	int i, j, k, h;
	int linhas = 0;
	int **matriz = NULL;
	if (numsSize < 4)
	{
		return NULL;
	}

	insertionSort(nums, numsSize);

	i = 0;
	h = numsSize - 1;
	while ((i - h) > 2)
	{
		j = i + 1;
		k = h - 1;
		while (j < k)
		{
			int soma = nums[i] + nums[j] + nums[k] + nums[h];
			if (soma < target)
			{
				j++;
			}
			else if (soma > target)
			{
				k--;
			}
			else
			{
				int **temp = NULL;
				int *temporario = NULL;
				matriz = (int **)realloc(temp, (linhas + 1) * sizeof(int *));
				matriz[linhas] = (int *)malloc(4 * sizeof(int *));

				// Teste alocação
				if (temp == NULL)
				{
					exit(1);
				}
				else
				{
					matriz = temp;
				}
				temp == NULL;
				*returnColumnSizes = (int *)realloc(temporario, (linhas + 1) * sizeof(int));

				// Teste alocação
				if (temporario == NULL)
				{
					exit(1);
				}
				else
				{
					*returnColumnSizes = temporario;
				}

				matriz[linhas][0] = nums[i];
				matriz[linhas][1] = nums[j];
				matriz[linhas][2] = nums[k];
				matriz[linhas][3] = nums[h];

				*returnColumnSizes[linhas] = 4;

				j++;
				k--;
				linhas++;
			}
		}
		i++;
		h--;
	}

	*returnSize = linhas;
	return matriz;
}
```

### Código feito em casa:
```
int **fourSum(int *nums, int numsSize, int target,
              int *returnSize, int **returnColumnSizes)
{
    int i, j, k, h;

    *returnSize = 0;
    *returnColumnSizes = NULL;

    if (numsSize < 4)
    {
        return NULL;
    }

    // Alteração: uso de qsort
    qsort(nums, numsSize, sizeof(int), CompararInt);

    int **matriz = NULL;

    for (i = 0; i < numsSize - 3; i++)
    {
        // Alteração: evita duplicatas para i
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        for (j = i + 1; j < numsSize - 2; j++)
        {
            // Alteração: evita duplicatas para j
            if (j > i + 1 && nums[j] == nums[j - 1])
            {
                continue;
            }

            k = j + 1;
            h = numsSize - 1;

            while (k < h)
            {
                // Alteração: usa long long para evitar overflow
                long long soma = (long long)nums[i] + nums[j] + nums[k] + nums[h];

                if (soma < target)
                {
                    k++;
                }
                else if (soma > target)
                {
                    h--;
                }
                else
                {
                    // Alteração: realloc usando a matriz existente
                    int **temp = realloc(matriz, (*returnSize + 1) * sizeof(int *));

                    if (temp == NULL)
                        exit(1);

                    matriz = temp;

                    // Alteração: sizeof(int)
                    matriz[*returnSize] = malloc(4 * sizeof(int));

                    if (matriz[*returnSize] == NULL)
                        exit(1);

                    matriz[*returnSize][0] = nums[i];
                    matriz[*returnSize][1] = nums[j];
                    matriz[*returnSize][2] = nums[k];
                    matriz[*returnSize][3] = nums[h];

                    // Alteração: realloc correto do vetor de colunas
                    int *colunas = realloc(*returnColumnSizes, (*returnSize + 1) * sizeof(int));

                    if (colunas == NULL)
                        exit(1);

                    *returnColumnSizes = colunas;

                    // Alteração: acesso correto
                    (*returnColumnSizes)[*returnSize] = 4;

                    (*returnSize)++;

                    // Alteração: pula duplicatas
                    while (k < h && nums[k] == nums[k + 1])
                    {
                        k++;
                    }

                    while (k < h && nums[h] == nums[h - 1])
                    {
                        h--;
                    }

                    k++;
                    h--;
                }
            }
        }
    }

    return matriz;
}
```

### Explicação:
Tive bastante dificuldade em desenvolver a solução a partir do código apresentado em aula, tanto que não consegui fazê-lo funcionar corretamente. Tentei resolver de modo semelhante ao problema "3Sum", Porém cometi vários erros, tanto em relação às alocações quanto à inicialização e movimentação dos indices no vetor.

No código feito em aula utilizei InsertionSort para ordenar o vetor, mas no código feito em casa utilizei QuickSort, visto que é mais eficaz.

Ao final, apenas três casos de teste foram aprovados, mas isso ocorreu de forma acidental, sem que a lógica implementada resolvesse corretamente o problema de maneira geral.
