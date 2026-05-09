# Agenda pBuffer
## Gustavo Schmitz Bergmann - Turma M1

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

### Explicação:
No início do desenvolvimento, tive bastante dificuldade para compreender como realizar os acessos à memória dentro do `pBuffer`. Minha primeira abordagem foi definir MACROs com constantes para representar deslocamentos de memória, como no exemplo: `#define QTD_PESSOAS 1`.

Assim, era possível acessar determinada região do buffer utilizando: `(int *)pBuffer + QTD_PESSOAS`.

Com o tempo, percebi que a lógica utilizada era semelhante ao conceito de endereço base + deslocamento, estudado na disciplina de Arquitetura e Organização de Computadores. Entretanto, o modo como eu estava abordando isso deixava o código confuso, pouco legível e mais difícil de manter.

Posteriormente, descobri a utilização de MACROs no formato de função, como: `#define QTD_PESSOAS(pBuffer) ((int *)pBuffer + 1)`. 

Dessa forma, os acessos à memória passaram a ficar mais claros e organizados, permitindo utilizar expressões como: `*QTD_PESSOAS(pBuffer)`.

Isso facilitou significativamente o desenvolvimento do programa. A partir dessa organização, consegui definir corretamente as regiões do buffer destinadas:

- às variáveis de controle;
- aos buffers temporários;
- e ao armazenamento dos dados das pessoas cadastradas. 

Após estruturar melhor o gerenciamento de memória, o restante do desenvolvimento se tornou mais claro. Apesar dos diversos erros envolvendo ponteiros durante a implementação, consegui concluir o trabalho com sucesso.