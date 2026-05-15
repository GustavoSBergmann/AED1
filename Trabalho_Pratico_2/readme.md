# LeetCode 503 - Next Greater Element II
## Gustavo Schmitz Bergmann

> [!IMPORTANT]
> Código feito inteiramente em aula.

> [!NOTE]
> A única alteração no código feito em aula foram os comentários para melhor compreensão do mesmo.

### Descrição do Problema:
Dado um array circular de inteiros `nums` (ou seja, o próximo elemento de `nums[nums.length - 1]` é `nums[0]`), retorne o próximo número maior para cada elemento em `nums`.

O próximo número maior de um número `x` é o primeiro número maior que o seu próximo na ordem de travessia do array, o que significa que você poderia percorrer o array circularmente para encontrar o próximo número maior. Se ele não existir, retorne -1 para esse número.

![Demonstração de como a matriz deve ser percorrida](https://github.com/GustavoSBergmann/AED1/blob/master/Trabalho%20Pratico%201/Matriz.png)

### Código feito em aula:
```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int *nextGreaterElements(int *nums, int numsSize, int *returnSize)
{
    // Define o tamanho do vetor retornado
    (*returnSize) = numsSize;
    // Vetor retornado com as respostas
    int *resp = (int *)malloc(numsSize * sizeof(int));
    // Pilha com os índices dos elementos buscando um elemento maior
    int *pilha = (int *)malloc(numsSize * sizeof(int));

    // Pilha inicializada vazia
    int topo = -1;

    // Inicializa todas as respostas com -1
    // Deste modo, caso não seja encontrado um elemento maior ele permanece como está
    for (int i = 0; i < numsSize; i++)
    {
        resp[i] = -1;
    }

    // Percorre o vetor nums 2 vezes
    for (int i = 0; i < 2 * numsSize; i++)
    {
        // Garante que o indice atue circularmente
        int indice = i % numsSize;

        // Enquanto a pilha tiver elementos e o
        // elemento atual for maior que o elemento representado pelo topo da pilha
        while (topo != -1 && nums[indice] > nums[pilha[topo]])
        {
            // Guarda o próximo maior elemento na posição correspondente
            resp[pilha[topo]] = nums[indice];
            // Remove o topo da pilha
            topo--;
        }

        // Empilha apenas na primeira passagem
        if (i < numsSize)
        {
            topo++;
            pilha[topo] = indice;
        }
    }

    free(pilha);
    return resp;
}
```

### Submit no LeetCode:
![Teste do código no LeetCode](https://github.com/GustavoSBergmann/AED1/blob/master/Trabalho%20Pratico%201/Submit%20LeetCode.png)

### Explicação:
Tive bastante dificuldade com relação a como percorrer o vetor circularmente, visto que, diferente das listas encadeadas, os vetores não tem `*next` para apontar para o próximo endereço. Depois de muitas tentativas e erros consegui chegar no cálculo do índice baseado no resto da divisão, o qual conclui que seria `int indice = i % numsSize`, fazendo com que, quando `i` passasse de `numsSize`, o indice voltasse a contar do zero, tornando vetor circular.