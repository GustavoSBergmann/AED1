# LeetCode 860 - Lemonade Change
## Gustavo Schmitz Bergmann

### Descrição do Problema:
Em uma barraca de limonada, cada limonada custa `$5`. Os clientes estão em fila para comprar e pedem uma de cada vez (na ordem especificada pelas notas). Cada cliente comprará apenas uma limonada e pagará com uma nota de `$5`, `$10` ou `$20`. Você deve dar o troco correto a cada cliente para que o valor total da transação seja de `$5`.

Observe que você não tem troco inicialmente.

Dado um array de inteiros `bills`, onde `bills[i]` representa a nota paga pelo i-ésimo cliente, retorne `true` se você puder dar o troco correto a todos os clientes, ou `false` caso contrário.

### Código feito em aula:
```
bool lemonadeChange(int *bills, int billsSize)
{
    int i, j;
    for (j = 1; j < billsSize; j++)
    {
        i = j - 1;
        int temp = bills[j];

        if (temp == 10)
        {
            while (i >= 0 && bills[i] != 5)
            {
                i--;
            }
            if (bills[i + 1] == 5)
            {
                bills[i + 1] = 0;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}
```
![Teste do código de aula no LeetCode](https://github.com/GustavoSBergmann/AED1/blob/master/LeetCode/LeetCode_860/CodigoAula.png)

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