#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *invertTree(struct TreeNode *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    struct TreeNode *node = root->left;
    root->left = root->right;
    root->right = node;
    invertTree(root->left);
    invertTree(root->right);

    return root;
}

struct TreeNode *newNode(int value)
{
    struct TreeNode *node = malloc(sizeof(struct TreeNode));

    node->val = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// Percurso em pré-ordem
void preOrder(struct TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d ", root->val);

    preOrder(root->left);
    preOrder(root->right);
}

// Libera a memória da árvore
void freeTree(struct TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    freeTree(root->left);
    freeTree(root->right);

    free(root);
}

int main()
{
    struct TreeNode *root = newNode(4);

    root->left = newNode(2);
    root->right = newNode(7);

    root->left->left = newNode(1);
    root->left->right = newNode(3);

    root->right->left = newNode(6);
    root->right->right = newNode(9);

    printf("Antes da inversao (Pre-Ordem):\n");
    preOrder(root);
    printf("\n");

    root = invertTree(root);

    printf("Depois da inversao (Pre-Ordem):\n");
    preOrder(root);
    printf("\n");

    freeTree(root);

    return 0;
}
