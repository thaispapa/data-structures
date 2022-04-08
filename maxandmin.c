#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// Finding the max and min in a binary tree

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data)
{
    struct Node* node
            = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

int findMax(struct Node* root)
{
    if (root == NULL)
        return INT_MIN;

    int res = root->data;
    int lres = findMax(root->left);
    int rres = findMax(root->right);
    if (lres > res)
        res = lres;
    if (rres > res)
        res = rres;
    return res;
}

int findMin(struct Node* root)
{
    if (root == NULL)
        return INT_MAX;

    int res = root->data;
    int lres = findMin(root->left);
    int rres = findMin(root->right);
    if (lres < res)
        res = lres;
    if (rres < res)
        res = rres;
    return res;
}

int main(void)
{
    struct Node* NewRoot = NULL;
    struct Node* root = newNode(2);
    root->left = newNode(7);
    root->right = newNode(5);
    root->left->right = newNode(6);
    root->left->right->left = newNode(1);
    root->left->right->right = newNode(11);
    root->right->right = newNode(9);
    root->right->right->left = newNode(4);

    printf("The max element is %i \n", findMax(root));
    printf("The min element is %i \n", findMin(root));

    return 0;
}