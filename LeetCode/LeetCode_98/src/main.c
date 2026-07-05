#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *newNode(int value)
{
    struct TreeNode *node = malloc(sizeof(struct TreeNode));

    node->val = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

bool isValidBST(struct TreeNode *root)
{
    if (root == NULL)
    {
        return true;
    }

    if ((root->left != NULL && root->val <= root->left->val) ||
        (root->right != NULL && root->val >= root->right->val))
    {
        return false;
    }

    bool esquerda = isValidBST(root->left);
    bool direita = isValidBST(root->right);

    return (esquerda && direita);
}

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

void printTree(struct TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("Valor: %d \n", root->val);

    printTree(root->left);
    printTree(root->right);
}

int main()
{
    struct TreeNode *root = newNode(5);

    root->left = newNode(1);
    root->right = newNode(4);

    root->right->left = newNode(3);
    root->right->right = newNode(6);

    bool valid = isValidBST(root);
    printf("Arvore considerada: %s\n", valid ? "Valida" : "INVALIDA");

    freeTree(root);

    return 0;
}
