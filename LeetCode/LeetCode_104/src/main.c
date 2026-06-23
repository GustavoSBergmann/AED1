#include <stdio.h>
#include <stdlib.h>

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    if (leftDepth > rightDepth)
    {
        return leftDepth + 1;
    }
    else
    {
        return rightDepth + 1;
    }
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

    printf("Profundidade = %d\n", maxDepth(root));

    free(root);

    return 0;
}
