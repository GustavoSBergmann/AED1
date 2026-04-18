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
