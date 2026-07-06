# LeetCode 775 - Global and Local Inversions
## Gustavo Schmitz Bergmann

> [!IMPORTANT]
> Código finalizado em casa.

### Descrição do Problema:
É fornecido um array de inteiros `nums` de tamanho `n`, que representa uma permutação de todos os inteiros no intervalo `[0, n - 1]`.

O número de inversões globais é a quantidade de pares distintos `(i, j)` tais que:

- `0 <= i < j < n`
- `nums[i] > nums[j]`

O número de inversões locais é a quantidade de índices `i` tais que:

- `0 <= i < n - 1`
- `nums[i] > nums[i + 1]`

Retorne `true` se o número de inversões globais for igual ao número de inversões locais.

### Código feito em aula:
```
bool isIdealPermutation(int *nums, int numsSize)
{
	// Se o nums tiver apenas 1 elemento
	if (numsSize == 1)
	{
		return true;
	}

	long long global = 0;
	long long local = 0;
	int i, j;

	no_t *raiz = NULL;
	raiz = Inserir_r(raiz, nums[0]);

	// A cada mudança de raiz incrementa global
	for (int i = 1; i < numsSize; i++)
	{
		no_t *raizTemp = Inserir_r(raiz, nums[i]);
		if (raizTemp != raiz)
		{
			global++;
		}
		raiz = raizTemp;
	}

	local = 0;
	// Igual o da força bruta pois já está otimizado
	// Percorre apenas uma vez o vetor nums
	for (i = 0; i + 1 < numsSize; i++)
	{
		if (nums[i] > nums[i + 1])
		{
			local++;
		}
	}

	printf("Global: %d\n", (int)global);
	printf("Local: %d\n", (int)local);
	return global == local;
}
```

### Código feito em casa:
```
int contarMaiores(no_t *raiz, int valor)
{
	if (raiz == NULL)
	{
		return 0;
	}

	if (valor < raiz->valor)
	{
		// Raiz também é maior
		return 1 +
			   Tamanho(raiz->dir) +
			   contarMaiores(raiz->esq, valor);
	}

	return contarMaiores(raiz->dir, valor);
}

bool isIdealPermutation(int *nums, int numsSize)
{
	long long global = 0;
	long long local = 0;

	no_t *raiz = NULL;

	for (int i = 0; i < numsSize; i++)
	{
		global += contarMaiores(raiz, nums[i]);
		raiz = Inserir_r(raiz, nums[i]);
	}

	// Igual ao da função ForçaBruta, pois já está otimizado
	// Percorre apenas uma vez o vetor nums
	for (int i = 0; i + 1 < numsSize; i++)
	{
		if (nums[i] > nums[i + 1])
		{
			local++;
		}
	}

	return global == local;
}
```

### Explicação:
Tive bastante dificuldade em desenvolver a solução a partir do código apresentado em aula, tanto que não consegui fazê-lo funcionar corretamente. Percebi que a parte responsável por identificar as inversões locais já estava correta e, por isso, mantive essa implementação no meu código.

Entretanto, não consegui desenvolver uma solução adequada para identificar as inversões globais. Acredito que uma das principais razões para essa dificuldade foi a minha interpretação do enunciado. Inicialmente, não compreendi que o vetor fornecido representava uma permutação formada exatamente pelos números de `0` até `n - 1`, apenas em uma ordem diferente. Esse equívoco prejudicou meu raciocínio durante o desenvolvimento da solução.

Ao final, apenas quatro casos de teste foram aprovados, mas isso ocorreu de forma acidental, sem que a lógica implementada resolvesse corretamente o problema de maneira geral.
