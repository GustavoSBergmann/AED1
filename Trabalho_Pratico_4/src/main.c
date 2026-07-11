/*
===============================================================================

	LeetCode 18 - 4Sum ( Soma de Quatro )

	Dado um array nums de n inteiros, retorne um array com todas as
	quadruplas UNICAS [ nums[a], nums[b], nums[c], nums[d] ] tais que:

		0 <= a, b, c, d < n
		a, b, c e d sao distintos
		nums[a] + nums[b] + nums[c] + nums[d] == target

	Voce pode retornar a resposta em qualquer ordem.

	Exemplo 1:

		Entrada: nums = [1,0,-1,0,-2,2], target = 0
		Saida: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

	Exemplo 2:

		Entrada: nums = [2,2,2,2,2], target = 8
		Saida: [[2,2,2,2]]

	Restricoes:

		1 <= nums.length <= 200
		-10^9 <= nums[i] <= 10^9
		-10^9 <= target <= 10^9

===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
====================
CompararInt

	Comparador para qsort; forma segura contra overflow de ( x - y ).
====================
*/
static int CompararInt(const void *a, const void *b)
{
	int x;
	int y;

	x = *(const int *)a;
	y = *(const int *)b;
	return (x > y) - (x < y);
}

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

/*
====================
fourSum

	Assinatura exigida pelo LeetCode.
	returnSize        <- numero de quadruplas encontradas
	returnColumnSizes <- array com o tamanho de cada linha ( sempre 4 )
====================
*/
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

/*
====================
CompararQuadruplas

	Ordena as linhas do resultado lexicograficamente para permitir
	comparacao direta com o esperado, ja que o enunciado aceita a
	resposta em qualquer ordem.
====================
*/
static int CompararQuadruplas(const void *a, const void *b)
{
	const int *x;
	const int *y;
	int k;

	x = *(int *const *)a;
	y = *(int *const *)b;
	for (k = 0; k < 4; k++)
	{
		if (x[k] != y[k])
		{
			return (x[k] > y[k]) - (x[k] < y[k]);
		}
	}
	return 0;
}

/*
====================
ImprimirQuadruplas
====================
*/
static void ImprimirQuadruplas(int **res, int n)
{
	int k;

	printf("[");
	for (k = 0; k < n; k++)
	{
		printf("[%d,%d,%d,%d]%s", res[k][0], res[k][1], res[k][2], res[k][3],
			   k + 1 < n ? "," : "");
	}
	printf("]");
}

/*
====================
RodarTeste

	Compara o retorno de fourSum com o resultado esperado hard-coded.
	As quadruplas esperadas devem estar em ordem lexicografica.
====================
*/
static int RodarTeste(int num, const int *entrada, int n, int target,
					  const int esperado[][4], int esperadoQtd)
{
	int **res;
	int *nums;
	int *colSizes;
	int qtd;
	int ok;
	int k;
	int c;

	nums = malloc(sizeof(int) * (n > 0 ? n : 1));
	memcpy(nums, entrada, sizeof(int) * n);

	qtd = 0;
	colSizes = NULL;
	res = fourSum(nums, n, target, &qtd, &colSizes);

	ok = (qtd == esperadoQtd);
	if (ok && qtd > 0)
	{
		qsort(res, qtd, sizeof(int *), CompararQuadruplas);
		for (k = 0; k < qtd && ok; k++)
		{
			for (c = 0; c < 4; c++)
			{
				if (res[k][c] != esperado[k][c])
				{
					ok = 0;
					break;
				}
			}
		}
	}

	printf("Teste %2d: target = %d, nums = [", num, target);
	for (k = 0; k < n; k++)
	{
		printf("%d%s", entrada[k], k + 1 < n ? "," : "");
	}
	printf("]\n  obtido = ");
	ImprimirQuadruplas(res, qtd);
	printf("  ->  %s\n\n", ok ? "OK" : "FALHOU");

	for (k = 0; k < qtd; k++)
	{
		free(res[k]);
	}
	free(res);
	free(colSizes);
	free(nums);
	return ok;
}

/*
====================
main
====================
*/
int main(void)
{
	int passou;

	/* Teste 1: exemplo 1 do enunciado */
	int t1[] = {1, 0, -1, 0, -2, 2};
	int e1[][4] = {{-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}};

	/* Teste 2: exemplo 2 do enunciado - duplicatas extremas */
	int t2[] = {2, 2, 2, 2, 2};
	int e2[][4] = {{2, 2, 2, 2}};

	/* Teste 3: menos de 4 elementos - resposta vazia */
	int t3[] = {1, 2, 3};

	/* Teste 4: overflow - 4 * 10^9 com int estoura para -294967296;   */
	/* uma solucao sem long long ENCONTRARIA esta quadrupla e falharia */
	int t4[] = {1000000000, 1000000000, 1000000000, 1000000000};

	/* Teste 5: negativos e simetrias - 8 quadruplas */
	int t5[] = {-3, -2, -1, 0, 0, 1, 2, 3};
	int e5[][4] = {{-3, -2, 2, 3}, {-3, -1, 1, 3}, {-3, 0, 0, 3}, {-3, 0, 1, 2}, {-2, -1, 0, 3}, {-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}};

	/* Teste 6: exatamente 4 elementos que somam o alvo */
	int t6[] = {1, 2, 3, 4};
	int e6[][4] = {{1, 2, 3, 4}};

	/* Teste 7: exatamente 4 elementos que NAO somam o alvo */
	int t7[] = {1, 2, 3, 4};

	/* Teste 8: todos iguais a zero - deve sair UMA quadrupla, nao varias */
	int t8[] = {0, 0, 0, 0, 0, 0};
	int e8[][4] = {{0, 0, 0, 0}};

	/* Teste 9: todos negativos com alvo negativo */
	int t9[] = {-5, -4, -3, -2, -1};
	int e9[][4] = {{-4, -3, -2, -1}};

	/* Teste 10: duplicatas espalhadas e desordenadas */
	int t10[] = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
	int e10[][4] = {{1, 1, 3, 4}, {1, 2, 2, 4}, {1, 2, 3, 3}};

	passou = 0;
	passou += RodarTeste(1, t1, 6, 0, e1, 3);
	passou += RodarTeste(2, t2, 5, 8, e2, 1);
	passou += RodarTeste(3, t3, 3, 6, NULL, 0);
	passou += RodarTeste(4, t4, 4, -294967296, NULL, 0);
	passou += RodarTeste(5, t5, 8, 0, e5, 8);
	passou += RodarTeste(6, t6, 4, 10, e6, 1);
	passou += RodarTeste(7, t7, 4, 11, NULL, 0);
	passou += RodarTeste(8, t8, 6, 0, e8, 1);
	passou += RodarTeste(9, t9, 5, -10, e9, 1);
	passou += RodarTeste(10, t10, 10, 9, e10, 3);

	printf("Resultado final: %d/10 testes passaram\n", passou);
	return passou == 10 ? 0 : 1;
}
