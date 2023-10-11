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
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }
    
    return root;
}

int findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

int findMax(struct Node* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
}

int findHeight(struct Node* root) {
    if (root == NULL) {
        return -1;
    }
    
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to display the menu
void displayMenu() {
    printf("\nBinary Search Tree Menu:\n");
    printf("1. Insert a node\n");
    printf("2. Find minimum value\n");
    printf("3. Find maximum value\n");
    printf("4. Find height of the tree\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    struct Node* root = NULL;
    int choice, value, minVal, maxVal, height;
    
    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the number of nodes to insert: ");
                int n;
                scanf("%d", &n);
                printf("Enter the values of %d nodes:\n", n);
                for (int i = 0; i < n; i++) {
                    scanf("%d", &value);
                    root = insertNode(root, value);
                }
                break;
                
            case 2:
                if (root != NULL) {
                    minVal = findMin(root);
                    printf("Minimum value in the tree: %d\n", minVal);
                } else {
                    printf("Tree is empty.\n");
                }
                break;
                
            case 3:
                if (root != NULL) {
                    maxVal = findMax(root);
                    printf("Maximum value in the tree: %d\n", maxVal);
                } else {
                    printf("Tree is empty.\n");
                }
                break;
                
            case 4:
                height = findHeight(root);
                printf("Height of the tree: %d\n", height);
                break;
                
            case 5:
                printf("Exiting the program.\n");
                break;
                
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
