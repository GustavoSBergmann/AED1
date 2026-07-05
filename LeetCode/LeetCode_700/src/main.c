#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *searchBST(struct TreeNode *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->val == val)
    {
        return root;
    }
    if (root->val > val)
    {
        return searchBST(root->left, val);
    }

    return searchBST(root->right, val);
}

struct TreeNode *newNode(int value)
{
    struct TreeNode *node = malloc(sizeof(struct TreeNode));

    node->val = value;
    node->left = NULL;
    node->right = NULL;

    return node;
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

    struct TreeNode *subRoot = searchBST(root, 2);
    printTree(subRoot);

    freeTree(root);

    return 0;
}
