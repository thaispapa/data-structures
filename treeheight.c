#include <stdio.h>
#include <stdlib.h>

// Finding the height of a binary tree

typedef struct Node Node;

struct Node {
    int value;
    Node* left, *right;
};


Node* init_tree(int data) {
    Node* root = (Node*) malloc (sizeof(Node));
    root->left = root->right = NULL;
    root->value = data;
    return root;
}

Node* create_node(int data) {
    Node* node = (Node*) malloc (sizeof(Node));
    node->value = data;
    node->left = node->right = NULL;
    return node;
}

void free_tree(Node* root) {
    Node* temp = root;
    if (!temp)
        return;
    free_tree(temp->left);
    free_tree(temp->right);
    if (!temp->left && !temp->right) {
        free(temp);
        return;
    }
}

int tree_height(Node* root) {
    if (!root)
        return 0;
    else {
        int left_height = tree_height(root->left);
        int right_height = tree_height(root->right);
        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
}

int main() {
    Node* root = init_tree(10);

    root->left = create_node(20);
    root->right = create_node(30);
    root->left->left = create_node(40);
    root->left->right = create_node(50);

    int height = tree_height(root);
    printf("The height of the binary tree is: %i\n", height);

    free_tree(root);
    return 0;
}
