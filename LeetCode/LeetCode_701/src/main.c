#include <stdio.h>
#include <stdlib.h>

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

struct TreeNode *insertIntoBST(struct TreeNode *root, int val)
{
    if (root == NULL)
    {
        return newNode(val);
    }

    if (root->val > val)
    {
        root->left = insertIntoBST(root->left, val);
        return root;
    }
    if (root->val < val)
    {
        root->right = insertIntoBST(root->right, val);
        return root;
    }

    return root;
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
    struct TreeNode *root = newNode(4);

    root->left = newNode(2);
    root->right = newNode(7);

    root->left->left = newNode(1);
    root->left->right = newNode(3);

    struct TreeNode *newRoot = insertIntoBST(root, 5);
    printTree(newRoot);

    freeTree(root);

    return 0;
}
