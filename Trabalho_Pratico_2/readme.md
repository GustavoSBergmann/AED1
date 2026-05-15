# LeetCode 503 - Next Greater Element II
## Gustavo Schmitz Bergmann

> [!IMPORTANT]
> Código feito inteiramente em aula.

> [!NOTE]
> A única alteração no código feito em aula foram os comentários para melhor compreensão do mesmo.

### Descrição do Problema:
Dado um array circular de inteiros `nums` (ou seja, o próximo elemento de `nums[nums.length - 1]` é `nums[0]`), retorne o próximo número maior para cada elemento em `nums`.

O próximo número maior de um número `x` é o primeiro número maior que o seu próximo na ordem de travessia do array, o que significa que você poderia percorrer o array circularmente para encontrar o próximo número maior. Se ele não existir, retorne -1 para esse número.

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
![Teste do código no LeetCode](https://github.com/GustavoSBergmann/AED1/blob/master/Trabalho_Pratico_2/Submit_LeetCode.png)

### Explicação:
Tive bastante dificuldade em relação a como percorrer o vetor circularmente, visto que, diferentemente das listas encadeadas, os vetores não possuem um ponteiro `*next` para apontar para o próximo endereço. Após muitas tentativas e erros, consegui chegar ao cálculo do índice baseado no resto da divisão, concluindo que a expressão `int indice = i % numsSize` faria com que, quando `i` ultrapassasse numsSize, o índice voltasse a contar do zero, tornando o vetor circular. A partir disso, concluí também que seria necessário percorrer o vetor duas vezes para que fosse possível avaliar todos os elementos posteriores a um elemento específico.

Também tive algumas dificuldades em relação às condições necessárias para armazenar os valores em `*resp`, mas nada comparado à dificuldade de tornar o vetor circular.

Todos os casos do LeetCode foram testados com sucesso.