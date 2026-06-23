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

int height(struct TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int esquerda = height(root->left);
    int direita = height(root->right);

    if (esquerda > direita)
    {
        return esquerda + 1;
    }
    else
    {
        return direita + 1;
    }
}

bool isBalanced(struct TreeNode *root)
{
    if (root == NULL)
    {
        return true;
    }

    int esquerda = height(root->left);
    int direita = height(root->right);

    // O nó atual está desbalanceado
    if (abs(esquerda - direita) > 1)
    {
        return false;
    }

    // Verifica se as subárvores também são balanceadas
    return isBalanced(root->left) && isBalanced(root->right);
}

struct TreeNode *newNode(int value)
{
    struct TreeNode *node = malloc(sizeof(struct TreeNode));

    node->val = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int main()
{
    struct TreeNode *root = newNode(3);

    root->left = newNode(9);
    root->right = newNode(20);

    root->right->left = newNode(15);
    root->right->right = newNode(7);

    root->right->right->right = newNode(10);

    printf("Is Balanced: %s\n", isBalanced(root) ? "True" : "False");

    return 0;
}
