#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int **levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes)
{
    if (root == NULL)
    {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    struct TreeNode *fila[2000];
    int inicio = 0, fim = 0;

    fila[fim++] = root;

    int **result = malloc(sizeof(int *) * 2000);
    *returnColumnSizes = malloc(sizeof(int) * 2000);

    int nivel = 0;

    while (inicio < fim)
    {
        int tamanho = fim - inicio;
        result[nivel] = malloc(sizeof(int) * tamanho);
        (*returnColumnSizes)[nivel] = tamanho;

        for (int i = 0; i < tamanho; i++)
        {
            struct TreeNode *atual = fila[inicio++];

            result[nivel][i] = atual->val;

            if (atual->left != NULL)
            {
                fila[fim++] = atual->left;
            }

            if (atual->right != NULL)
            {
                fila[fim++] = atual->right;
            }
        }
        nivel++;
    }
    *returnSize = nivel;

    return result;
}

// Cria um novo nó
struct TreeNode *newNode(int value)
{
    struct TreeNode *node = malloc(sizeof(struct TreeNode));

    node->val = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// Libera a árvore
void freeTree(struct TreeNode *root)
{
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);

    free(root);
}

int main()
{
    /*
             3
           /   \
          9     20
               /  \
              15   7
    */

    struct TreeNode *root = newNode(3);

    root->left = newNode(9);
    root->right = newNode(20);

    root->right->left = newNode(15);
    root->right->right = newNode(7);

    int returnSize;
    int *returnColumnSizes;

    int **ans = levelOrder(root, &returnSize, &returnColumnSizes);

    printf("Resultado:\n");

    for (int i = 0; i < returnSize; i++)
    {
        printf("Nivel %d: ", i);

        for (int j = 0; j < returnColumnSizes[i]; j++)
        {
            printf("%d ", ans[i][j]);
        }

        printf("\n");
    }

    // Libera a memória do resultado
    for (int i = 0; i < returnSize; i++)
    {
        free(ans[i]);
    }

    free(ans);
    free(returnColumnSizes);

    freeTree(root);

    return 0;
}