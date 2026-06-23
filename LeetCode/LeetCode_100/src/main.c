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

bool isSameTree(struct TreeNode *p, struct TreeNode *q)
{
    if (p == NULL && q == NULL)
    {
        return true;
    }
    else if ((p == NULL && q != NULL) || (p != NULL && q == NULL) || (p->val != q->val))
    {
        return false;
    }

    bool esquerda = isSameTree(p->left, q->left);
    bool direita = isSameTree(p->right, q->right);

    return (esquerda && direita);
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
    struct TreeNode *root1 = newNode(1);
    struct TreeNode *root2 = newNode(1);

    root1->left = newNode(2);
    root1->right = newNode(3);

    root2->left = newNode(2);
    root2->right = newNode(3);

    printf("As arvores sao iguais: %s\n", isSameTree(root1, root2) ? "Verdadeiro" : "Falso");

    free(root1);
    free(root2);

    return 0;
}
