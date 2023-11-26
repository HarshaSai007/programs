#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

int findHeight(struct Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);
        return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
    }
}

int findMin(struct Node* root) {
    if (root->left == NULL) {
        return root->data;
    } else {
        return findMin(root->left);
    }
}

void swapChildren(struct Node* root) {
    if (root == NULL) {
        return;
    }
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    swapChildren(root->left);
    swapChildren(root->right);
}

struct Node* search(struct Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

int main() {
    struct Node* root = NULL;
    int values[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    int numValues = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < numValues; i++) {
        root = insert(root, values[i]);
    }

    // Insert new node
    root = insert(root, 5);

    // Find number of nodes in longest path
    int longestPath = findHeight(root);
    printf("Number of nodes in longest path: %d\n", longestPath);

    // Minimum data value found in the tree
    int minValue = findMin(root);
    printf("Minimum value in the tree: %d\n", minValue);

    // Change the tree so that the roles of the left and right pointers are swapped at every node
    swapChildren(root);

    // Search a value
    int searchValue = 6;
    struct Node* result = search(root, searchValue);
    if (result != NULL) {
        printf("%d is found in the tree\n", searchValue);
    } else {
        printf("%d is not found in the tree\n", searchValue);
    }

    return 0;
}
